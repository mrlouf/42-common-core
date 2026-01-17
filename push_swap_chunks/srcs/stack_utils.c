/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:16:26 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/22 20:17:58 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*new_stack(int value)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->prev = NULL;
	new_stack->next = NULL;
	return (new_stack);
}

t_stack	*form_stack(int *array, int count)
{
	int		i;
	t_stack	*new;

	new = NULL;
	i = 0;
	while (i < count)
	{
		if (i > 0)
			stackadd_back(&new, new_stack(array[i]));
		else
			new = new_stack(array[i]);
		if (!new)
		{
			free(array);
			print_error();
		}
		i++;
	}
	free(array);
	return (new);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new || !stack)
		return ;
	tmp = stacklast(*stack);
	tmp->next = new;
	new->prev = tmp;
	return ;
}

t_stack	*stacklast(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
