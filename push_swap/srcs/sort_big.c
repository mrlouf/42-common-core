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

t_stack	*ptr_to_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min_ptr;
	long	min_val;

	tmp = stack;
	min_val = stack->value;
	min_ptr = tmp;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_ptr = tmp;
			min_val = tmp->value;
		}
		tmp = tmp->next;
	}
	return (min_ptr);
}

t_stack	*ptr_to_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max_ptr;
	long	max_val;

	tmp = stack;
	max_val = stack->value;
	max_ptr = stack;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_ptr = tmp;
			max_val = tmp->value;
		}
		tmp = tmp->next;
	}
	return (max_ptr);
}

/*	This function normalises the set of values in a stack; if the stack size is
	500, the value in each node will get replaced by 0-499 while retaining
	the same original order.		*/

void	normalise_stack(t_stack **stack_a, int size)
{
	int		i;
	t_stack	*min;
	t_stack	*max;

	i = 0;
	while (i < size)
	{
		min = ptr_to_min(*stack_a);
		min->value = LONG_MAX - (1 + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		max = ptr_to_max(*stack_a);
		max->value = i;
		i++;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	iterations;
	int	size;
	int	i;

	i = 0;
	size = stack_size(*stack_a);
	normalise_stack(stack_a, size);
	while (!is_sorted(stack_a))
	{
		iterations = 0;
		while (iterations < size && !is_sorted(stack_a))
		{
			iterations++;
			if ((((*stack_a)->value >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		while (stack_size(*stack_b) > 0)
			push_a(stack_a, stack_b);
		i++;
	}
}
