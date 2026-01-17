/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:53:23 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/22 18:38:00 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	rotate(t_stack **current)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*current || !(*current)->next)
		return ;
	tmp = *current;
	*current = (*current)->next;
	last = stacklast(*current);
	last->next = tmp;
	tmp->next = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
