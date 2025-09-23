/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:08:01 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:26:46 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = (i <= median);
		stack = stack->next;
		i++;
	}
}

void	analyze_nodes_a(t_stacks *stacks)
{
	set_positions(stacks->a);
	set_positions(stacks->b);
	set_targets_a_to_b(stacks);
	calculate_costs(stacks);
	mark_cheapest(stacks->a);
}

void	analyze_nodes_b(t_stacks *stacks)
{
	set_positions(stacks->a);
	set_positions(stacks->b);
	set_targets_b_to_a(stacks);
}
