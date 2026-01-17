/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:28:06 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/22 15:44:34 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	swap(t_stack **current)
{
	int	tmp;

	if (!*current || !(*current)->next)
		return ;
	tmp = (*current)->value;
	(*current)->value = (*current)->next->value;
	(*current)->next->value = tmp;
}

void	swap_a(t_stack **current)
{
	swap(current);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **current)
{
	swap(current);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
