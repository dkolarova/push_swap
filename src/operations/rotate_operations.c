/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:38:07 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:25 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = get_last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stacks *stacks, bool silent)
{
	rotate_stack(&stacks->a);
	if (!silent)
		ft_printf("ra\n");
}

void	rb(t_stacks *stacks, bool silent)
{
	rotate_stack(&stacks->b);
	if (!silent)
		ft_printf("rb\n");
}

void	rr(t_stacks *stacks, bool silent)
{
	rotate_stack(&stacks->a);
	rotate_stack(&stacks->b);
	if (!silent)
		ft_printf("rr\n");
}
