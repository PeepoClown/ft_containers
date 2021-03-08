#include <iostream>
#include "../Deque/Deque.hpp"

void	dequeTest()
{
	ft::deque<int> ft_deq(10, 3);
	for (size_t i = 0; i < 15; i++) {
		if (i % 2 == 0)
			ft_deq.push_back(i + 1);
		else
			ft_deq.push_front(i + 1);
	}
	ft_deq.print();


}
