#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T	*_arr;
		int	_size;

	public:
	Array()
	{
		_arr = nullptr;
		_size = 0;
	}
	Array(unsigned int n)
	{
		if (n > 0)
			_arr = new T[n];
		else
			_arr = nullptr;
		_size = n;
	}
	Array(const Array& copy)
	{
		if (copy._size > 0)
			_arr = new T[copy._size];
		else
			_arr = nullptr;
		_size = copy._size;
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = copy._arr[i];
		}
	}
	Array& operator=(const Array&src)
	{
		if (this != &src)
		{
			delete[] _arr;
			_size = src._size;
			if (_size > 0)
				_arr = new T[_size];
			else
				_arr = nullptr;
			for (int i = 0; i < _size; i++)
			{
				_arr[i] = src._arr[i];
			}
		}
		return *this;
	}
	~Array()
	{
		delete[] _arr;
	}
	T operator[](int index) const
	{
		if (index < 0 || index >= _size)
		{
			throw std::exception();
		}
		return(_arr[index]);
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= _size)
		{
			throw std::exception();
		}
		return(_arr[index]);
	}
	int size() const
	{
		return _size;
	}
};
