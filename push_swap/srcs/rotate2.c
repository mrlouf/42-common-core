/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:42:13 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/23 14:43:04 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/*	Returns the position of the min element of the stack, (0) if first	*/

int	locate_min(t_stack *stack_a)
{
	int		tmp;
	int		i;
	int		pos;
	int		size;

	i = 1;
	pos = 0;
	tmp = stack_a->value;
	size = stack_size(stack_a);
	stack_a = stack_a->next;
	while (i < size)
	{
		if (tmp > stack_a->value)
		{
			tmp = stack_a->value;
			pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (pos);
}

/*	Returns the position of the max element of the stack, (0) if first	*/

int	locate_max(t_stack *stack_a)
{
	int		tmp;
	int		i;
	int		pos;
	int		size;

	i = 1;
	pos = 0;
	tmp = stack_a->value;
	size = stack_size(stack_a);
	stack_a = stack_a->next;
	while (i < size)
	{
		if (tmp < stack_a->value)
		{
			tmp = stack_a->value;
			pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (pos);
}

/*	Rotate the min/max number to the top of the stack, or reverse if
	less costly in movements.	*/

void	rotate_to_min(t_stack **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	while (locate_min(*stack_a) != 0)
	{
		if (locate_min(*stack_a) <= (size / 2))
			rotate_a(stack_a);
		else if (locate_min(*stack_a) > (size / 2)
			|| (locate_min(*stack_a) == 3 && size == 5))
			reverse_a(stack_a);
	}
}

void	rotate_to_max(t_stack **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	while (locate_max(*stack_a) != 0)
	{
		if (locate_max(*stack_a) <= (size / 2))
			rotate_a(stack_a);
		else if (locate_max(*stack_a) > (size / 2)
			|| (locate_max(*stack_a) == 3 && size == 5))
			reverse_a(stack_a);
	}
}
