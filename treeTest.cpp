#include "Utils/Tree.hpp"
#include <iostream>

int 	main()
{
	ft::Tree<int, std::less<int>, false> tree;
	tree.insert(1); // tree.insert(2);
//	tree.insert(3);tree.insert(4);tree.insert(5);
	tree.traversal();
}
