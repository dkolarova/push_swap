/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:49:11 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:01 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->a;
	while (current)
	{
		current->cost = current->index;
		if (!current->above_median)
			current->cost = stacks->size_a - current->index;
		if (current->target->above_median)
			current->cost += current->target->index;
		else
			current->cost += stacks->size_b - current->target->index;
		current = current->next;
	}
}

void	mark_cheapest(t_node *stack)
{
	long	cheapest_cost;
	t_node	*cheapest_node;
	t_node	*current;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		if (current->cost < cheapest_cost)
		{
			cheapest_cost = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

t_node	*get_cheapest_node(t_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
