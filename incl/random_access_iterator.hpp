/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:16:07 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/23 16:22:08 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RANDOM_ACCESS_ITERATOR_HPP_
# define _RANDOM_ACCESS_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft
{

	template <class T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{

		public :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          MEMBER TYPES                            */
		/*																	*/
		/* ---------------------------------------------------------------- */
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;


		protected :

			pointer	_ptr;


		public :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          CONSTRUCTORS                            */
		/*																	*/
		/* ---------------------------------------------------------------- */
		// default
			random_access_iterator() : _ptr(NULL) {}

		// by pointer
			random_access_iterator(pointer ptr) : _ptr(ptr) {}

		// copy
			random_access_iterator(const random_access_iterator & src) : _ptr(src._ptr) {}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          DESTRUCTOR                              */
		/*																	*/
		/* ---------------------------------------------------------------- */
			~random_access_iterator() {}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ASSIGN OPERATOR                         */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			random_access_iterator	& operator=(const random_access_iterator & rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			}

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          OVERLOAD OPERATORS                      */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// base
			const pointer	&base() const
			{
				return (this->_ptr);
			}

		// casting to const
			operator	random_access_iterator<const T>() const
			{
				return (this->_ptr);
			}

		// dereference
			reference	operator*() const
			{
				return (*this->_ptr);
			}

			pointer	operator->() const
			{
				return (&(operator*()));
			}

		// offset operator
			reference	operator[](difference_type n) const
			{
				return (this->_ptr[n]);
			}

		// pre-increment
			random_access_iterator	&operator++()
			{
				this->_ptr++;
				return (*this);
			}

		// post-increment
			random_access_iterator	operator++(int)
			{
				random_access_iterator	tmp(*this);
				operator++();
				return (tmp);
			}

		// pre-decrement
			random_access_iterator	&operator--()
			{
				this->_ptr--;
				return (*this);
			}

		// post-decrement
			random_access_iterator	operator--(int)
			{
				random_access_iterator	tmp(*this);
				operator--();
				return (tmp);
			}

		// arithmetic '+'
			random_access_iterator	operator+(difference_type n) const
			{
				return (random_access_iterator(this->_ptr + n));
			}

		// arithmetic '-'
			random_access_iterator	operator-(difference_type n) const
			{
				return (random_access_iterator(this->_ptr - n));
			}

		// assignment '+='
			random_access_iterator	&operator+=(difference_type n)
			{
				this->_ptr += n;
				return (*this);
			}

		// assignment '-='
			random_access_iterator	&operator-=(difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			}

	};

/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          COMPARISON OPERATORS                    */
/*                                                                  */
/* ---------------------------------------------------------------- */
// comparison '=='
	template <typename IteratorL, typename IteratorR>
	bool	operator==(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

// comparison '!='
	template <typename IteratorL, typename IteratorR>
	bool	operator!=(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

// comparison '<'
	template <typename IteratorL, typename IteratorR>
	bool	operator<(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

// comparison '>'
	template <typename IteratorL, typename IteratorR>
	bool	operator>(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

// comparison '<='
	template <typename IteratorL, typename IteratorR>
	bool	operator<=(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

// comparison '>='
	template <typename IteratorL, typename IteratorR>
	bool	operator>=(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

// arithmetic '+'
	template <typename Iterator>
	random_access_iterator<Iterator>	operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &rhs)
	{
		return (rhs.base() + n);
	}

// arithmetic '-'
	template <typename IteratorL, typename IteratorR>
	typename random_access_iterator<IteratorL>::difference_type	operator-(const random_access_iterator<IteratorL> &lhs, const random_access_iterator<IteratorR> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

}

#endif
