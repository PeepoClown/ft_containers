#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include "../Stack/Stack.hpp"

void	stackTest()
{
	getchar();
	system("clear");

	{
		std::stack<int> std_stack;
		ft::stack<int> ft_stack;

		std::cout << "empty stack" << std::endl;
		std::cout << "[std] size: " << std_stack.size() << std::endl;
		std::cout << "[ft] size: " << ft_stack.size() << std::endl;
		std::cout << "[std] empty: " << std_stack.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_stack.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::stack<int> std_stack;
		ft::stack<int> ft_stack;

		std_stack.push(1); std_stack.push(2); std_stack.push(3);
		ft_stack.push(1); ft_stack.push(2); ft_stack.push(3);
		std::cout << "3 2 1 stack" << std::endl;
		std::cout << "[std] size: " << std_stack.size() << std::endl;
		std::cout << "[ft] size: " << ft_stack.size() << std::endl;
		std::cout << "[std] empty: " << std_stack.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_stack.empty() << std::endl;
		std::cout << "[std] front: " << std_stack.top() << std::endl;
		std::cout << "[ft] front: " << ft_stack.top() << std::endl;
		std::cout << "[std] stack: ";
		while (!std_stack.empty()) {
			std::cout << std_stack.top() << " ";
			std_stack.pop();
		}
		std::cout << std::endl << "[ft] stack: ";
		while (!ft_stack.empty()) {
			std::cout << ft_stack.top() << " ";
			ft_stack.pop();
		}
		std::cout << std::endl << "[std] empty: " << std_stack.empty() << std::endl;
		std::cout << "[ft] empty: " << ft_stack.empty() << std::endl;
	}

	getchar();
	system("clear");

	{
		std::stack<int> std_stack;
		ft::stack<int> ft_stack;

		std::cout << "100 elements stack" << std::endl;
		srand(time(NULL));
		for (size_t i = 0; i < 100; i++) {
			int val = rand() % 2000 - 1000;
			std_stack.push(val);
			ft_stack.push(val);
		}
		std::cout << "[std] size: " << std_stack.size() << std::endl;
		std::cout << "[ft] size: " << ft_stack.size() << std::endl;
		std::cout << "decrease by 3 elements" << std::endl;
		std_stack.pop(); std_stack.pop(); std_stack.pop();
		ft_stack.pop(); ft_stack.pop(); ft_stack.pop();
		std::cout << "[std] size: " << std_stack.size() << std::endl;
		std::cout << "[ft] size: " << ft_stack.size() << std::endl;
		std::cout << "[std] stack: ";
		size_t i = 0;
		while (!std_stack.empty()) {
			std::cout << std_stack.top() << " ";
			std_stack.pop();
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << std::endl << "[ft] stack: ";
		i = 0;
		while (!ft_stack.empty()) {
			std::cout << ft_stack.top() << " ";
			ft_stack.pop();
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
			i++;
		}
		std::cout << std::endl;
	}

	getchar();
	system("clear");

	{
		std::cout << "compare operators test" << std::endl;
		std::stack<int> std_stack1;
		std::stack<int> std_stack2;
		std::stack<int> std_stack3;
		ft::stack<int> ft_stack1;
		ft::stack<int> ft_stack2;
		ft::stack<int> ft_stack3;

		std_stack1.push(3); std_stack1.push(2); std_stack1.push(1);
		std_stack2.push(2); std_stack2.push(1);
		std_stack3.push(4); std_stack3.push(2); std_stack3.push(1);

		ft_stack1.push(3); ft_stack1.push(2); ft_stack1.push(1);
		ft_stack2.push(2); ft_stack2.push(1);
		ft_stack3.push(4); ft_stack3.push(2); ft_stack3.push(1);

		std::cout << "[std] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (std_stack1 == std_stack2) << std::endl;
		std::cout << "!= : " << (std_stack1 != std_stack2) << std::endl;
		std::cout << "< : " << (std_stack1 < std_stack2) << std::endl;
		std::cout << "> : " << (std_stack1 > std_stack2) << std::endl;
		std::cout << "<= : " << (std_stack1 <= std_stack2) << std::endl;
		std::cout << ">= : " << (std_stack1 >= std_stack2) << std::endl;
		std::cout << "[std] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (std_stack1 == std_stack3) << std::endl;
		std::cout << "!= : " << (std_stack1 != std_stack3) << std::endl;
		std::cout << "< : " << (std_stack1 < std_stack3) << std::endl;
		std::cout << "> : " << (std_stack1 > std_stack3) << std::endl;
		std::cout << "<= : " << (std_stack1 <= std_stack3) << std::endl;
		std::cout << ">= : " << (std_stack1 >= std_stack3) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (ft_stack1 == ft_stack2) << std::endl;
		std::cout << "!= : " << (ft_stack1 != ft_stack2) << std::endl;
		std::cout << "< : " << (ft_stack1 < ft_stack2) << std::endl;
		std::cout << "> : " << (ft_stack1 > ft_stack2) << std::endl;
		std::cout << "<= : " << (ft_stack1 <= ft_stack2) << std::endl;
		std::cout << ">= : " << (ft_stack1 >= ft_stack2) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (ft_stack1 == ft_stack3) << std::endl;
		std::cout << "!= : " << (ft_stack1 != ft_stack3) << std::endl;
		std::cout << "< : " << (ft_stack1 < ft_stack3) << std::endl;
		std::cout << "> : " << (ft_stack1 > ft_stack3) << std::endl;
		std::cout << "<= : " << (ft_stack1 <= ft_stack3) << std::endl;
		std::cout << ">= : " << (ft_stack1 >= ft_stack3) << std::endl;

		std::stack<int> std_stack_copy(std_stack1);
		ft::stack<int> ft_stack_copy(ft_stack1);

		std::cout << "compare equal stacks" << std::endl;
		std::cout << "[std]" << std::endl;
		std::cout << "== : " << (std_stack1 == std_stack_copy) << std::endl;
		std::cout << "!= : " << (std_stack1 != std_stack_copy) << std::endl;
		std::cout << "< : " << (std_stack1 < std_stack_copy) << std::endl;
		std::cout << "> : " << (std_stack1 > std_stack_copy) << std::endl;
		std::cout << "<= : " << (std_stack1 <= std_stack_copy) << std::endl;
		std::cout << ">= : " << (std_stack1 >= std_stack_copy) << std::endl;
		std::cout << "[ft]" << std::endl;
		std::cout << "== : " << (ft_stack1 == ft_stack_copy) << std::endl;
		std::cout << "!= : " << (ft_stack1 != ft_stack_copy) << std::endl;
		std::cout << "< : " << (ft_stack1 < ft_stack_copy) << std::endl;
		std::cout << "> : " << (ft_stack1 > ft_stack_copy) << std::endl;
		std::cout << "<= : " << (ft_stack1 <= ft_stack_copy) << std::endl;
		std::cout << ">= : " << (ft_stack1 >= ft_stack_copy) << std::endl;
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

