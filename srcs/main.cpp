#include "containers.hpp"
#include <iostream>

class Test
{
private :
	std::string i;
public :
	Test(std::string i = 0) : i(i) { std::cout << i << " created" << std::endl; }
	Test(const Test& test) : i(test.i) { }
	Test& operator= (const Test& test) { i = test.i; return (*this); }
	~Test() { std::cout << i << " removed" << std::endl; }
	friend std::ostream& operator<< (std::ostream& out, const Test& test);
};

std::ostream& operator<< (std::ostream& out, const Test& test)
{
	out << test.i;
	return (out);
}

int		main()
{
	std::cout << "\e[1;38;5;218m                          VECTOR TEST\e[0m" << std::endl;
	vectorTest();
	std::cout << "\e[1;38;5;214m                          LIST TEST\e[0m" << std::endl;
	listTest();
	std::cout << "\e[1;38;5;151m                          STACK TEST\e[0m" << std::endl;
	stackTest();
	std::cout << "\e[1;38;5;197m                          QUEUE TEST\e[0m" << std::endl;
	queueTest();
	std::cout << "\e[1;38;5;154m                          MAP TEST\e[0m" << std::endl;
	mapTest();
	std::cout << "\e[1;38;5;226m                          MULTIMAP TEST\e[0m" << std::endl;
	multimapTest();
	std::cout << "\e[1;38;5;208m                          SET TEST\e[0m" << std::endl;
	setTest();
	std::cout << "\e[1;38;5;105m                          MULTISET TEST\e[0m" << std::endl;
	multisetTest();
	std::cout << "\e[1;38;5;195m                          DEQUE TEST\e[0m" << std::endl;
	dequeTest();
	return (0);
}
