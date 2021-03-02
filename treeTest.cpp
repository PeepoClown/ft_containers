#include "Utils/RBTree.hpp"
#include <iostream>

typedef ft::Tree<int, std::less<int>, true> rbTree;

int 	main()
{
	rbTree tree;
	for (size_t i = 0; i < 10; i++)
		tree.insert(i);
	std::cout << "36 found: " << tree.count(36) << std::endl;
	tree.traversal();
	tree.erase(tree.find(4));
	tree.erase(tree.find(5));
	std::cout << "iterating: ";
	for (rbTree::reverse_iterator it = tree.rbegin(); it != tree.rend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	tree.traversal();

//	rbTree rbtree;
//
//	rbtree = tree;
//
//	std::cout << "copy tree" << std::endl;
//	rbtree.traversal();
}
