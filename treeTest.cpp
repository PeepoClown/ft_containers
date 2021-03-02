#include "Utils/RBTree.hpp"
#include <iostream>

typedef ft::Tree<int, std::less<int>, true> rbTree;

int 	main()
{
	rbTree tree;
	tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(1);
	tree.insert(36);
	tree.insert(2003);
	std::cout << "36 found: " << tree.count(36) << std::endl;
	tree.traversal();
	tree.erase(tree.find(5));
	std::cout << "iterating : ";
	for (rbTree::iterator it = tree.begin(); it != tree.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	tree.traversal();

	rbTree rbtree(tree);

	std::cout << "copy tree" << std::endl;
	rbtree.traversal();
}
