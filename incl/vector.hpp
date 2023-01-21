/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:10:56 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/21 18:12:28 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

# include <iterator>
# include <stdexcept>
# include <algorithm>

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*							MEMBER TYPES                            */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			typedef				T												value_type;
			typedef				Alloc											allocator_type;
			typedef typename	allocator_type::reference						reference;
			typedef typename	allocator_type::const_reference					const_reference;
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			typedef typename	ft::random_access_iterator<value_type>			iterator;
			typedef typename	ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	iterator_traits<iterator>::difference_type		difference_type;
			typedef typename	allocator_type::size_type						size_type;



		private:

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ATTRIBUTES                              */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			allocator_type	_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_capacity;



		public:

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          CONSTRUCTORS                            */
		/*																	*/
		/* ---------------------------------------------------------------- */
		// default
			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}

		// fill
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
			{
				this->_ptr = _alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_capacity; i++)
					this->_alloc.construct(&this->_ptr[i], val);
			}

		// range
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) : _alloc(alloc)
			{
				size_type	tmp_size = 0;
				for (InputIterator i = first; i != last; i++)
					tmp_size++;
				this->_size = tmp_size;
				this->_capacity = this->_size;
				this->_ptr = _alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_capacity; i++)
					this->_alloc.construct(&this->_ptr[i], *first++);
			}

		// copy
			vector(const vector &x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
			{
				this->_ptr = _alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_capacity; i++)
					this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          DESTRUCTOR                              */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			~vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->_capacity);
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ASSIGN OPERATOR                         */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			vector	&operator=(const vector &x)
			{
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_ptr = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_capacity; i++)
					this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
				return (*this);
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ITERATORS                               */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// begin
			iterator	begin()
			{
				return (this->_ptr);
			}

			const_iterator	begin() const
			{
				return (this->_ptr);
			}

		// end
			iterator	end()
			{
				return (this->_ptr + this->_size);
			}

			const_iterator	end() const
			{
				return (this->_ptr + this->_size);
			}

		// reverse begin
			reverse_iterator	rbegin()
			{
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator	rbegin() const
			{
				return (reverse_iterator(this->end()));
			}

		// reverse end
			reverse_iterator	rend()
			{
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator	rend() const
			{
				return (reverse_iterator(this->begin()));
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          CAPACITY                                */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// size
			size_type	size() const
			{
				return (this->_size);
			}

		// max size
			size_type	max_size() const
			{
				return (this->_alloc.max_size());
			}

		// resize
			void	resize(size_type n, value_type val = value_type())
			{
				if (n == this->_size)
					return ;
				else if (n < this->_size)
					this->erase(this->begin() + n, this->end());
				else
				{
					if (this->_capacity < n)
						this->reserve(n);
					insert(this->end(), n - this->_size, val);
				}
			}

		// capacity
			size_type	capacity() const
			{
				return (this->_capacity);
			}

		// empty
			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			}

		// reserve
			void	reserve(size_type n)
			{
				if (n <= this->_capacity)
					return ;
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));

				size_type	tmp_size = this->_size;
				pointer		tmp_ptr = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&tmp_ptr[i], this->_ptr[i]);
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = tmp_ptr;
				this->_capacity = n;
				this->_size = tmp_size;
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          ELEMENT ACCESS                          */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// operator []
			reference	operator[](size_type n)
			{
				return (*(this->_ptr + n));
			}

			const_reference	operator[](size_type n) const
			{
				return (*(this->_ptr + n));
			}

		// at
			reference	at(size_type n)
			{
				if (n >= this->_size)
					throw (std::out_of_range("vector::at"));
				return (this->_ptr[n]);
			}

			const_reference	at(size_type n) const
			{
				if (n >= this->_size)
					throw (std::out_of_range("vector::at_const"));
				return (this->_ptr[n]);
			}

		// front
			reference	front()
			{
				return (this->_ptr[0]);
			}

			const_reference	front() const
			{
				return (this->_ptr[0]);
			}

		// back
			reference	back()
			{
				return (this->_ptr[this->_size - 1]);
			}

			const_reference	back() const
			{
				return (this->_ptr[this->_size - 1]);
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          MODIFIERS                               */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// assign
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
			{
				size_type	distance = 0;
				for (InputIterator i = first; i != last; i++)
					distance++;
				if (this->_capacity < distance)
					this->reserve(distance);
				this->clear();
				this->_size = distance;
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&this->_ptr[i], *first);
					first++;
				}
			}

			void	assign(size_type n, const value_type &val)
			{
				this->clear();
				this->_size = n;
				if (this->_size > this->_capacity)
				{
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_capacity = this->_size;
					this->_ptr = this->_alloc.allocate(this->_capacity);
				}
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_ptr[i], val);
			}

		// push back
			void	push_back(const value_type &val)
			{
				if (this->_capacity == 0)
					this->reserve(1);
				else if (this->_size == this->_capacity)
					this->reserve(this->_capacity * 2);
				this->_alloc.construct(&this->_ptr[this->_size], val);
				this->_size++;
			}


		// pop back
			void	pop_back()
			{
				if (this->_size > 0)
					this->_alloc.destroy(&this->_ptr[this->_size - 1]);
				this->_size--;
			}

		// insert
			iterator	insert(iterator position, const value_type &val)
			{
				if (this->_capacity == 0)
					this->reserve(1);
				else if (this->_size == this->_capacity)
					this->reserve(this->_capacity * 2);

				for (size_type i = this->_size - 1; &this->_ptr[i] >= &(*position); i--)
				{
					this->_alloc.construct(&this->_ptr[i + 1], this->_ptr[i]);
					this->_alloc.destroy(&this->_ptr[i]);
				}

				this->_alloc.construct(&(*position), val);
				this->_size++;
				return (this->_ptr);
			}

			void	insert(iterator position, size_type n, const value_type &val)
			{
				size_type	distance = 0;
				for (iterator i = this->begin(); i != position; i++)
					distance++;

				if (this->_size + n > this->_capacity)
					this->reserve(this->_size + n);

				if (this->_size == 0)
				{
					for (size_type i = 0; i < n; i++)
						this->_alloc.construct(&this->_ptr[i], val);
				}

				else
				{
					for (size_type i = this->_size - 1; i > distance; i--)
					{
						this->_alloc.construct(&this->_ptr[i] + n, this->_ptr[i]);
						this->_alloc.destroy(&this->_ptr[distance]);
					}
					for (size_type i = 0; i < n; i++)
						this->_alloc.construct(&this->_ptr[distance + i], val);
				}
				this->_size += n;
			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
			{
				size_type	distance = 0;
				for (InputIterator i = first; i != last; i++)
					distance++;
				size_type	index = 0;
				for (iterator i = this->begin(); i != position; i++)
					index++;

				if (this->_size + distance > this->_capacity)
					this->reserve(this->_size + distance);

				iterator	new_pos = this->begin() + index;
				for (size_type i = 0; i < this->_size - index; i++)
				{
					this->_alloc.construct(&this->_ptr[this->_size + distance - i], this->_ptr[this->_size - i - 1]);
					this->_alloc.destroy(&this->_ptr[this->_size - i - 1]);
				}
				while (first < last)
				{
					this->_alloc.construct(&(*new_pos), *(&(*first)));
					first++;
					new_pos++;
				}
				this->_size += distance;
			}

		// erase
			iterator	erase(iterator position)
			{
				iterator	rtn_iter = position;

				while (position < this->end())
				{
					this->_alloc.destroy(&(*position));
					this->_alloc.construct(&(*position), *(position + 1));
					position++;
				}
				this->_alloc.destroy(&(*position));
				this->_size--;
				return (rtn_iter);
			}

			iterator	erase(iterator first, iterator last)
			{
				iterator	rtn_iter = first;
				size_type	distance = 0;

				for (iterator i = first; i != last; i++)
					distance++;
				while (last > first)
				{
					for (iterator tmp_itr = first; tmp_itr < this->end(); tmp_itr++)
					{
						this->_alloc.destroy(&(*tmp_itr));
						this->_alloc.construct(&(*tmp_itr), *(tmp_itr + 1));
					}
					last--;
				}
				this->_size -= distance;
				return (rtn_iter);
			}

		// swap
			void	swap(vector &x)
			{
				allocator_type	tmp_alloc;
				pointer			tmp_ptr;
				size_type		tmp_size;
				size_type		tmp_capacity;

				tmp_alloc = x._alloc;
				tmp_ptr = x._ptr;
				tmp_size = x._size;
				tmp_capacity = x._capacity;

				x._alloc = this->_alloc;
				x._ptr = this->_ptr;
				x._size = this->_size;
				x._capacity = this->_capacity;

				this->_alloc = tmp_alloc;
				this->_ptr = tmp_ptr;
				this->_size = tmp_size;
				this->_capacity = tmp_capacity;
			}

		// clear
			void	clear()
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_size = 0;
			}


		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          GET_ALLOCATOR                           */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// get allocator
			allocator_type	get_allocator() const
			{
				return (this->_alloc);
			}



		private :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*                          OVERLOAD OPERATORS                      */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
		// comparison '=='
			template <class T2, class Alloc2>
			friend bool	operator==(const vector<T2, Alloc2> &lhs, const vector<T2, Alloc2> &rhs);

		// comparison '!='
			template <class T2, class Alloc2>
			friend bool	operator!=(const vector<T2, Alloc2> &lhs, const vector<T2, Alloc2> &rhs);

		// comparison '<'
			template <class T2, class Alloc2>
			friend bool	operator<(const vector<T2, Alloc2> &lhs, const vector<T2, Alloc2> &rhs);

		// comparison '<='
			template <class T2, class Alloc2>
			friend bool	operator<=(const vector<T2, Alloc2> &lhs, const vector<T2, Alloc2> &rhs);

		// comparison '>'
			template <class T2, class Alloc2>
			friend bool	operator>(const vector<T2, Alloc2> &lhs, const vector<T2, Alloc2> &rhs);

		// comparison '>='
			template <class T2, class Alloc2>
			friend bool	operator>=(const vector<T2, Alloc2> &lhs, const vector<T2, Alloc2> &rhs);

	};


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          COMPARISON OPERATORS                    */
/*                                                                  */
/* ---------------------------------------------------------------- */
// comparison '=='
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

// comparison '!='
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

// comparison '<'
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

// comparison '<='
	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

// comparison '>'
	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

// comparison '>='
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

}

#endif
