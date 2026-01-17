/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:48:13 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 19:17:30 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T> T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T> void swap(T &a, T &b) // take the reference to do the swap
{
    T c = a;
	a = b;
	b = c;
}
