/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:45:57 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/18 14:31:34 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP_
# define _STACK_HPP_

# include "vector.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> >
	class stack
	{

		public :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*							MEMBER TYPES                            */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;



		protected :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ATTRIBUTES                              */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			container_type	c_;



		public :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          CONSTRUCTOR                             */
		/*																	*/
		/* ---------------------------------------------------------------- */
		// default
			explicit stack(const container_type &ctnr = container_type()) : c_(ctnr) {}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          DESTRUCTOR                              */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			~stack() {}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          MEMBER FUNCTIONS                        */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// empty
			bool	empty() const
			{
				return (this->c_.empty());
			}

		// size
			size_type	size() const
			{
				return (this->c_.size());
			}

		// top
			value_type	&top()
			{
				return (this->c_.back());
			}

			const value_type	&top() const
			{
				return (this->c_.back());
			}

		// push
			void	push(const value_type &val)
			{
				this->c_.push_back(val);
			}

		// pop
			void	pop()
			{
				this->c_.pop_back();
			}


		private :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          OVERLOAD OPERATORS                      */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// comparison '=='
			template <class T2, class Container2>
				friend bool	operator==(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs);

		// comparison '!='
			template <class T2, class Container2>
				friend bool	operator!=(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs);

		// comparison '<'
			template <class T2, class Container2>
				friend bool	operator<(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs);

		// comparison '<='
			template <class T2, class Container2>
				friend bool	operator<=(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs);

		// comparison '>'
			template <class T2, class Container2>
				friend bool	operator>(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs);

		// comparison '>='
			template <class T2, class Container2>
				friend bool	operator>=(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs);

	};

/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          COMPARISON OPERATORS                    */
/*                                                                  */
/* ---------------------------------------------------------------- */
// comparison '=='
	template <class T, class Container>
	bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c_ == rhs.c_);
	}

// comparison '!='
	template <class T, class Container>
	bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c_ != rhs.c_);
	}

// comparison '<'
	template <class T, class Container>
	bool	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c_ < rhs.c_);
	}

// comparison '<='
	template <class T, class Container>
	bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c_ <= rhs.c_);
	}

// comparison '>'
	template <class T, class Container>
	bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c_ > rhs.c_);
	}

// comparison '>='
	template <class T, class Container>
	bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c_ >= rhs.c_);
	}

}

#endif
