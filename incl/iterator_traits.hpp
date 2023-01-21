/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:28:24 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/13 09:28:54 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_TRAITS_HPP_
# define _ITERATOR_TRAITS_HPP_

namespace ft
{

/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          ITERATOR TYPES                          */
/*																	*/
/* ---------------------------------------------------------------- */
// input
	struct input_iterator_tag {};
// output
	struct output_iterator_tag {};
// forward
	struct forward_iterator_tag : public input_iterator_tag {};
// bidirectionnal
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
// random access
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          ITERATOR CLASS                          */
/*																	*/
/* ---------------------------------------------------------------- */
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public :

			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;

	};


/* ---------------------------------------------------------------- */
/*                                                                  */
/*                          ITERATOR_TRAITS CLASS                   */
/*																	*/
/* ---------------------------------------------------------------- */
	template <class Iterator>
	class iterator_traits
	{

		public :

			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;

	};

	template <class T>
	class iterator_traits<T*>
	{

		public :

			typedef random_access_iterator_tag	iterator_category;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef T*							pointer;
			typedef T&							reference;

	};

	template <class T>
	class iterator_traits<const T*>
	{

		public :

			typedef random_access_iterator_tag	iterator_category;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef T*							pointer;
			typedef T&							reference;

	};

}

#endif
