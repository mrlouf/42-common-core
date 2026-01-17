/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:08:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/15 18:53:49 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	int		*args;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 2)
	{
		size = check_format(av) - 1;
		args = get_args(av, size);
		stack_a = NULL;
		stack_b = NULL;
		stack_a = form_stack(args, size);
		sort(&stack_a, &stack_b, size);
		free_all(stack_a, stack_b);
	}
	else
		print_error();
	return (0);
}
