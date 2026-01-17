/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:08:34 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/15 18:55:41 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	*get_args(char **array, int size)
{
	int		*args;
	int		i;

	check_double(array);
	args = (int *)malloc(sizeof(int) * (size));
	if (!args)
		return (NULL);
	i = 0;
	while (++i <= size)
	{
		if (check_value(array[i]))
			args[i - 1] = ft_atoi(array[i]);
		else
		{
			free(args);
			print_error();
		}
	}
	return (args);
}
