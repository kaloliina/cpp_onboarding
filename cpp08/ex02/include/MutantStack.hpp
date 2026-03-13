#include <iostream>
#include <stack>
/*Stack container follows LIFO (last in first out) order of insertion and deletion.
It means that most recently inserted element is removed first and the first inserted element will
be removed last. This is done by inserting and deleting elements at only one end of the stack
which is generally called the top of the stack.
stack<T> stdL (T being data type of elements in the stack)
Push for inserting elements, pop for deleting, empty, size*/

/*this stack can contain any data types so thats why templates...*/
//if stack doesnt have T there, main doesnt recognize the stack's functions
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
/*Using refers to give this nickname, typename states that this container is a type.
std::stack<T>::container_type::iterator is the iterator that is hiding behind the stack container... 
C is the underlying container in stack...*/
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
