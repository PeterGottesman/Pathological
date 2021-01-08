#pragma once

#include <string>
#include <unordered_map>
#include <functional>

class ArgParse
{
private:
	int argc;
	char **argv;

	struct Argument
	{
		std::string long_arg;
		std::string help;

		bool requires_param;
		bool has_short_arg;
		char short_arg;

		// Data from cli input
		std::string value;
		bool present;

		Argument(const std::string &long_arg, const std::string &help,
				 bool requires_param,
				 char short_arg = 0)
			: long_arg(long_arg), help(help), requires_param(requires_param),
			  has_short_arg(short_arg != 0), short_arg(short_arg),
			  present(false) {}
	};

	// Map long arg string to argument
	std::unordered_map<std::string, Argument> args;

	// Map short arg to long string
	std::unordered_map<char, std::string> short_args;

public:
	ArgParse(int argc, char **argv) : argc(argc), argv(argv) {}

	template <class T>
	int interpret_arg(std::string long_arg, T &value,
					  std::string type_name, int (*f)(std::string, T &));

	int add_arg(const std::string &long_arg, const std::string &help,
				 bool requires_param,
				 char short_arg = 0);

	template <class T>
	int get_arg(std::string long_arg, T &value);

	template <class T>
	int get_arg(std::string long_arg, T &value, T default_value)
	{
		int err = get_arg(long_arg, value);
		if (err != 0)
			value = default_value;

		return err;
	}

	int parse(void);
};
