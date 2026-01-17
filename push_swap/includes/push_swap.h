/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:09:03 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/14 10:09:05 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// INPUT CHECK & BUILD STACK

int			*get_args(char **array, int size);
int			check_format(char **array);
int			check_value(char *str);
void		check_double(char **array);
t_stack		*form_stack(int *array, int count);
void		free_stack(t_stack *stack);
void		free_all(t_stack *stack_a, t_stack *stack_b);
void		print_error(void);
t_stack		*new_stack(int value);
void		stackadd_back(t_stack **stack, t_stack *new);
t_stack		*stacklast(t_stack *stack);
int			stack_size(t_stack *stack);

// MOVES

void		swap(t_stack **current);
void		swap_a(t_stack **current);
void		swap_b(t_stack **current);
void		swap_ab(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **from, t_stack **to);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **current);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b);
void		rotate_to_min(t_stack **stack_a);
void		rotate_to_max(t_stack **stack_a);
void		reverse(t_stack **current);
void		reverse_a(t_stack **stack_a);
void		reverse_b(t_stack **stack_b);
void		reverse_ab(t_stack **stack_a, t_stack **stack_b);

//	SORTING ALGO

int			is_sorted(t_stack **stack_a);
void		sort(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_big(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
int			locate_min(t_stack *stack_a);
int			locate_max(t_stack *stack_a);
int			cost_min(t_stack **stack_a);
int			cost_max(t_stack **stack_a);
void		stack_back(t_stack **stack_a, t_stack **stack_b);
t_stack		*ptr_to_min(t_stack *stack);
t_stack		*ptr_to_max(t_stack *stack);

#endif
