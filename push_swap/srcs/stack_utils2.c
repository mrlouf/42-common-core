/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:00:18 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/24 14:02:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	stack_size(t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
