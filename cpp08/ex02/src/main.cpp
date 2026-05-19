#include "../include/MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "--------Regular Mutant Stack test--------" << std::endl;
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

	std::cout << std::endl;

	std::cout << "--------Comparing results with list test--------" << std::endl;
	std::cout << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);      // list: [5]
	mlist.push_back(17);     // list: [5, 17]
	std::cout << mlist.back() << std::endl;  // prints: 17 (top = back)
	mlist.pop_back();        // list: [5]
	std::cout << mlist.size() << std::endl;  // prints: 1
	mlist.push_back(3);      // list: [5, 3]
	mlist.push_back(5);      // list: [5, 3, 5]
	mlist.push_back(737);    // list: [5, 3, 5, 737]
	//[...]
	mlist.push_back(0);      // list: [5, 3, 5, 737, 0]

	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itel = mlist.end();
	++itl;  // skip first element (5)
	--itl;  // back to first element
	while (itl != itel)
	{
	    std::cout << *itl << std::endl;  // prints: 5, 3, 5, 737, 0
	    ++itl;
	}

	std::list<int> sl(mlist);  // copy to std::list

	std::cout << "--------Mutant stack with strings test--------" << std::endl;
	MutantStack<std::string> mstack1;
	mstack1.push("hello");
	std::cout << mstack1.top();
	mstack1.push(" from the other side");
	std::cout << mstack1.top() << std::endl;
	mstack1.pop();
	std::cout << mstack1.size() << std::endl;
	mstack1.push(" and hi");
	mstack1.push("ya");
	MutantStack<std::string>::iterator it1 = mstack1.begin();
	MutantStack<std::string>::iterator ite1 = mstack1.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
	std::cout << *it1;
	++it1;
	}
	std::cout << std::endl;
	return 0;
}
