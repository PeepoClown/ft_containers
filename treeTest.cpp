#include "Utils/RBTree.hpp"
#include <iostream>

typedef ft::Tree<int, std::less<int>, true> rbTree;

int 	main()
{
//	rbTree tree;
//	for (size_t i = 0; i < 10; i++)
//		tree.insert(i);
//
//	tree.insert(15);
//	tree.insert(20);
//	tree.insert(25);
//
////	std::cout << "iterating: ";
////	for (rbTree::reverse_iterator it = tree.rbegin(); it != tree.rend(); it++) {
////		std::cout << *it << " ";
////	}
////	std::cout << std::endl;
////
////	tree.traversal();
//
//	tree.print();

    rbTree mapa;

	for (int i = 0; i < 10; i++) {
		if (i % 3 == 0) {
			mapa.insert(i);
		}
		mapa.insert(i);
	}

//	mapa.print();
//
//	mapa.erase(mapa.find(0));
//	mapa.erase(mapa.find(1));
//	mapa.erase(mapa.find(2));
//	mapa.erase(mapa.find(3));
//	mapa.erase(mapa.find(4));
//
//	mapa.print();
//
//	mapa.erase(mapa.find(5));
//	mapa.erase(mapa.find(6));
//	mapa.erase(mapa.find(7));
//
//	mapa.print();
//
//	mapa.erase(mapa.find(8));
//
//	mapa.print();
//
//	mapa.erase(mapa.find(9));

	mapa.print();
}
