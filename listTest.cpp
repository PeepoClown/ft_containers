#include "List/List.hpp"
#include <list>
#include <iostream>

int main() {
	ft::list<int> l;
	l.insert(l.begin(), 1); l.insert(l.begin(), 4); l.insert(l.begin(), 2); l.insert(l.begin(), 3);

	for (ft::list<int>::iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << "\n";
	}
}