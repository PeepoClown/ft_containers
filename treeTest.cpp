#include "Utils/RBTree.hpp"
#include <iostream>

typedef ft::Tree<int, std::less<int>, true> rbTree;

int 	main()
{
	rbTree tree;
	for (size_t i = 0; i < 10; i++)
		tree.insert(i);

	tree.insert(15);
	tree.insert(20);
	tree.insert(25);

	std::cout << "iterating: ";
	for (rbTree::reverse_iterator it = tree.rbegin(); it != tree.rend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	tree.traversal();

	tree.print();

	tree.print();

	tree.erase(tree.find(0));
	tree.erase(tree.find(1));
	tree.erase(tree.find(2));
	tree.erase(tree.find(3));
	tree.erase(tree.find(4));

	tree.print();

	tree.erase(tree.find(5));
	tree.erase(tree.find(6));
	tree.erase(tree.find(7));

	tree.print();

	tree.erase(tree.find(8));

	tree.print();

	tree.erase(tree.find(9));

	tree.print();
}
