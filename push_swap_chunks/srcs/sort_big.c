/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:11:40 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/24 17:36:40 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*	These functions compare the cost of rotating/reverting the min or the max value
	to the top before pushing it to stack b, choosing the less costly move.
	This is done by checking which number is the closest to the middle of the stack,
	indicating a costly move (the closer to the beginning or end, the cheapest.	*/

int		cost_min(t_stack **stack_a)
{
	int	cost;
	int	size;
	
	size = stack_size(*stack_a);
	cost = (size / 2) - locate_min(*stack_a);
	if (cost < 0)
		cost = -cost;
	return (cost);
}

int		cost_max(t_stack **stack_a)
{
	int	cost;
	int	size;
	
	size = stack_size(*stack_a);
	cost = (size / 2) - locate_max(*stack_a);
	if (cost < 0)
		cost = -cost;
	return (cost);
}

void	stack_back(t_stack **stack_a, t_stack **stack_b)
{
	push_a(stack_a, stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->value > (*stack_a)->value)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else
			push_a(stack_a, stack_b);
	}
}

/*	Note: with these functions, a high value of cost indicates a cheap move.
	For example, cost_min of 5 on a stack of 10 means it is either at the beginning
	or the end.			*/

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 0)
	{
		if ((cost_min(stack_a) - 1) > cost_max(stack_a))
		{
			rotate_to_min(stack_a);
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else
		{
			rotate_to_max(stack_a);
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
	}
	stack_back(stack_a, stack_b);
}
