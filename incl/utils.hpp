/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:10:35 by tmartial          #+#    #+#             */
/*   Updated: 2022/12/21 19:18:05 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstddef>

# include <iterator>


namespace ft {
	
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	ITERATOR TRAITS                     */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/iterator/iterator_tags
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/* Common iterator class */
	template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class iterator
	{
		public:
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
	};

	/* Traits class for iterators */
	template<typename Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
	};

	/* Partial specialization for pointer types */
	template<typename T>
	class iterator_traits<T*>
	{
		public:
			typedef random_access_iterator_tag		iterator_category;
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
	};

	/* Partial specialization for const pointer types */
	template<typename T>
	class iterator_traits<const T*>
	{
		public:
			typedef random_access_iterator_tag		iterator_category;
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef const T*						pointer;
			typedef const T&						reference;
	};

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	       PAIR		                    */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/utility/pair
	template < class T1, class T2 >
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first; // copy of first object
		T2	second; // copy of second object

		// Constructors 
		pair() : first(), second() {}

		pair(const T1 &a, const T2 &b) : first(a), second(b) {}

		template < class U1, class U2 >
		pair(const pair <U1, U2> &p) : first(p.first), second(p.second) {}

		pair &operator=(const pair &p)
		{
			first = p.first;
			second = p.second;
			return (*this);
		}
	};

	template < class T1, class T2 >
	bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first == y.first && x.second == y.second);
	}
	template < class T1, class T2 >
	bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	}

	template < class T1, class T2 >
	bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x == y);
	}

	template < class T1, class T2 >
	bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return y < x;
	}

	template < class T1, class T2 >
	bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(y < x);
	}

	template < class T1, class T2 >
	bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x < y);
	}

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	   MAKE PAIR		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/utility/pair/make_pair
	template < class T1, class T2 >
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}
	
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	   TYPE TRAITS		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/header/type_traits
	template <typename T, T val>
	struct integral_constant
	{
		static const	T							value = val;
		typedef			T							value_type;
		typedef			integral_constant<T, val>	type;
	};

	template<typename T, T val>
	const T integral_constant<T, val>::value;

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <typename>
	struct is_integral : public false_type {};

	template <>
	struct is_integral<bool> : public true_type {};
	template <>
	struct is_integral<char> : public true_type {};
	template <>
	struct is_integral<signed char> : public true_type {};
	template <>
	struct is_integral<unsigned char> : public true_type {};
	template <>
	struct is_integral<wchar_t> : public true_type {};
	// template <>
	// struct is_integral<char16_t> : public true_type {};
	// template <>
	// struct is_integral<char32_t> : public true_type {};
	template <>
	struct is_integral<short> : public true_type {};
	template <>
	struct is_integral<unsigned short> : public true_type {};
	template <>
	struct is_integral<int> : public true_type {};
	template <>
	struct is_integral<unsigned int> : public true_type {};
	template <>
	struct is_integral<long> : public true_type {};
	template <>
	struct is_integral<unsigned long> : public true_type {};

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	   ENABLE IF		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/types/enable_if
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };
	
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	      EQUAL 		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/algorithm/equal
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
    	for (; first1 != last1; ++first1, ++first2)
		{
        	if (!(*first1 == *first2))
            	return false;
    	}
    	return true;
	}

	/* ---------------------------------------------------- */
	/*                                                      */
	/*               LEXICOGRAPHICAL COMPARE		        */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
    	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
        	if (*first1 < *first2)
				return true;
        	if (*first2 < *first1)
				return false;
    	}
    	return (first1 == last1) && (first2 != last2);
	}

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                 	    DISTANCE		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	//Link: https://en.cppreference.com/w/cpp/iterator/distance
	template < class InputIterator >
	typename iterator_traits<InputIterator>::difference_type __distance(InputIterator _first, InputIterator _last, input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (_first != _last)
		{
			_first++;
			n++;
		}
		return (n);
	}

	template < class RandomAccessIterator >
	typename iterator_traits<RandomAccessIterator>::difference_type __distance(RandomAccessIterator _first, RandomAccessIterator _last, random_access_iterator_tag)
	{
		return (_last - _first);
	}

	template < class InputIterator >
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		return __distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
	}
	
}

#endif
