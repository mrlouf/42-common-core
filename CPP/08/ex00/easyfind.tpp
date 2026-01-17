/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:37:50 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/20 12:48:39 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <algorithm>
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &v, const int i)
{
	typename T::iterator it = v.begin();
	typename T::iterator end = v.end();
	typename T::iterator result = std::find(it, end, i); 
	if (result != end)
		return result;
	throw std::runtime_error("Element not found");
}
