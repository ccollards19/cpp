#pragma once

template <typename T>
void swap (T &arg1, T &arg2)
{
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template <typename T>
T min(T arg1, T arg2)
{
	if (arg2 <= arg1)
		return (arg2);
	return (arg1);
}

template <typename T>
T max(T arg1, T arg2)
{
	if (arg2 >= arg1)
		return (arg2);
	return (arg1);
}
