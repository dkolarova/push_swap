/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:11:07 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:27 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stacks *stacks, bool silent)
{
	swap_stack(&stacks->a);
	if (!silent)
		ft_printf("sa\n");
}

void	sb(t_stacks *stacks, bool silent)
{
	swap_stack(&stacks->b);
	if (!silent)
		ft_printf("sb\n");
}

void	ss(t_stacks *stacks, bool silent)
{
	swap_stack(&stacks->a);
	swap_stack(&stacks->b);
	if (!silent)
		ft_printf("ss\n");
}
