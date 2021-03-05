#include "containers.hpp"
#include <iostream>

int		main()
{
	// ...
	std::cout << "\e[1;33m                          MAP TEST\e[0m" << std::endl;
	mapTest();
	std::cout << "\e[1;33m                          MULTIMAP TEST\e[0m" << std::endl;
	multimapTest();
	std::cout << "\e[1;33m                          SET TEST\e[0m" << std::endl;
	setTest();
	std::cout << "\e[1;33m                          MULTISET TEST\e[0m" << std::endl;
	multisetTest();
	// ...
	return (0);
}
