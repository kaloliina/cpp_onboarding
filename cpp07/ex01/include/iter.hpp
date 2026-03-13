#pragma once
#include <iostream>

/*We can expect here any type of array but also const or non-const
Also the function may take it's argument by const reference or non-const reference.
Template for the function handles this as well as it works for both const and non-const
If we did not have a template for the function, the iter function would not be as
receptive and we would need to predefine the function's argument as const or non-const.

If we try to call a non-const function with an array that is const, it simply wont compile*/
template <typename T, typename F>
void	iter(T* arr, const size_t length, F function)
{
	if (arr == nullptr)
		return ;
	for (size_t i = 0; i < length; i++)
	{
		function(arr[i]);
	}
}
