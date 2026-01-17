/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:55:52 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/22 19:04:39 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	reverse(t_stack **current)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*current || !(*current)->next)
		return ;
	last = *current;
	while (last->next->next != NULL)
		last = last->next;
	tmp = *current;
	*current = last->next;
	last->next = NULL;
	(*current)->next = tmp;
}

void	reverse_a(t_stack **stack_a)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_b(t_stack **stack_b)
{
	reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
}
