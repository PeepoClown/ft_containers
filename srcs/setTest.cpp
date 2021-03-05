#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
#include "../Set/Set.hpp"

void print_std_set(std::set<std::string>& set)
{
	std::cout << "[std] set: " << std::endl;
	size_t i = 0;
	for (std::set<std::string>::iterator it = set.begin(); it != set.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 3 == 0)
			std::cout << std::endl;
		i++;
	}
	if (i % 3 != 0)
		std::cout << std::endl;
	std::cout << "[std] size: " << set.size() << std::endl;
	std::cout << std::endl;
}

void print_ft_set(ft::set<std::string>& set)
{
	std::cout << "[ft] set: " << std::endl;
	size_t i = 0;
	for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 3 == 0)
			std::cout << std::endl;
		i++;
	}
	if (i % 3 != 0)
		std::cout << std::endl;
	std::cout << "[ft] size: " << set.size() << std::endl;
	std::cout << std::endl;
}

void	setTest()
{
	getchar();
	system("clear");

	{
		std::cout << "empty set test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		print_std_set(std_set);
		print_ft_set(ft_set);
		std::cout << "[std] empty: " << std_set.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_set.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "range constructor test" << std::endl;
		std::set<std::string> std_set_base;
		ft::set<std::string> ft_set_base;

		std_set_base.insert("(1)"); std_set_base.insert("(2)"); std_set_base.insert("(3)");
		std_set_base.insert("(4)"); std_set_base.insert("(5)"); std_set_base.insert("(6)");
		std_set_base.insert("(7)"); std_set_base.insert("(8)"); std_set_base.insert("(9)");

		ft_set_base.insert("(1)"); ft_set_base.insert("(2)"); ft_set_base.insert("(3)");
		ft_set_base.insert("(4)"); ft_set_base.insert("(5)"); ft_set_base.insert("(6)");
		ft_set_base.insert("(7)"); ft_set_base.insert("(8)"); ft_set_base.insert("(9)");

		std::set<std::string> std_set(std_set_base.begin(), std_set_base.end());
		ft::set<std::string> ft_set(ft_set_base.begin(), ft_set_base.end());
		print_std_set(std_set);
		print_ft_set(ft_set);
	}

	getchar();
	system("clear");

	{
		std::cout << "size, empty, max_size test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std::cout << "[std] set: size = " << std_set.size() << ", empty = " << std_set.empty() << std::endl;
		std::cout << "[ft] set: size = " << ft_set.size() << ", empty = " << ft_set.empty() << std::endl;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(4)"); std_set.insert("(5)"); std_set.insert("(6)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(4)"); ft_set.insert("(5)"); ft_set.insert("(6)");
		print_std_set(std_set);
		print_ft_set(ft_set);
		std::cout << "[std] set: size = " << std_set.size() << ", empty = " << std_set.empty() << std::endl;
		std::cout << "[ft] set: size = " << ft_set.size() << ", empty = " << ft_set.empty() << std::endl;
		std::cout << "[std] max_size: " << std_set.max_size() << ", [ft] max_size: " << ft_set.max_size() << std::endl;

		std::set<int> _std_set;
		ft::set<int> _ft_set;

		std::cout << "with another type of set: [std] max_size: " << _std_set.max_size() << ", [ft] max_size: " << _ft_set.max_size() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "iterators test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("asd"); std_set.insert("qew"); std_set.insert("dfg");
		std_set.insert("zxc"); std_set.insert("vef"); std_set.insert("uyj");

		ft_set.insert("asd"); ft_set.insert("qew"); ft_set.insert("dfg");
		ft_set.insert("zxc"); ft_set.insert("vef"); ft_set.insert("uyj");

		std::cout << "iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::set<std::string>::iterator it = std_set.begin(); it != std_set.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << "[ft]: " << std::endl;
		for (ft::set<std::string>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout << *it << " ";

		std::cout << std::endl << "reverse iterator: ";
		std::cout << std::endl << "[std]: " << std::endl;
		for (std::set<std::string>::reverse_iterator it = std_set.rbegin(); it != std_set.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << "[ft]: " << std::endl;
		for (ft::set<std::string>::reverse_iterator it = ft_set.rbegin(); it != ft_set.rend(); it++)
			std::cout << *it << " ";

		std::set<std::string> std_set_const(std_set);
		ft::set<std::string> ft_set_const(ft_set);

		std::cout << std::endl << "const iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::set<std::string>::const_iterator it = std_set_const.begin(); it != std_set_const.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << "[ft]: " << std::endl;
		for (ft::set<std::string>::const_iterator it = ft_set_const.begin(); it != ft_set_const.end(); it++)
			std::cout << *it << " ";

		std::cout << std::endl << "const reverse iterator: " << std::endl;
		std::cout << "[std]: " << std::endl;
		for (std::set<std::string>::const_reverse_iterator it = std_set_const.rbegin(); it != std_set_const.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << "[ft]: " << std::endl;
		for (ft::set<std::string>::const_reverse_iterator it = ft_set_const.rbegin(); it != ft_set_const.rend(); it++)
			std::cout << *it << " ";

	}

	getchar();
	system("clear");

	{
		std::cout << "insert test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("asd"); std_set.insert("qew"); std_set.insert("dfg");
		ft_set.insert("asd"); ft_set.insert("qew"); ft_set.insert("dfg");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "iterator values: " << std::endl;
		std::cout << "insert new elem: " << std::endl;
		std::pair<std::set<std::string>::iterator, bool> std_it = std_set.insert("zxc");
		std::pair<ft::set<std::string>::iterator, bool> ft_it = ft_set.insert("zxc");
		std::cout << "[std]: elem: " << *(std_it.first) << ", flag: " << std_it.second << std::endl;
		std::cout << "[ft]: elem: " << *(ft_it.first) << ", flag: " << ft_it.second << std::endl;

		std::cout << "insert elem with key that already exist: " << std::endl;
		std::pair<std::set<std::string>::iterator, bool> std_it1 = std_set.insert("zxc");
		std::pair<ft::set<std::string>::iterator, bool> ft_it1 = ft_set.insert("zxc");
		std::cout << "[std]: elem: " << *(std_it1.first) << ", flag: " << std_it1.second << std::endl;
		std::cout << "[ft]: elem: " << *(ft_it1.first) << ", flag: " << ft_it1.second << std::endl;
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "insert with position: " << std::endl;
		std_set.insert(std_set.begin(), "wbo"); std_set.insert(std_set.begin(), "asd");
		ft_set.insert(ft_set.begin(), "wbo"); ft_set.insert(ft_set.begin(), "asd");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "range insert: " << std::endl;
		std::cout << "in empty set: " << std::endl;
		std::set<std::string> _std_set;
		ft::set<std::string> _ft_set;

		_std_set.insert(std_set.begin(), --(--std_set.end()));
		_ft_set.insert(ft_set.begin(), --(--ft_set.end()));
		print_std_set(_std_set);
		print_ft_set(_ft_set);

		std::cout << "in filled set: " << std::endl;
		_std_set.insert(std_set.begin(), std_set.end());
		_ft_set.insert(ft_set.begin(), ft_set.end());
		print_std_set(_std_set);
		print_ft_set(_ft_set);
	}

	getchar();
	system("clear");

	{
		std::cout << "erase test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(4)"); std_set.insert("(5)"); std_set.insert("(6)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(4)"); ft_set.insert("(5)"); ft_set.insert("(6)");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "erase by iterator: " << std::endl;
		std_set.erase(std_set.begin()); std_set.erase(++std_set.begin());
		ft_set.erase(ft_set.begin()); ft_set.erase(++ft_set.begin());
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "erase by key: " << std::endl;
		std_set.erase("(5)");
		ft_set.erase("(5)");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "erase by range: " << std::endl;
		std_set.erase(std_set.begin(), std_set.end());
		ft_set.erase(ft_set.begin(), ft_set.end());
		print_std_set(std_set);
		print_ft_set(ft_set);
	}

	getchar();
	system("clear");

	{
		std::cout << "clear test" <<std::endl;

		std::cout << "empty set: " << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;
		std_set.clear();
		ft_set.clear();
		std::cout << "after clear: " << std::endl;
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "filled map: " << std::endl;
		std::set<std::string> _std_set;
		ft::set<std::string> _ft_set;
		_std_set.insert("(1)"); _std_set.insert("(2)"); _std_set.insert("(3)");
		_std_set.insert("(4)"); _std_set.insert("(5)"); _std_set.insert("(6)");

		_ft_set.insert("(1)"); _ft_set.insert("(2)"); _ft_set.insert("(3)");
		_ft_set.insert("(4)"); _ft_set.insert("(5)"); _ft_set.insert("(6)");
		std::cout << "before clear: " << std::endl;
		print_std_set(_std_set);
		print_ft_set(_ft_set);
		_std_set.clear();
		_ft_set.clear();
		std::cout << "after clear: " << std::endl;
		print_std_set(_std_set);
		print_ft_set(_ft_set);
	}

	getchar();
	system("clear");

	{
		std::cout << "swap test" << std::endl;
		std::set<std::string> std_set1, std_set2;
		ft::set<std::string> ft_set1, ft_set2;

		std_set1.insert("(1)"); std_set1.insert("(2)"); std_set1.insert("(3)");
		std_set2.insert("(11)"); std_set2.insert("(22)"); std_set2.insert("(33)");

		ft_set1.insert("(1)"); ft_set1.insert("(2)"); ft_set1.insert("(3)");
		ft_set2.insert("(11)"); ft_set2.insert("(22)"); ft_set2.insert("(33)");

		std::cout << "before swap: " << std::endl;
		print_std_set(std_set1); print_std_set(std_set2);
		print_ft_set(ft_set1); print_ft_set(ft_set2);
		std_set1.swap(std_set2);
		ft_set1.swap(ft_set2);
		std::cout << "after swap: " << std::endl;
		print_std_set(std_set1); print_std_set(std_set2);
		print_ft_set(ft_set1); print_ft_set(ft_set2);
	}

	getchar();
	system("clear");

	{
		std::cout << "compare test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(4)"); std_set.insert("(5)"); std_set.insert("(6)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(4)"); ft_set.insert("(5)"); ft_set.insert("(6)");
		std::set<std::string>::key_compare std_comp = std_set.key_comp();
		ft::set<std::string>::key_compare ft_comp = ft_set.key_comp();

		std::cout << "[std]: " << std::endl;
		std::set<std::string>::iterator it = std_set.begin();
		do {
			if (it == std_set.end())
				break ;
			std::cout << *it << " ";
		} while (std_comp((*it++), "zzzz"));
		std::cout << std::endl;
		std::cout << "[ft]: " << std::endl;
		ft::set<std::string>::iterator it1 = ft_set.begin();
		do {
			if (it1 == ft_set.end())
				break ;
			std::cout << *it1 << " ";
		} while (ft_comp((*it1++), "zzzz"));
		std::cout << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "find test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(4)"); std_set.insert("(5)"); std_set.insert("(6)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(4)"); ft_set.insert("(5)"); ft_set.insert("(6)");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "find existed elements: " << std::endl;
		std::cout << "find (1): " << "[std]: " << *(std_set.find("(1)")) << std::endl;
		std::cout << "find (1): " << "[ft]: " << *(ft_set.find("(1)")) << std::endl;
		std::cout << "find (3): " << "[std]: " << *(std_set.find("(3)")) << std::endl;
		std::cout << "find (3): " << "[ft]: " << *(ft_set.find("(3)")) << std::endl;
		std::cout << "find non existed element: " << std::endl;
		std::cout << "find (11): " << "[std]: ";
		if(std_set.find("(11)") == std_set.end())
			std::cout << "0" << std::endl;
		std::cout << "find (11): " << "[ft]: ";
		if(ft_set.find("(11)") == ft_set.end())
			std::cout << "0" << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "count test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(4)"); std_set.insert("(5)"); std_set.insert("(6)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(4)"); ft_set.insert("(5)"); ft_set.insert("(6)");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::cout << "count existed elements: " << std::endl;
		std::cout << "count (1): " << "[std]: " << std_set.count("(1)") << std::endl;
		std::cout << "count (1): " << "[ft]: " << ft_set.count("(1)") << std::endl;
		std::cout << "count (3): " << "[std]: " << std_set.count("(3)") << std::endl;
		std::cout << "count (3): " << "[ft]: " << ft_set.count("(3)") << std::endl;
		std::cout << "count non existed element: " << std::endl;
		std::cout << "count (11): " << "[std]: " << std_set.count("(11)") << std::endl;
		std::cout << "count (11): " << "[ft]: " << ft_set.count("(11)") << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "bounds test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(44)"); std_set.insert("(55)"); std_set.insert("(36)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(44)"); ft_set.insert("(55)"); ft_set.insert("(36)");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::set<std::string>::iterator std_it_low = std_set.lower_bound("(1)");
		std::set<std::string>::iterator std_it_up = std_set.lower_bound("(46)");
		std::cout << "[std] bounds (1, 46): " << std::endl;
		for ( ; std_it_low != std_it_up; std_it_low++)
			std::cout << *std_it_low << " ";
		std::cout << std::endl;

		ft::set<std::string>::iterator ft_it_low = ft_set.lower_bound("(1)");
		ft::set<std::string>::iterator ft_it_up = ft_set.lower_bound("(46)");
		std::cout << "[ft] bounds (1, 46): " << std::endl;
		for ( ; ft_it_low != ft_it_up; ft_it_low++)
			std::cout << *ft_it_low << " ";
		std::cout << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "equal range test" << std::endl;
		std::set<std::string> std_set;
		ft::set<std::string> ft_set;

		std_set.insert("(1)"); std_set.insert("(2)"); std_set.insert("(3)");
		std_set.insert("(44)"); std_set.insert("(55)"); std_set.insert("(36)");

		ft_set.insert("(1)"); ft_set.insert("(2)"); ft_set.insert("(3)");
		ft_set.insert("(44)"); ft_set.insert("(55)"); ft_set.insert("(36)");
		print_std_set(std_set);
		print_ft_set(ft_set);

		std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> std_range = std_set.equal_range("(3)");
		std::cout << "[std] range: (" << *(std_range.first) << ", " << *(std_range.second) << ")" << std::endl;

		std::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> ft_range = ft_set.equal_range("(3)");
		std::cout << "[ft] range: (" << *(ft_range.first) << ", " << *(ft_range.second) << ")" << std::endl;

		std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> std_range1 = std_set.equal_range("(44)");
		std::cout << "[std] range: (" << *(std_range1.first) << ", " << *(std_range1.second) << ")" << std::endl;

		std::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> ft_range1 = ft_set.equal_range("(44)");
		std::cout << "[ft] range: (" << *(ft_range1.first) << ", " << *(ft_range1.second) << ")" << std::endl;
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
