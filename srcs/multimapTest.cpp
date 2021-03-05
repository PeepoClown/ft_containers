#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include "../Multimap/Multimap.hpp"

void print_std_map(std::multimap<std::string, int>& map)
{
	std::cout << "[std] multimap: " << std::endl;
	for (std::multimap<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "[std] size: " << map.size() << std::endl;
	std::cout << std::endl;
}

void print_ft_map(ft::multimap<std::string, int>& map)
{
	std::cout << "[ft] multimap: " << std::endl;
	for (ft::multimap<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "[ft] size: " << map.size() << std::endl;
	std::cout << std::endl;
}

void	multimapTest()
{
	getchar();
	system("clear");

	{
		std::cout << "empty multimap test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		print_std_map(std_map);
		print_ft_map(ft_map);
		std::cout << "[std] empty: " << std_map.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_map.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "range constructor test" << std::endl;
		std::multimap<std::string, int> std_map_base;
		ft::multimap<std::string, int> ft_map_base;

		std_map_base.insert(std::pair<std::string, int>("(1)", 1));
		std_map_base.insert(std::pair<std::string, int>("(2)", 2));
		std_map_base.insert(std::pair<std::string, int>("(3)", 3));
		std_map_base.insert(std::pair<std::string, int>("(1)", 4));
		std_map_base.insert(std::pair<std::string, int>("(3)", 3));
		std_map_base.insert(std::pair<std::string, int>("(6)", 6));
		std_map_base.insert(std::pair<std::string, int>("(1)", 1));
		std_map_base.insert(std::pair<std::string, int>("(8)", 8));
		std_map_base.insert(std::pair<std::string, int>("(2)", 22));

		ft_map_base.insert(std::pair<std::string, int>("(1)", 1));
		ft_map_base.insert(std::pair<std::string, int>("(2)", 2));
		ft_map_base.insert(std::pair<std::string, int>("(3)", 3));
		ft_map_base.insert(std::pair<std::string, int>("(1)", 4));
		ft_map_base.insert(std::pair<std::string, int>("(3)", 3));
		ft_map_base.insert(std::pair<std::string, int>("(6)", 6));
		ft_map_base.insert(std::pair<std::string, int>("(1)", 1));
		ft_map_base.insert(std::pair<std::string, int>("(8)", 8));
		ft_map_base.insert(std::pair<std::string, int>("(2)", 22));

		std::multimap<std::string, int> std_map(std_map_base.begin(), std_map_base.end());
		ft::multimap<std::string, int> ft_map(ft_map_base.begin(), ft_map_base.end());
		print_std_map(std_map);
		print_ft_map(ft_map);
	}

	getchar();
	system("clear");

	{
		std::cout << "size, empty, max_size test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std::cout << "[std] multimap: size = " << std_map.size() << ", empty = " << std_map.empty() << std::endl;
		std::cout << "[ft] multimap: size = " << ft_map.size() << ", empty = " << ft_map.empty() << std::endl;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		print_std_map(std_map);
		print_ft_map(ft_map);
		std::cout << "[std] multimap: size = " << std_map.size() << ", empty = " << std_map.empty() << std::endl;
		std::cout << "[ft] multimap: size = " << ft_map.size() << ", empty = " << ft_map.empty() << std::endl;
		std::cout << "[std] max_size: " << std_map.max_size() << ", [ft] max_size: " << ft_map.max_size() << std::endl;

		std::multimap<int, int> _std_map;
		ft::multimap<int, int> _ft_map;

		std::cout << "with another type of multimap: [std] max_size: " << _std_map.max_size() << ", [ft] max_size: " << _ft_map.max_size() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "iterators test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));

		std::cout << "iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::multimap<std::string, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << "[ft]: " << std::endl;
		for (ft::multimap<std::string, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;

		std::cout << "reverse iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::multimap<std::string, int>::reverse_iterator it = std_map.rbegin(); it != std_map.rend(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << "[ft]: " << std::endl;
		for (ft::multimap<std::string, int>::reverse_iterator it = ft_map.rbegin(); it != ft_map.rend(); it++)
			std::cout << it->first << " => " << it->second << std::endl;

		std::multimap<std::string, int> std_map_const(std_map);
		ft::multimap<std::string, int> ft_map_const(ft_map);

		std::cout << "const iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::multimap<std::string, int>::const_iterator it = std_map_const.begin(); it != std_map_const.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << "[ft]: " << std::endl;
		for (ft::multimap<std::string, int>::const_iterator it = ft_map_const.begin(); it != ft_map_const.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;

		std::cout << "const reverse iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::multimap<std::string, int>::const_reverse_iterator it = std_map_const.rbegin(); it != std_map_const.rend(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << "[ft]: " << std::endl;
		for (ft::multimap<std::string, int>::const_reverse_iterator it = ft_map_const.rbegin(); it != ft_map_const.rend(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "insert test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("(1)", 1)); std_map.insert(std::pair<std::string, int>("(2)", 2));
		ft_map.insert(std::pair<std::string, int>("(1)", 1)); ft_map.insert(std::pair<std::string, int>("(2)", 2));
		std::multimap<std::string, int>::iterator std_it = std_map.insert(std::pair<std::string, int>("(3)", 3));
		ft::multimap<std::string, int>::iterator ft_it = ft_map.insert(std::pair<std::string, int>("(3)", 3));
		std::cout << "returned iterators values: " << std::endl;
		std::cout << "[std] it: " << std_it->first << " => " << std_it->second << std::endl;
		std::cout << "[ft] it: " << ft_it->first << " => " << ft_it->second << std::endl;
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "insert elem with key that already exist: " << std::endl;
		std_map.insert(std::pair<std::string, int>("(3)", 33));
		ft_map.insert(std::pair<std::string, int>("(3)", 33));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "insert with position: " << std::endl;
		std_map.insert(std_map.begin(), std::pair<std::string, int>("(11)", 11)); std_map.insert(std_map.begin(), std::pair<std::string, int>("(2)", 2));
		ft_map.insert(ft_map.begin(), std::pair<std::string, int>("(11)", 11)); ft_map.insert(ft_map.begin(), std::pair<std::string, int>("(2)", 2));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "range insert: " << std::endl;
		std::cout << "in empty multimap: " << std::endl;
		std::multimap<std::string, int> _std_map;
		ft::multimap<std::string, int> _ft_map;

		_std_map.insert(std_map.begin(), --(--std_map.end()));
		_ft_map.insert(ft_map.begin(), --(--ft_map.end()));
		print_std_map(_std_map);
		print_ft_map(_ft_map);

		std::cout << "in filled multimap: " << std::endl;
		_std_map.insert(std_map.begin(), std_map.end());
		_ft_map.insert(ft_map.begin(), ft_map.end());
		print_std_map(_std_map);
		print_ft_map(_ft_map);
	}

	getchar();
	system("clear");

	{
		std::cout << "erase test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));
		std_map.insert(std::pair<std::string, int>("zzz", 7));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		ft_map.insert(std::pair<std::string, int>("zzz", 7));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "erase by iterator: " << std::endl;
		std_map.erase(std_map.begin()); std_map.erase(++std_map.begin());
		ft_map.erase(ft_map.begin()); ft_map.erase(++ft_map.begin());
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "erase by key zzz: " << std::endl;
		size_t i1 = std_map.erase("zzz");
		size_t i2 = ft_map.erase("zzz");
		std::cout << "[std] delete items: " << i1 << ", [ft] delete items: " << i2 << std::endl;
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "erase by range: " << std::endl;
		std_map.erase(std_map.begin(), std_map.end());
		ft_map.erase(ft_map.begin(), ft_map.end());
		print_std_map(std_map);
		print_ft_map(ft_map);
	}

	getchar();
	system("clear");

	{
		std::cout << "clear test" <<std::endl;

		std::cout << "empty multimap: " << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;
		std_map.clear();
		ft_map.clear();
		std::cout << "after clear: " << std::endl;
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "filled multimap: " << std::endl;
		std::multimap<std::string, int> _std_map;
		ft::multimap<std::string, int> _ft_map;
		_std_map.insert(std::pair<std::string, int>("asd", 1));
		_std_map.insert(std::pair<std::string, int>("qwe", 2));
		_std_map.insert(std::pair<std::string, int>("zcx", 3));
		_std_map.insert(std::pair<std::string, int>("qqq", 4));
		_std_map.insert(std::pair<std::string, int>("aaa", 5));
		_std_map.insert(std::pair<std::string, int>("zzz", 6));

		_ft_map.insert(std::pair<std::string, int>("asd", 1));
		_ft_map.insert(std::pair<std::string, int>("qwe", 2));
		_ft_map.insert(std::pair<std::string, int>("zcx", 3));
		_ft_map.insert(std::pair<std::string, int>("qqq", 4));
		_ft_map.insert(std::pair<std::string, int>("aaa", 5));
		_ft_map.insert(std::pair<std::string, int>("zzz", 6));
		std::cout << "before clear: " << std::endl;
		print_std_map(_std_map);
		print_ft_map(_ft_map);
		_std_map.clear();
		_ft_map.clear();
		std::cout << "after clear: " << std::endl;
		print_std_map(_std_map);
		print_ft_map(_ft_map);
	}

	getchar();
	system("clear");

	{
		std::cout << "swap test" << std::endl;
		std::multimap<std::string, int> std_map1, std_map2;
		ft::multimap<std::string, int> ft_map1, ft_map2;

		std_map1.insert(std::pair<std::string, int>("(1)", 1));
		std_map1.insert(std::pair<std::string, int>("(2)", 2));
		std_map1.insert(std::pair<std::string, int>("(3)", 3));
		std_map2.insert(std::pair<std::string, int>("(11)", 11));
		std_map2.insert(std::pair<std::string, int>("(22)", 22));
		std_map2.insert(std::pair<std::string, int>("(33)", 33));

		ft_map1.insert(std::pair<std::string, int>("(1)", 1));
		ft_map1.insert(std::pair<std::string, int>("(2)", 2));
		ft_map1.insert(std::pair<std::string, int>("(3)", 3));
		ft_map2.insert(std::pair<std::string, int>("(11)", 11));
		ft_map2.insert(std::pair<std::string, int>("(22)", 22));
		ft_map2.insert(std::pair<std::string, int>("(33)", 33));

		std::cout << "before swap: " << std::endl;
		print_std_map(std_map1); print_std_map(std_map2);
		print_ft_map(ft_map1); print_ft_map(ft_map2);
		std_map1.swap(std_map2);
		ft_map1.swap(ft_map2);
		std::cout << "after swap: " << std::endl;
		print_std_map(std_map1); print_std_map(std_map2);
		print_ft_map(ft_map1); print_ft_map(ft_map2);
	}

	getchar();
	system("clear");

	{
		std::cout << "compare test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		std::multimap<std::string, int>::key_compare std_comp = std_map.key_comp();
		ft::multimap<std::string, int>::key_compare ft_comp = ft_map.key_comp();

		std::cout << "[std]: " << std::endl;
		std::multimap<std::string, int>::iterator it = std_map.begin();
		do {
			if (it == std_map.end())
				break ;
			std::cout << it->first << " => " << it->second << '\n';
		} while (std_comp((*it++).first, "zzzz"));

		std::cout << "[ft]: " << std::endl;
		ft::multimap<std::string, int>::iterator it1 = ft_map.begin();
		do {
			if (it1 == ft_map.end())
				break ;
			std::cout << it1->first << " => " << it1->second << '\n';
		} while (ft_comp((*it1++).first, "zzzz"));
	}

	getchar();
	system("clear");

	{
		std::cout << "find test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));
		std_map.insert(std::pair<std::string, int>("zzz", 7));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		ft_map.insert(std::pair<std::string, int>("zzz", 7));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "find existed elements: " << std::endl;
		std::cout << "find asd: " << "[std]: " << std_map.find("asd")->first << " => " << std_map.find("asd")->second << std::endl;
		std::cout << "find asd: " << "[ft]: " << ft_map.find("asd")->first << " => " << ft_map.find("asd")->second << std::endl;
		std::cout << "find qqq: " << "[std]: " << std_map.find("qqq")->first << " => " << std_map.find("qqq")->second << std::endl;
		std::cout << "find qqq: " << "[ft]: " << ft_map.find("qqq")->first << " => " << ft_map.find("qqq")->second << std::endl;
		std::cout << "find non existed element: " << std::endl;
		std::cout << "find asda: " << "[std]: " << std_map.find("asda")->second << std::endl;
		std::cout << "find asda: " << "[ft]: " << ft_map.find("asda")->second << std::endl;
		std::cout << "find element by key that not unique: " << std::endl;
		std::cout << "find zzz: " << "[std]: " << std_map.find("zzz")->first << " => " << std_map.find("zzz")->second << std::endl;
		std::cout << "find zzz: " << "[ft]: " << ft_map.find("zzz")->first << " => " << ft_map.find("zzz")->second << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "count test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));
		std_map.insert(std::pair<std::string, int>("zzz", 7));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		ft_map.insert(std::pair<std::string, int>("zzz", 7));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::cout << "count existed elements: " << std::endl;
		std::cout << "count asd: " << "[std]: " << std_map.count("asd") << std::endl;
		std::cout << "count asd: " << "[ft]: " << ft_map.count("asd") << std::endl;
		std::cout << "count zzz: " << "[std]: " << std_map.count("zzz") << std::endl;
		std::cout << "count zzz: " << "[ft]: " << ft_map.count("zzz") << std::endl;
		std::cout << "count non existed element: " << std::endl;
		std::cout << "count asda: " << "[std]: " << std_map.count("asda") << std::endl;
		std::cout << "count asda: " << "[ft]: " << ft_map.count("asda") << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "bounds test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));
		std_map.insert(std::pair<std::string, int>("zzz", 7));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		ft_map.insert(std::pair<std::string, int>("zzz", 7));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::multimap<std::string, int>::iterator std_it_low = std_map.lower_bound("asd");
		std::multimap<std::string, int>::iterator std_it_up = std_map.lower_bound("zcx");
		std::cout << "[std] bounds (asd, zcx): " << std::endl;
		for ( ; std_it_low != std_it_up; std_it_low++)
			std::cout << std_it_low->first << " => " << std_it_low->second << std::endl;

		ft::multimap<std::string, int>::iterator ft_it_low = ft_map.lower_bound("asd");
		ft::multimap<std::string, int>::iterator ft_it_up = ft_map.lower_bound("zcx");
		std::cout << "[ft] bounds (asd, zcx): " << std::endl;
		for ( ; ft_it_low != ft_it_up; ft_it_low++)
			std::cout << ft_it_low->first << " => " << ft_it_low->second << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "equal range test" << std::endl;
		std::multimap<std::string, int> std_map;
		ft::multimap<std::string, int> ft_map;

		std_map.insert(std::pair<std::string, int>("asd", 1));
		std_map.insert(std::pair<std::string, int>("qwe", 2));
		std_map.insert(std::pair<std::string, int>("zcx", 3));
		std_map.insert(std::pair<std::string, int>("qqq", 4));
		std_map.insert(std::pair<std::string, int>("aaa", 5));
		std_map.insert(std::pair<std::string, int>("zzz", 6));
		std_map.insert(std::pair<std::string, int>("zzz", 7));

		ft_map.insert(std::pair<std::string, int>("asd", 1));
		ft_map.insert(std::pair<std::string, int>("qwe", 2));
		ft_map.insert(std::pair<std::string, int>("zcx", 3));
		ft_map.insert(std::pair<std::string, int>("qqq", 4));
		ft_map.insert(std::pair<std::string, int>("aaa", 5));
		ft_map.insert(std::pair<std::string, int>("zzz", 6));
		ft_map.insert(std::pair<std::string, int>("zzz", 7));
		print_std_map(std_map);
		print_ft_map(ft_map);

		std::pair<std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator> std_range = std_map.equal_range("qwe");
		std::cout << "[std] range: (" << std_range.first->first << " => " << std_range.first->second << ", "
				  << std_range.second->first << " => " << std_range.second->second << ")" << std::endl;

		std::pair<ft::multimap<std::string, int>::iterator, ft::multimap<std::string, int>::iterator> ft_range = ft_map.equal_range("qwe");
		std::cout << "[ft] range: (" << ft_range.first->first << " => " << ft_range.first->second << ", "
				  << ft_range.second->first << " => " << ft_range.second->second << ")" << std::endl;

		std::pair<std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator> std_range1 = std_map.equal_range("asd");
		std::cout << "[std] range: (" << std_range1.first->first << " => " << std_range1.first->second << ", "
				  << std_range1.second->first << " => " << std_range1.second->second << ")" << std::endl;

		std::pair<ft::multimap<std::string, int>::iterator, ft::multimap<std::string, int>::iterator> ft_range1 = ft_map.equal_range("asd");
		std::cout << "[ft] range: (" << ft_range1.first->first << " => " << ft_range1.first->second << ", "
				  << ft_range1.second->first << " => " << ft_range1.second->second << ")" << std::endl;
	}

	getchar();
	system("clear");

	std::cout <<	"\n\n\n\
					⢸⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⡷⡄\n\
					⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⡇  ⠢⣀\n\
					⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀ ⠈⠑⢦⡀\n\
					⢸⠀⠀⠀⠀⢀⠖⠒⠒⠒⢤⠀⠀⠀⠀⠀ ⡇⠀⠀⠀⠀ ⠀⠙⢦⡀\n\
					⢸⠀⠀⣀⢤⣼⣀⡠⠤⠤⠼⠤⡄⠀⠀  ⡇⠀⠀⠀⠀⠀⠀ ⠀⠙⢄\n\
					⢸⠀⠀⠑⡤⠤⡒⠒⠒⡊⠙⡏⠀⢀⠀  ⡇⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠑⠢⡄\n\
					⢸⠀⠀⠀⠇⠀⣀⣀⣀⣀⢀⠧⠟⠁  ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⡇\n\
					⢸⠀⠀⠀⠸⣀⠀⠀⠈⢉⠟⠓⠀⠀⠀ ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⠀⠀⠈⢱⡖⠋⠁⠀⠀⠀⠀⠀ ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⠀⠀⣠⢺⠧⢄⣀⠀⠀⣀⣀⠀ ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢸\n\
					⢸⠀⠀⠀⣠⠃⢸⠀⠀⠈⠉⡽⠿⠯⡆⠀ ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⣰⠁⠀⢸⠀⠀⠀⠀⠉⠉⠉⠀⠀ ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸\n\
					⢸⠀⠀⠣⠀⠀⢸⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⠀⢸⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⠀⡌⠀⠈⡆⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⢠⠃⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\
					⢸⠀⠀⠀⠀⢸⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸\n\n\n";

	getchar();
	system("clear");

}
