#pragma once

#include <chrono>

class Timer
{
	std::chrono::high_resolution_clock::time_point begin, end;

public:
	void start(void)
	{
		end = begin = std::chrono::high_resolution_clock::now();
	}

	void stop(void)
	{
		end = std::chrono::high_resolution_clock::now();
	}

	float get_ms(void)
	{
		return std::chrono::duration<float, std::milli>(end-begin).count();
	}

	float get_cnt_per_ms(int count)
	{
		return count/std::chrono::duration<float, std::milli>(end-begin).count();
	}
};
