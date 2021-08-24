#include "util/argparse.h"

#include <cstdio>
#include <typeinfo>

int ArgParse::add_arg(const std::string &long_arg, const std::string &help,
					   bool requires_param, char short_arg)
{
	bool success = args.insert({
			long_arg, Argument{long_arg, help, requires_param, short_arg}
		}).second;

	if (short_arg != 0)
		success &= short_args.insert({short_arg, long_arg}).second;

	return success ? 0 : -1;
}

// Default get_arg for unsupported types
template <class T>
int ArgParse::get_arg(std::string long_arg, T &value)
{
	fprintf(stderr, "Argument type not supported: %s\n", typeid(value).name());
	fprintf(stderr, "You may want to run the above message through `c++filt -t`\n");

	return -1;
}

template <class T>
int ArgParse::interpret_arg(std::string long_arg, T &value,
							std::string type_name, int (*f)(std::string, T &))
{

	auto arg = args.find(long_arg);
	if (arg == args.end())
		return -1;

	if (arg->second.present == false)
		return -1;

	std::string literal_value = arg->second.value;

	int err = 0;
	try
	{
		err = f(literal_value, value);
	} catch (const std::exception &e) {
		fprintf(stderr, "Caught error interpreting argument %s as %s: %s\n",
			   long_arg.c_str(), type_name.c_str(), e.what());
		fprintf(stderr, "Value was: %s\n", literal_value.c_str());
		err = -1;
	}

	return err;
}

template<> int ArgParse::get_arg(std::string long_arg, bool &value)
{
	return interpret_arg<bool>(long_arg, value, "bool",
							  [](std::string literal, bool &value) -> int {
								  if (literal == "true")
									  value = true;
								  if (literal == "false")
									  value = false;
								  else
									  return -1;

								  return 0;
							  }
		);
}

template<> int ArgParse::get_arg(std::string long_arg, int &value)
{
	return interpret_arg<int>(long_arg, value, "int",
							  [](std::string literal, int &value) -> int {
								  value = std::stoi(literal);
								  return 0;
							  }
		);
}

template<> int ArgParse::get_arg(std::string long_arg, std::string &value)
{
	return interpret_arg<std::string>(long_arg, value, "string",
									  [](std::string literal, std::string &value) -> int {
										  value = literal;
										  return 0;
									  }
		);
}

int ArgParse::parse(void)
{
	// a valid argument may be one of:
	// "-<char>", "--<str>", "-<char>=value"--<str>=value"

	char *cur;
	int err = 0;
	int argv_idx = 1;

	while (argv_idx < argc)
	{
		cur = argv[argv_idx];
		if (cur == NULL || cur[0] != '-')
		{
			// Invalid argument
			err = -1;
			break;
		}

		std::string arg, val;
		bool has_param;

		if (cur[1] == '-')
		{
			// Parse long args
			std::string str = (&cur[2]);
			unsigned sep_idx = str.find('=');

			// Check that there is an equal sign and at least one character after it
			has_param = sep_idx < (str.length()-1);

			arg = str.substr(0, sep_idx);
			val = str.substr(sep_idx+1);
		}
		else
		{
			char short_arg = cur[1];
			auto long_entry = short_args.find(short_arg);
			if (!isalnum(short_arg) || long_entry == short_args.end())
			{
				fprintf(stderr, "Invalid or unknown short argument -%c\n", short_arg);
				err = -1;
				break;
			}

			arg = long_entry->second;

			if (cur[2] == '=' && cur[3] != 0)
			{
				val = std::string(&cur[3]);
				has_param = true;
			}
			else
				has_param = false;
		}

		auto entry = args.find(arg);
		if (entry == args.end())
		{
			// Unknown argument
			err = -1;
			break;
		}

		Argument &a = entry->second;
		if (a.requires_param && !has_param)
		{
			// Required parameter missing
			if (a.has_short_arg)
				fprintf(stderr, "Argument --%s (-%c) missing required parameter\n",
						a.long_arg.c_str(), a.short_arg);
			else
				fprintf(stderr, "Argument --%s missing required parameter\n",
						a.long_arg.c_str());
			err = -1;
			break;
		}

		if (has_param)
		{
			a.value = val;
		}

		a.present = true;

		argv_idx++;
	}

	return err;
}
