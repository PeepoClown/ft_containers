#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <list>
#include "../List/List.hpp"

void print_std_list(std::list<int>& list)
{
	std::cout << "[std] list: " << std::endl;
	size_t i = 0;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 10 == 0 && i != list.size() - 1)
			std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "[std] size: " << list.size() << std::endl;
}

void print_ft_list(ft::list<int>& list)
{
	std::cout << "[ft] list: " << std::endl;
	size_t i = 0;
	for (ft::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << " ";
		if ((i + 1) % 10 == 0 && i != list.size() - 1)
			std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "[ft] size: " << list.size() << std::endl;
}

bool is_negative(int& val)
{ return (val < 0); }

bool unique_test(int& val1, int &val2)
{ return (val1 + 1 == val2); }

bool merge_test(int& val1, int& val2)
{ return (val1 > val2); }

void	listTest()
{
	srand(time(NULL));

	getchar();
	system("clear");

	{
		std::cout << "empty list test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;

		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "[std] empty: " << std_list.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_list.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "fill constructor and iterators test" << std::endl;
		std::list<int> std_list((size_t)5, 10);
		ft::list<int> ft_list((size_t)5, 10);
		for (size_t i = 0; i < 25; i++) {
			int val = rand() % 200 - 100;
			std_list.push_back(val);
			ft_list.push_back(val);
		}
		std::cout << "[std] size: " << std_list.size() << std::endl;
		std::cout << "[ft] size: " << ft_list.size() << std::endl;
		std::cout << "[std] empty: " << std_list.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_list.empty() << std::endl;
		std::cout << "iterator" << std::endl;
		std::cout << "[std] list: ";
		size_t i = 0;
		for (std::list<int>::iterator it = std_list.begin(); it != std_list.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft] list: ";
		i = 0;
		for (ft::list<int>::iterator it = ft_list.begin(); it != ft_list.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << "reverse iterator" << std::endl;
		std::cout << "[std] list: ";
		i = 0;
		for (std::list<int>::reverse_iterator it = std_list.rbegin(); it != std_list.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft] list: ";
		i = 0;
		for (ft::list<int>::reverse_iterator it = ft_list.rbegin(); it != ft_list.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		const std::list<int> std_list_const(std_list);
		const ft::list<int> ft_list_const(ft_list);
		std::cout << "const iterator" << std::endl;
		std::cout << "[std] list: ";
		i = 0;
		for (std::list<int>::const_iterator it = std_list_const.begin(); it != std_list_const.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft] list: ";
		i = 0;
		for (ft::list<int>::const_iterator it = ft_list_const.begin(); it != ft_list_const.end(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << "const reverse iterator" << std::endl;
		std::cout << "[std] list: ";
		i = 0;
		for (std::list<int>::const_reverse_iterator it = std_list_const.rbegin(); it != std_list_const.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << "[ft] list: ";
		i = 0;
		for (ft::list<int>::const_reverse_iterator it = ft_list_const.rbegin(); it != ft_list_const.rend(); it++) {
			std::cout << *it << " ";
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
	}

	getchar();
	system("clear");

	{
		std::cout << "range constructor test" << std::endl;
		std::list<int> std_list_base((size_t)10, 3); std_list_base.push_back(100); std_list_base.push_front(1000);
		ft::list<int> ft_list_base((size_t)10, 3); ft_list_base.push_back(100); ft_list_base.push_front(1000);
		std::list<int> std_list(std_list_base.begin(), std_list_base.end());
		ft::list<int> ft_list(ft_list_base.begin(), ft_list_base.end());
		print_std_list(std_list);
		print_ft_list(ft_list);
	}

	getchar();
	system("clear");

	{
		std::cout << "max_size, size, empty test" << std::endl;
		std::list<int> std_list_int((size_t)10, 3);
		ft::list<int> ft_list_int((size_t)10, 3);
		std::list<double> std_list_double((size_t)100, 3);
		ft::list<double> ft_list_double((size_t)100, 3);

		std::cout << "for integer list" << std::endl;
		std::cout << "[std] max_size: " << std_list_int.max_size() << " size: " << std_list_int.size() << std::endl;
		std::cout << "[ft]  max_size: " << ft_list_int.max_size() << " size: " << ft_list_int.size() << std::endl;
		std::cout << "[std] empty: " << std_list_int.empty() << std::endl;
		std::cout << "[ft]  empty: " << ft_list_int.empty() << std::endl;
		std::cout << "for float point numbers list" << std::endl;
		std::cout << "[std] max_size: " << std_list_double.max_size() << " size: " << std_list_double.size() << std::endl;
		std::cout << "[ft]  max_size: " << ft_list_double.max_size() << " size: " << ft_list_double.size() << std::endl;
		std::cout << "[std] empty: " << std_list_double.empty() << std::endl;
		std::cout << "[ft]  empty: " << ft_list_double.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "front, back test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;

		std_list.push_back(154); std_list.push_back(9437); std_list.push_back(288); std_list.push_back(1002);
		ft_list.push_back(154); ft_list.push_back(9437); ft_list.push_back(288); ft_list.push_back(1002);
		std::cout << "[std] front: " << std_list.front() << " back: " << std_list.back() << std::endl;
		std::cout << "[ft] front: " << ft_list.front() << " back: " << ft_list.back() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "push_back/push_front test" << std::endl;
		std::cout << "pushing in empty list" << std::endl;
		std::list<int> std_list1;
		ft::list<int> ft_list1;
		std_list1.push_front(100); std_list1.push_back(200); std_list1.push_back(300); std_list1.push_front(400); std_list1.push_back(500);
		ft_list1.push_front(100); ft_list1.push_back(200); ft_list1.push_back(300); ft_list1.push_front(400); ft_list1.push_back(500);
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::cout << "pushing in non empty list" << std::endl;
		std::list<int> std_list2((size_t)10, 7);
		ft::list<int> ft_list2((size_t)10, 7);
		std::cout << "[std] size: " << std_list2.size() << std::endl;
		std::cout << "[ft] size: " << ft_list2.size() << std::endl;
		std_list2.push_front(100); std_list2.push_back(200); std_list2.push_back(300); std_list2.push_front(400); std_list2.push_back(500);
		ft_list2.push_front(100); ft_list2.push_back(200); ft_list2.push_back(300); ft_list2.push_front(400); ft_list2.push_back(500);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
	}

	getchar();
	system("clear");

	{
		std::cout << "pop_back/pop_front, clear test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;
		for (size_t i = 0; i < 30; i++) {
			int val = rand() % 200 - 100;
			std_list.push_back(val);
			ft_list.push_back(val);
		}
		std::cout << "current list content" << std::endl;
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after 3 pop_back and 1 pop_front" << std::endl;
		std_list.pop_back(); std_list.pop_front(); std_list.pop_back(); std_list.pop_back();
		ft_list.pop_back(); ft_list.pop_front(); ft_list.pop_back(); ft_list.pop_back();
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after clear" << std::endl;
		std_list.clear(); ft_list.clear();
		print_std_list(std_list);
		print_ft_list(ft_list);
	}

	getchar();
	system("clear");

	{
		std::cout << "insert test" << std::endl;
		std::cout << "insertion in empty list" << std::endl;
		std::list<int> std_list_base((size_t)10, 3); std_list_base.push_back(100); std_list_base.push_front(1000);
		ft::list<int> ft_list_base((size_t)10, 3); ft_list_base.push_back(100); ft_list_base.push_front(1000);
		std::list<int> std_list1;
		ft::list<int> ft_list1;
		std_list1.insert(std_list1.begin(), std_list_base.begin(), std_list_base.end());
		ft_list1.insert(ft_list1.begin(), ft_list_base.begin(), ft_list_base.end());
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::cout << "insertion in non empty list" << std::endl;
		std::list<int> std_list2;
		ft::list<int> ft_list2;
		std_list2.push_back(100); std_list2.push_back(200); std_list2.push_back(300);
		ft_list2.push_back(100); ft_list2.push_back(200); ft_list2.push_back(300);
		std_list2.insert(std_list2.begin(), 777); // single
		ft_list2.insert(ft_list2.begin(), 777);
		std_list2.insert(std_list2.begin(), (size_t)2, 77); // fill
		ft_list2.insert(ft_list2.begin(), (size_t)2, 77);
		std_list2.insert(++std_list2.begin(), std_list_base.begin(), ++(++(++std_list_base.begin()))); // range
		ft_list2.insert(++ft_list2.begin(), ft_list_base.begin(), ++(++(++ft_list_base.begin())));
		print_std_list(std_list2);
		print_ft_list(ft_list2);
	}

	getchar();
	system("clear");

	{
		std::cout << "erase test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;
		std_list.push_back(100); std_list.push_back(200); std_list.push_back(300); std_list.push_back(400); std_list.push_back(500); std_list.push_back(600);
		ft_list.push_back(100); ft_list.push_back(200); ft_list.push_back(300); ft_list.push_back(400); ft_list.push_back(500); ft_list.push_back(600);
		std::cout << "current list content" << std::endl;
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after erase begin and end" << std::endl;
		std_list.erase(std_list.begin()); std_list.erase(--std_list.end());
		ft_list.erase(ft_list.begin()); ft_list.erase(--ft_list.end());
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after erase all elements" << std::endl;
		std_list.erase(std_list.begin(), std_list.end());
		ft_list.erase(ft_list.begin(), ft_list.end());
		print_std_list(std_list);
		print_ft_list(ft_list);
	}

	getchar();
	system("clear");

	{
		std::cout << "assign test" << std::endl;
		std::cout << "assign list to empty container" << std::endl;
		std::list<int> std_list_base;
		ft::list<int> ft_list_base;
		std_list_base.push_back(100); std_list_base.push_back(200); std_list_base.push_back(300); std_list_base.push_back(400); std_list_base.push_back(500);
		ft_list_base.push_back(100); ft_list_base.push_back(200); ft_list_base.push_back(300); ft_list_base.push_back(400); ft_list_base.push_back(500);
		std::list<int> std_list1;
		ft::list<int> ft_list1;
		std_list1.assign(std_list_base.begin(), std_list_base.end());
		ft_list1.assign(ft_list_base.begin(), ft_list_base.end());
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::cout << "assign list to non empty container" << std::endl;
		std::list<int> std_list2((size_t)10, 3);
		ft::list<int> ft_list2((size_t)10, 3);
		std_list2.assign(std_list_base.begin(), std_list_base.end());
		ft_list2.assign(ft_list_base.begin(), ft_list_base.end());
		print_std_list(std_list2);
		print_ft_list(ft_list2);
	}

	getchar();
	system("clear");

	{
		std::cout << "resize test" << std::endl;
		std::cout << "increase resizing empty container" << std::endl;
		std::list<int> std_list1;
		ft::list<int> ft_list1;
		std_list1.resize(10, 33); ft_list1.resize(10, 33);
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::cout << "increase resizing of non empty container" << std::endl;
		std::list<int> std_list2((size_t)5, 11);
		ft::list<int> ft_list2((size_t)5, 11);
		std_list2.resize(10, 33); ft_list2.resize(10, 33);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std::cout << "decrease resizing" << std::endl;
		std::list<int> std_list3((size_t)55, 11);
		ft::list<int> ft_list3((size_t)55, 11);
		std::cout << "[std] size: " << std_list3.size() << std::endl;
		std::cout << "[ft] size: " << ft_list3.size() << std::endl;
		std::cout << "after resize to 10 elements" << std::endl;
		std_list3.resize(10); ft_list3.resize(10);
		print_std_list(std_list3);
		print_ft_list(ft_list3);
	}

	getchar();
	system("clear");

	{
		std::cout << "swap test" << std::endl;
		std::list<int> std_list1, std_list2;
		ft::list<int> ft_list1, ft_list2;
		std_list1.push_back(100); std_list1.push_back(200); std_list1.push_back(300);
		std_list2.push_back(77); std_list2.push_back(88); std_list2.push_back(99); std_list2.push_back(789);
		ft_list1.push_back(100); ft_list1.push_back(200); ft_list1.push_back(300);
		ft_list2.push_back(77); ft_list2.push_back(88); ft_list2.push_back(99); ft_list2.push_back(789);
		std::list<int>::iterator std_it1 = std_list1.begin(), std_it2 = std_list2.begin();
		ft::list<int>::iterator ft_it1 = ft_list1.begin(), ft_it2 = ft_list2.begin();
		std::cout << "iterators before swap" << std::endl;
		std::cout << "[std1] " << *std_it1 << " [ft1] " << *ft_it1 << std::endl;
		std::cout << "[std2] " << *std_it2 << " [ft2] " << *ft_it2 << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std_list1.swap(std_list2);
		ft_list1.swap(ft_list2);
		std::cout << "iterators after swap(the same but points to another container)" << std::endl;
		std::cout << "[std1] " << *std_it1 << " [ft1] " << *ft_it1 << std::endl;
		std::cout << "[std2] " << *std_it2 << " [ft2] " << *ft_it2 << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
	}

	getchar();
	system("clear");

	{
		std::cout << "splice test" << std::endl;
		std::cout << "transfer single element" << std::endl;
		std::list<int> std_list1, std_list2;
		ft::list<int> ft_list1, ft_list2;
		std_list1.push_back(456); std_list1.push_back(123); std_list1.push_back(789);
		std_list2.push_back(100); std_list2.push_back(200); std_list2.push_back(300); std_list2.push_back(400); std_list2.push_back(500);
		ft_list1.push_back(456); ft_list1.push_back(123); ft_list1.push_back(789);
		ft_list2.push_back(100); ft_list2.push_back(200); ft_list2.push_back(300); ft_list2.push_back(400); ft_list2.push_back(500);
		std::cout << "before transfer" << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std_list1.splice(std_list1.begin(), std_list2, std_list2.begin());
		ft_list1.splice(ft_list1.begin(), ft_list2, ft_list2.begin());
		std::cout << "after transfer" << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std::cout << "transfer range(container is the same as after the last splice)" << std::endl;
		std_list2.splice(std_list2.end(), std_list1, std_list1.begin(), ++(++std_list1.begin()));
		ft_list2.splice(ft_list2.end(), ft_list1, ft_list1.begin(), ++(++ft_list1.begin()));
		std::cout << "after transfer" << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std::cout << "transfer all list(container is the same as after the last splice)" << std::endl;
		std_list1.splice(std_list1.begin(), std_list2);
		ft_list1.splice(ft_list1.begin(), ft_list2);
		std::cout << "after transfer" << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
	}

	getchar();
	system("clear");

	{
		std::cout << "remove/remove_if test" << std::endl;
		std::list<int> std_list1;
		ft::list<int> ft_list1;
		std_list1.push_back(100); std_list1.push_back(140); std_list1.push_back(112); std_list1.push_back(100); std_list1.push_back(150); std_list1.push_back(101);
		ft_list1.push_back(100); ft_list1.push_back(140); ft_list1.push_back(112); ft_list1.push_back(100); ft_list1.push_back(150); ft_list1.push_back(101);
		std::cout << "before removing" << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::cout << "after removing 100" << std::endl;
		std_list1.remove(100);
		ft_list1.remove(100);
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::cout << "after removing 102" << std::endl;
		std_list1.remove(102);
		ft_list1.remove(102);
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::list<int> std_list2;
		ft::list<int> ft_list2;
		for (size_t i = 0; i < 30; i++) {
			int val = rand() % 200 - 100;
			std_list2.push_back(val);
			ft_list2.push_back(val);
		}
		std::cout << "generated list" << std::endl;
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std::cout << "after removing all negative values" << std::endl;
		std_list2.remove_if(is_negative);
		ft_list2.remove_if(is_negative);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
	}

	getchar();
	system("clear");

	{
		std::cout << "unique test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;
		for (size_t i = 0; i < 30; i++) {
			int val = rand() % 5;
			std_list.push_back(val);
			ft_list.push_back(val);
		}
		std::cout << "before unique" << std::endl;
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after unique" << std::endl;
		std_list.unique();
		ft_list.unique();
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after unique with predicate" << std::endl;
		std_list.unique(unique_test);
		ft_list.unique(unique_test);
		print_std_list(std_list);
		print_ft_list(ft_list);
	}

	getchar();
	system("clear");

	{
		std::cout << "merge test" << std::endl;
		std::list<int> std_list1, std_list2;
		ft::list<int> ft_list1, ft_list2;
		std_list1.push_back(100); std_list1.push_back(200); std_list1.push_back(300); std_list1.push_back(400); std_list1.push_back(500);
		std_list2.push_back(123); std_list2.push_back(456); std_list2.push_back(789);
		ft_list1.push_back(100); ft_list1.push_back(200); ft_list1.push_back(300); ft_list1.push_back(400); ft_list1.push_back(500);
		ft_list2.push_back(123); ft_list2.push_back(456); ft_list2.push_back(789);
		std::cout << "before merging" << std::endl;
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		print_std_list(std_list2);
		print_ft_list(ft_list2);
		std::cout << "after merging" << std::endl;
		std_list1.merge(std_list2);
		ft_list1.merge(ft_list2);
		print_std_list(std_list1);
		print_ft_list(ft_list1);
		std::list<int> std_list3, std_list4;
		ft::list<int> ft_list3, ft_list4;
		std_list3.push_back(564); std_list3.push_back(345); std_list3.push_back(222);
		std_list4.push_back(123); std_list4.push_back(456); std_list4.push_back(789);
		ft_list3.push_back(564); ft_list3.push_back(345); ft_list3.push_back(222);
		ft_list4.push_back(123); ft_list4.push_back(456); ft_list4.push_back(789);
		std::cout << "after merging with comparator" << std::endl;
		std_list3.merge(std_list4, merge_test);
		ft_list3.merge(ft_list4, merge_test);
		print_std_list(std_list3);
		print_ft_list(ft_list3);
	}

	getchar();
	system("clear");

	{
		std::cout << "sort test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;
		for (size_t i = 0; i < 100; i++) {
			int val = rand() % 200 - 100;
			std_list.push_back(val);
			ft_list.push_back(val);
		}
		std::cout << "unsorted list" << std::endl;
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after ascending sort" << std::endl;
		std_list.sort(); ft_list.sort();
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after descending sort" << std::endl;
		std_list.sort(merge_test); ft_list.sort(merge_test);
		print_std_list(std_list);
		print_ft_list(ft_list);
	}

	getchar();
	system("clear");

	{
		std::cout << "reverse test" << std::endl;
		std::list<int> std_list;
		ft::list<int> ft_list;
		for (size_t i = 0; i < 30; i++) {
			int val = rand() % 200 - 100;
			std_list.push_back(val);
			ft_list.push_back(val);
		}
		std::cout << "normal order" << std::endl;
		print_std_list(std_list);
		print_ft_list(ft_list);
		std::cout << "after reverse" << std::endl;
		std_list.reverse(); ft_list.reverse();
		print_std_list(std_list);
		print_ft_list(ft_list);
	}

	getchar();
	system("clear");

	{
		std::cout << "compare operators test" << std::endl;
		std::list<int> std_list1, std_list2, std_list3;
		ft::list<int> ft_list1, ft_list2, ft_list3;
		std_list1.push_back(1); std_list1.push_back(2); std_list1.push_back(3);
		std_list2.push_back(1); std_list2.push_back(2);
		std_list3.push_back(1); std_list3.push_back(2); std_list3.push_back(4);
		ft_list1.push_back(1); ft_list1.push_back(2); ft_list1.push_back(3);
		ft_list2.push_back(1); ft_list2.push_back(2);
		ft_list3.push_back(1); ft_list3.push_back(2); ft_list3.push_back(4);
		std::cout << "[std] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (std_list1 == std_list2) << std::endl;
		std::cout << "!= : " << (std_list1 != std_list2) << std::endl;
		std::cout << "< : " << (std_list1 < std_list2) << std::endl;
		std::cout << "> : " << (std_list1 > std_list2) << std::endl;
		std::cout << "<= : " << (std_list1 <= std_list2) << std::endl;
		std::cout << ">= : " << (std_list1 >= std_list2) << std::endl;
		std::cout << "[std] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (std_list1 == std_list3) << std::endl;
		std::cout << "!= : " << (std_list1 != std_list3) << std::endl;
		std::cout << "< : " << (std_list1 < std_list3) << std::endl;
		std::cout << "> : " << (std_list1 > std_list3) << std::endl;
		std::cout << "<= : " << (std_list1 <= std_list3) << std::endl;
		std::cout << ">= : " << (std_list1 >= std_list3) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (ft_list1 == ft_list2) << std::endl;
		std::cout << "!= : " << (ft_list1 != ft_list2) << std::endl;
		std::cout << "< : " << (ft_list1 < ft_list2) << std::endl;
		std::cout << "> : " << (ft_list1 > ft_list2) << std::endl;
		std::cout << "<= : " << (ft_list1 <= ft_list2) << std::endl;
		std::cout << ">= : " << (ft_list1 >= ft_list2) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (ft_list1 == ft_list3) << std::endl;
		std::cout << "!= : " << (ft_list1 != ft_list3) << std::endl;
		std::cout << "< : " << (ft_list1 < ft_list3) << std::endl;
		std::cout << "> : " << (ft_list1 > ft_list3) << std::endl;
		std::cout << "<= : " << (ft_list1 <= ft_list3) << std::endl;
		std::cout << ">= : " << (ft_list1 >= ft_list3) << std::endl;
		std::list<int> std_list_copy(std_list1);
		ft::list<int> ft_list_copy(ft_list1);
		std::cout << "compare equal lists" << std::endl;
		std::cout << "[std]" << std::endl;
		std::cout << "== : " << (std_list1 == std_list_copy) << std::endl;
		std::cout << "!= : " << (std_list1 != std_list_copy) << std::endl;
		std::cout << "< : " << (std_list1 < std_list_copy) << std::endl;
		std::cout << "> : " << (std_list1 > std_list_copy) << std::endl;
		std::cout << "<= : " << (std_list1 <= std_list_copy) << std::endl;
		std::cout << ">= : " << (std_list1 >= std_list_copy) << std::endl;
		std::cout << "[ft]" << std::endl;
		std::cout << "== : " << (ft_list1 == ft_list_copy) << std::endl;
		std::cout << "!= : " << (ft_list1 != ft_list_copy) << std::endl;
		std::cout << "< : " << (ft_list1 < ft_list_copy) << std::endl;
		std::cout << "> : " << (ft_list1 > ft_list_copy) << std::endl;
		std::cout << "<= : " << (ft_list1 <= ft_list_copy) << std::endl;
		std::cout << ">= : " << (ft_list1 >= ft_list_copy) << std::endl;
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
