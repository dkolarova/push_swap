/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:24:07 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:26:48 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stacks *stacks, t_node *node, char stack_name)
{
	if (stack_name == 'a')
	{
		while (stacks->a != node)
		{
			if (node->above_median)
				ra(stacks, false);
			else
				rra(stacks, false);
		}
	}
	else if (stack_name == 'b')
	{
		while (stacks->b != node)
		{
			if (node->above_median)
				rb(stacks, false);
			else
				rrb(stacks, false);
		}
	}
}

void	rotate_both(t_stacks *stacks, t_node *cheapest)
{
	while (stacks->b != cheapest->target && stacks->a != cheapest)
		rr(stacks, false);
	set_positions(stacks->a);
	set_positions(stacks->b);
}

void	rev_rotate_both(t_stacks *stacks, t_node *cheapest)
{
	while (stacks->b != cheapest->target && stacks->a != cheapest)
		rrr(stacks, false);
	set_positions(stacks->a);
	set_positions(stacks->b);
}

void	finish_rotation_a(t_stacks *stacks, t_node *cheapest)
{
	move_to_top(stacks, cheapest, 'a');
}

void	finish_rotation_b(t_stacks *stacks, t_node *cheapest)
{
	move_to_top(stacks, cheapest->target, 'b');
}
