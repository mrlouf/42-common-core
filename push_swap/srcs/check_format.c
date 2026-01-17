/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:44:27 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/21 10:44:51 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	check_value(char *str)
{
	long long	tmp;

	tmp = ft_atoi(str);
	return (!(tmp > INT_MAX || tmp < INT_MIN));
}

void	check_double(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[++i + 1])
	{
		j = i;
		while (array[++j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				print_error();
		}
	}
}

int	check_format(char **array)
{
	int	i;
	int	j;

	i = 1;
	while (array[i])
	{
		j = 0;
		if ((array[i][j] == '-' || array[i][j] == '+') && j == 0)
		{
			if (ft_isdigit(array[i][j + 1]))
				j++;
			else
				print_error();
		}
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
				print_error();
			j++;
		}
		i++;
	}
	return (i);
}
