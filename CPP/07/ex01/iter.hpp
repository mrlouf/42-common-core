/* ************************************************************************** */
#include <cstddef>
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:22:41 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 19:26:04 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

void negate(int &n)
{
    n = -n;
}

template <typename T, typename Func> void iter(T* array, size_t len, Func f)
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}
