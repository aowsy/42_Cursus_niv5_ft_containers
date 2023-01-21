/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:31:11 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/13 11:36:42 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"
#include "utils.hpp"
#include "reverse_iterator.hpp"
//#include "map.hpp"
//#include "binary_tree.hpp"
//#include "map_iterator.hpp"
#include <algorithm>
#include "stack.hpp"
#include <map>
#include <list>
#include <string>
#include <stack>
#include <time.h>
#include <sys/time.h>

#define NAMESPACE ft // change to STD if you want to compare with the STL


time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, NULL);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void print_time(time_t start)
{
	time_t second = timer();
	std::cout << "Time = " << second - start << "ms" << std::endl;
}

int main()
{
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                        VECTOR		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	std::cout << "VECTOR" << std::endl << std::endl;
	{
		time_t start = timer();
		std::cout << "~~~~TEST WITH INT~~~~~" << std::endl;
		NAMESPACE::vector<int> a;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----CAPACITY----" << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----PUSH_BACK + operator[] + RESERVE----" << std::endl;
		int j = 1;
		for (int i = 0; i < 30; i++)
		{
			a.push_back((j += 3) % 2 ? j : -j);
			std::cout << "Index " << i << " : value = " << a[i] << std::endl;
		}
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----CAPACITY----" << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----RESERVE----" << std::endl;
		a.reserve(50);
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----CAPACITY----" << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << "----AT----" << std::endl;
		std::cout << a.at(5) << std::endl;
		std::cout << a.at(15) << std::endl;
		std::cout << "----FRONT----" << std::endl;
		std::cout << a.front() << std::endl;
		std::cout << "----BACK----" << std::endl;
		std::cout << a.back() << std::endl;
		std::cout << "----COPY_CONSTRUCTOR----" << std::endl;
		NAMESPACE::vector<int> b(a);
		std::cout << "----ASSIGN----" << std::endl;
		std::cout << "before : size = " << a.size() << " && capacity = " << a.capacity() << std::endl;
		a.assign(10, 400);
		std::cout << "after : size = " << a.size() << " && capacity = " << a.capacity() << std::endl;
		std::cout << "----CLEAR----" << std::endl;
		a.clear();
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----OPERATOR=----" << std::endl;
		a = b;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----POP_BACK + RESIZE----" << std::endl;
		for (int i = 0; i < 20; i++)
		{
			a.pop_back();
		}
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a.at(i) << std::endl;
		}
		std::cout << "----INSERT + BEGIN + END----" << std::endl;
		std::cout << "lets remplace the value of the index 0 by 900" << std::endl;
		a.insert(a.begin(), 900);
		std::cout << "Index " << 0 << " : value = " << a[0] << std::endl;
		std::cout << "lets copy b in the end of a by using insert" << std::endl;
		a.insert(a.end(), b.begin(), b.end());
		std::cout << "lets add 5 x 200 to the result" << std::endl;
		a.insert(a.end(), 5, 200);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a[i] << std::endl;
		}
		std::cout << "----ERASE + BEGIN + END----" << std::endl;
		std::cout << "lets remove the end element" << std::endl;
		a.erase(a.end() - 1);
		std::cout << "lets remove the two first elements" << std::endl;
		NAMESPACE::vector<int>::iterator it = a.begin();
		it = it + 2;
		a.erase(a.begin(), it);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a.at(i) << std::endl;
		}
		std::cout << "----SWAP----" << std::endl;
		a.swap(b);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a.at(i) << std::endl;
		}
		std::cout << "----OPERATORS----" << std::endl;
		std::cout << "a == b : "<< (a == b) << std::endl;
		std::cout << "a != b : "<< (a != b) << std::endl;
		std::cout << "a > b : "<< (a > b) << std::endl;
		std::cout << "a < b : "<< (a < b) << std::endl;
		std::cout << "~~~~MINI TEST WITH CONST CHAR *~~~~" << std::endl;
		std::cout << "----CONSTRUCTOR WITH VALUE----" << std::endl;
		NAMESPACE::vector<const char *> c(4, "coucou");
		std::cout << "----CONSTRUCTOR WITH ITERATORS----" << std::endl;
		NAMESPACE::vector<const char *> d(c.begin(), c.end());
		for (unsigned int i = 0; i < d.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << d[i] << std::endl;
		}
		std::cout << "----TIME----" << std::endl;
		print_time(start);
	}

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                      STACK                           */
	/*                                                      */
	/* ---------------------------------------------------- */
	std::cout << "STACK" << std::endl << std::endl;
	{
		time_t start = timer();
		NAMESPACE::stack<int> a;
		std::cout << "~~~TEST WITH INT :~~~" << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----PUSH----" << std::endl;
		for (int i = 0; i < 30; i++)
		{
			a.push(i * 3);
			std::cout << "at index " << i << " : value = " << i * 3 << std::endl;
		}
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << a.top() << std::endl;
		std::cout << "----POP----" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			a.pop();
		}
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << a.top() << std::endl;
		NAMESPACE::stack<float> b;
		std::cout << std::endl;
		std::cout << "~~~TEST WITH FLOAT :~~~" << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << b.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "----PUSH----" << std::endl;
		float f = -0.5f;
		for (int i = 0; i < 30; i++)
		{
			b.push(f);
			std::cout << "at index " << i << " : value = " << f << std::endl;
			f += 0.6f;
		}
		std::cout << "----EMPTY----" << std::endl;
		std::cout << b.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << b.top() << std::endl;
		std::cout << "----POP----" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			b.pop();
		}
		std::cout << "----SIZE----" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << b.top() << std::endl;
		std::cout << "----TIME----" << std::endl;
		print_time(start);
	}

	return 0;
}
