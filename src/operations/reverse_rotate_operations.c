/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:07:09 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:23 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stacks *stacks, bool silent)
{
	reverse_rotate_stack(&stacks->a);
	if (!silent)
		ft_printf("rra\n");
}

void	rrb(t_stacks *stacks, bool silent)
{
	reverse_rotate_stack(&stacks->b);
	if (!silent)
		ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks, bool silent)
{
	reverse_rotate_stack(&stacks->a);
	reverse_rotate_stack(&stacks->b);
	if (!silent)
		ft_printf("rrr\n");
}
