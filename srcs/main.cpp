#include "containers.hpp"
#include <iostream>

int		main()
{
	std::cout << "\e[1;38;5;218m                          VECTOR TEST\e[0m" << std::endl;
	// vectorTest();
	std::cout << "\e[1;38;5;214m                          LIST TEST\e[0m" << std::endl;
	listTest();
	std::cout << "\e[1;38;5;151m                          STACK TEST\e[0m" << std::endl;
	// stackTest(); ???
	std::cout << "\e[1;38;5;197m                          QUEUE TEST\e[0m" << std::endl;
	// queueTest() ???
	std::cout << "\e[1;38;5;154m                          MAP TEST\e[0m" << std::endl;
	// mapTest();
	std::cout << "\e[1;38;5;226m                          MULTIMAP TEST\e[0m" << std::endl;
	// multimapTest();
	std::cout << "\e[1;38;5;208m                          SET TEST\e[0m" << std::endl;
	// setTest();
	std::cout << "\e[1;38;5;105m                          MULTISET TEST\e[0m" << std::endl;
	// multisetTest();
	std::cout << "\e[1;38;5;195m                          DEQUE TEST\e[0m" << std::endl;
	// dequeTest(); ???
	return (0);
}
