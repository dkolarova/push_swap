/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:07:00 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:26:26 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_stacks *stacks)
{
	t_node	*cheapest;

	cheapest = get_cheapest_node(stacks->a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stacks, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both(stacks, cheapest);
	finish_rotation_a(stacks, cheapest);
	finish_rotation_b(stacks, cheapest);
	pb(stacks, false);
}

static void	move_b_to_a(t_stacks *stacks)
{
	move_to_top(stacks, stacks->b->target, 'a');
	pa(stacks, false);
}

void	turk_sort(t_stacks *stacks)
{
	int	initial_size;

	initial_size = stacks->size_a;
	if (initial_size > 3 && !is_sorted(stacks->a))
		pb(stacks, false);
	if (initial_size > 3 && !is_sorted(stacks->a))
		pb(stacks, false);
	while (stacks->size_a > 3 && !is_sorted(stacks->a))
	{
		analyze_nodes_a(stacks);
		move_a_to_b(stacks);
	}
	sort_three(stacks);
	while (stacks->b)
	{
		analyze_nodes_b(stacks);
		move_b_to_a(stacks);
	}
	set_positions(stacks->a);
	move_min_to_top(stacks);
}
