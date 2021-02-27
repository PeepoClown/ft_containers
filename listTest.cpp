#include "List/List.hpp"
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
	ft::list<int> l;
	l.insert(l.begin(), 1); l.insert(l.begin(), 4); l.insert(++l.begin(), 2); l.insert(l.begin(), 3);

	for (ft::list<int>::iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	l.erase(++l.begin()); l.pop_front();

	for (ft::list<int>::iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	l.assign(10, 5);

	for (ft::list<int>::iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	l.clear();
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		l.push_back(rand() % 100);

//	size_t i = 0;
//	for (ft::list<int>::iterator it = l.begin(); it != l.end(); it++) {
//		std::cout << std::setw(5) << *it << " ";
//		if ((i + 1) % 10 == 0)
//			std::cout << std::endl;
//		i++;
//	}
//	std::cout << std::endl;

	l.sort();

//	i = 0;
//	for (ft::list<int>::iterator it = l.begin(); it != l.end(); it++) {
//		std::cout << std::setw(5) << *it << " ";
//		if ((i + 1) % 10 == 0)
//			std::cout << std::endl;
//		i++;
//	}
//	std::cout << std::endl;
}