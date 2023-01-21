/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:52:57 by mdelforg          #+#    #+#             */
/*   Updated: 2023/01/15 15:02:47 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _map_HPP_
# define _map_HPP_

namespace ft
{

	template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key, T> > >
	class map
	{

		public :

		/* ---------------------------------------------------------------- */
		/*                                                                  */
		/*							MEMBER TYPES                            */
		/*                                                                  */
		/* ---------------------------------------------------------------- */
			typedef				Key									key_type;
			typedef				T									mapped_type;
			typedef				pair<const key_type, mapped_type>	value_type;
			typedef				Compare								key_compare;
			typedef				Alloc								allocator_type;
			typedef	typename	allocator_type::reference			reference;
			typedef	typename	allocator_type::const_reference		const_reference;
			typedef	typename	allocator_type::pointer				pointer;
			typedef	typename	allocator_type::const_pointer		const_pointer;







	}


}

#endif
