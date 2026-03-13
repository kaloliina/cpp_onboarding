#include "../include/MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	// comparing it with list
	// std::cout << std::endl;
	// std::list<int> mlist;

	// mlist.push_back(5);      // list: [5]
	// mlist.push_back(17);     // list: [5, 17]
	// std::cout << mlist.back() << std::endl;  // prints: 17 (top = back)
	// mlist.pop_back();        // list: [5]
	// std::cout << mlist.size() << std::endl;  // prints: 1
	// mlist.push_back(3);      // list: [5, 3]
	// mlist.push_back(5);      // list: [5, 3, 5]
	// mlist.push_back(737);    // list: [5, 3, 5, 737]
	// //[...]
	// mlist.push_back(0);      // list: [5, 3, 5, 737, 0]

	// std::list<int>::iterator itl = mlist.begin();
	// std::list<int>::iterator itel = mlist.end();
	// ++itl;  // skip first element (5)
	// --itl;  // back to first element
	// while (itl != itel)
	// {
	//     std::cout << *itl << std::endl;  // prints: 5, 3, 5, 737, 0
	//     ++itl;
	// }

	// std::list<int> sl(mlist);  // copy to std::list
	// return 0;
}
