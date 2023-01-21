/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:45:02 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/15 14:52:36 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_HPP_
# define _UTILS_HPP_

namespace ft
{

/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          ENABLE_IF                               */
/*																	*/
/* ---------------------------------------------------------------- */
	template <bool Cond, class T = void>
	struct	enable_if {};

	template <class T>
	struct	enable_if<true, T> { typedef T type; };


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          TYPE_TRAITS                             */
/*																	*/
/* ---------------------------------------------------------------- */
// is_integral
	template <typename T>
	struct	is_integral
	{
		static const bool	value = false;
	};

	template <>
	struct	is_integral<bool>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<char>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<char16_t>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<char32_t>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<wchar_t>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<signed char>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<short int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<long int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<long long int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<unsigned char>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<unsigned short int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<unsigned int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<unsigned long int>
	{
		static const bool	value = true;
	};

	template <>
	struct	is_integral<unsigned long long int>
	{
		static const bool	value = true;
	};


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          COMPARE                                 */
/*																	*/
/* ---------------------------------------------------------------- */
// equal
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

// lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          PAIR                                    */
/*																	*/
/* ---------------------------------------------------------------- */
	template <class T1, class T2>
	struct	pair
	{
	// member types
		typedef T1	first_type;
		typedef T2	second_type;

	// member variables
		T1	first;
		T2	second;

	// default constructor
		pair() : first(), second() {}

	// initialization constructor
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

	// copy
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

	// assign operator
		pair	&operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

// operator '=='
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second== rhs.second);
	}

// operator '!='
	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

// operator '<'
	template <class T1, class T2>
	bool	operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

// operator '<='
	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

// operator '>'
	template <class T1, class T2>
	bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

// operator '>='
	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          MAKE_PAIR                               */
/*																	*/
/* ---------------------------------------------------------------- */
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          DISTANCE                                */
/*																	*/
/* ---------------------------------------------------------------- */
	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	rtn = 0;

		while (first != last)
		{
			first++;
			rtn++;
		}
		return (rtn);
	}




}

#endif
