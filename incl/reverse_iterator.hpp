/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:23:35 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/30 13:59:17 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "utils.hpp"

//Link: https://en.cppreference.com/w/cpp/iterator/reverse_iterator

namespace ft {

	template < typename Iterator >
	class reverse_iterator {

		public:

			typedef			 Iterator										iterator_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

		protected:

			iterator_type	current;
		
		public:

			/* Default constructor
			----------------------------------------------------------------------------- */
			reverse_iterator(void) : current() {}

			/* Copy constructor
			----------------------------------------------------------------------------- */
			explicit reverse_iterator(iterator_type it) : current(it) {}

			template<typename Iter>
			reverse_iterator(reverse_iterator<Iter> const &rev_it) : current(rev_it.base()) {}

			/* Default Destructor
			----------------------------------------------------------------------------- */
			virtual ~reverse_iterator(void) {}

			/* Base()
			----------------------------------------------------------------------------- */
			iterator_type base() const
			{
				return (this->current);
			}

			/* Casting to const
			----------------------------------------------------------------------------- */
			operator reverse_iterator<const Iterator>() const
			{
				return this->current;
			}

			/* Dereference operator
			----------------------------------------------------------------------------- */
			reference operator*() const
			{
				iterator_type tmp(this->current);
				return (*--tmp);
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			/* Pre and postfix Increment operators (++)
			----------------------------------------------------------------------------- */
			reverse_iterator &operator++()
			{
				--this->current;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				--this->current;
				return (tmp);
			}

			/* Pre and postfix Decrement operators (--)
			----------------------------------------------------------------------------- */
			reverse_iterator &operator--()
			{
				++this->current;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp(*this);
				++this->current;
				return (tmp);
			}

			/* Arithmetic operators (+ and -)
			----------------------------------------------------------------------------- */
			reverse_iterator operator+(difference_type n) const
			{
				return (reverse_iterator(this->current - n));
			}

			reverse_iterator operator-(difference_type n) const
			{
				return (reverse_iterator(this->current + n));
			}

			/* Compound assignment operations (+= and -=)
			----------------------------------------------------------------------------- */
			reverse_iterator &operator+=(difference_type n)
			{
				this->current -= n;
				return (*this);
			}

			reverse_iterator &operator-=(difference_type n)
			{
				this->current += n;
				return (*this);
			}

			/* Offset dereference operator ([])
			----------------------------------------------------------------------------- */
			reference operator[](difference_type n) const
			{
				return *(*this + n);
			}
	} ;

	/*  Relational operators (==, != <, >, <= and >=)
	----------------------------------------------------------------------------- */
	template < typename IteratorL, typename IteratorR >
	bool operator==(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template < typename IteratorL, typename IteratorR >
	bool operator!=(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template < typename IteratorL, typename IteratorR >
	bool operator<(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template < typename IteratorL, typename IteratorR >
	bool operator>(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template < typename IteratorL, typename IteratorR >
	bool operator<=(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template < typename IteratorL, typename IteratorR >
	bool operator>=(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	/* Arithmetic operators (+ and -)
	----------------------------------------------------------------------------- */
	template < typename Iterator >
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template < typename IteratorL, typename IteratorR >
	typename reverse_iterator<IteratorL>::difference_type operator-(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{
		return (rhs.base() - lhs.base());
	}

} // namespace

#endif

