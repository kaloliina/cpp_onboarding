#include <iostream>
#include <stack>
/*Stack container follows LIFO (last in first out) order of insertion and deletion.
It means that most recently inserted element is removed first and the first inserted element will
be removed last. This is done by inserting and deleting elements at only one end of the stack
which is generally called the top of the stack.
stack<T> stdL (T being data type of elements in the stack)
Push for inserting elements, pop for deleting, empty, size

This stack can contain any data types so that's why we use templates!

Stack is not a container in itself, it is a container adapter.
This means they "wrap another container" but don't expose iteration.
So under the hood there is a container that has an iterator (deque) that we will access:
We will also access the underlying container "c" in the stack.

Using refers to give this nickname "iterator", typename states that this container
is a type. std::stack<T>::container_type::iterator is the iterator that is
hiding behind the stack container.
Note! The nickname/or the alias needs to match the one we are calling on main!
So this type iterator then points to the iterator of the internal container
and the alias is now visible outside of class...
*/

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	using iterator = typename std::stack<T>::container_type::iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};
