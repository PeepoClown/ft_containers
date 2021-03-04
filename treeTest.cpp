#include "Map/Map.hpp"
#include <map>
#include <iostream>

int 	main()
{
	ft::map<int, std::string> m;

	m[0] = "0";
	m[2] = "2";
	m[1] = "1";
	m[3] = "3";
	m[2] = "555";
	m[5] = "5";

	std::pair<ft::map<int, std::string>::iterator, bool> t1 = m.insert(std::pair<int, std::string>(25, "zxc"));
	std::pair<ft::map<int, std::string>::iterator, bool> t2 = m.insert(std::pair<int, std::string>(5, "zxc"));

	std::cout << "fst: " << t1.second << " scd: " << t2.second << std::endl;

	std::cout << m.erase(3) << std::endl;

	std::cout << "find 5 : " << m.find(5)->first << " " << m.find(5)->second << std::endl;
	std::cout << "find 3 : " << m.find(3)->first << " " << m.find(3)->second << std::endl;

	for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	std::cout << m.size() << " " << m.empty() << " " << m.max_size() << std::endl;

	std::map<int, std::string> m1;

	std::cout << m1.size() << " " << m1.empty() << " " << m1.max_size() << std::endl;

	const ft::map<int, std::string> m2(m);

	std::cout << "find 5 : " << m2.find(5)->first << " " << m2.find(5)->second << std::endl;
	std::cout << "find 3 : " << m2.find(3)->first << " " << m2.find(3)->second << std::endl;

	std::cout << m2.count(11);

}
