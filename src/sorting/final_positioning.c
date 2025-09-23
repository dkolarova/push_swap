/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_positioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:54:07 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:26:57 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stacks *stacks)
{
	t_node	*min_node;

	min_node = find_min(stacks->a);
	if (min_node->above_median)
	{
		while (stacks->a != min_node)
			ra(stacks, false);
	}
	else
	{
		while (stacks->a != min_node)
			rra(stacks, false);
	}
}
