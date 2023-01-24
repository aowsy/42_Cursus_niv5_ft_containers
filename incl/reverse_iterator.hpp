/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:25:53 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/23 17:03:51 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_ITERATOR_HPP_
# define _REVERSE_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft
{

	template <class Iterator>
	class reverse_iterator
	{

		public :

			typedef				Iterator										iterator_type;
			typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename	iterator_traits<Iterator>::value_type			value_type;
			typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	iterator_traits<Iterator>::pointer				pointer;
			typedef typename	iterator_traits<Iterator>::reference			reference;

		protected :

			iterator_type	_current;

		public :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          CONSTRUCTORS                            */
		/*																	*/
		/* ---------------------------------------------------------------- */
		// default
			reverse_iterator() : _current(NULL) {}

		// initialisation
			explicit reverse_iterator(iterator_type it) : _current(it) {}

		// copy
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base()) {}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          DESTRUCTOR                              */
		/*																	*/
		/* ---------------------------------------------------------------- */
			~reverse_iterator() {}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ASSIGN OPERATOR                         */
		/*																	*/
		/* ---------------------------------------------------------------- */
			reverse_iterator	&operator=(const reverse_iterator &rhs)
			{
				this->_current = rhs._current;
				return (*this);
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          OVERLOAD OPERATORS                      */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// base
			iterator_type	base() const
			{
				return (this->_current);
			}

		// dereference '*'
			reference	operator*() const
			{
				iterator_type	tmp = this->_current;
				--tmp;
				return (*tmp);
			}

		// dereference '->'
			pointer	operator->() const
			{
				return (&(operator*()));
			}

		// offset operator
			reference	operator[](difference_type n) const
			{
				return (*(*this + n));
			}

		// pre-increment
			reverse_iterator &operator++()
			{
				this->_current--;
				return (*this);
			}

		// post-increment
			reverse_iterator	operator++(int)
			{
				reverse_iterator	tmp = *this;
				this->_current--;
				return (tmp);
			}

		// pre-decrement
			reverse_iterator	&operator--()
			{
				this->_current++;
				return (*this);
			}

		// post-decrement
			reverse_iterator	operator--(int)
			{
				reverse_iterator	tmp = *this;
				this->_current++;
				return (tmp);
			}

		// arithmetic '+'
			reverse_iterator	operator+(difference_type n) const
			{
				return (reverse_iterator(this->_current - n));
			}

		// arithmetic '-'
			reverse_iterator	operator-(difference_type n) const
			{
				return (reverse_iterator(this->_current + n));
			}

			difference_type	operator-(const reverse_iterator &rhs)
			{
				return (rhs._current.base() - this->_current.base());
			}

		// assignment '+='
			reverse_iterator	&operator+=(difference_type n)
			{
				this->_current -= n;
				return (*this);
			}

		// assignment '-='
			reverse_iterator	&operator-=(difference_type n)
			{
				this->_current += n;
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
	bool	operator==(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

// comparison '!='
	template <typename IteratorL, typename IteratorR>
	bool	operator!=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

// comparison '<'
	template <typename IteratorL, typename IteratorR>
	bool	operator<(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

// comparison '>'
	template <typename IteratorL, typename IteratorR>
	bool	operator>(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

// comparison '<='
	template <typename IteratorL, typename IteratorR>
	bool	operator<=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

// comparison '>='
	template <typename IteratorL, typename IteratorR>
	bool	operator>=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

// arithmetic '+'
	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rhs)
	{
		return (reverse_iterator<Iterator>(rhs.base() - n));
	}

// arithmetic '-'
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

}

#endif
