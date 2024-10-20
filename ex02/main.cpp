#include "MutantStack.hpp"
#include <list>

int main( void ) {
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top:\t" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size:\t" << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::MutantIterator it = mstack.begin();
	MutantStack<int>::MutantIterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << mstack << std::endl;

	/*std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "top:\t" << mstack.front() << std::endl;
	mstack.pop_back();
	std::cout << "size:\t" << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);*/
}
