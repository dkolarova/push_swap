/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:02:07 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:32:11 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_target_a_to_b(t_node *current_a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match;

	current_a = b;
	target = NULL;
	best_match = LONG_MAX;
	while (current_b)
	{
		if (current_b->value < current_a->value
			&& current_b->value > best_match)
		{
			best_match = current_b->value;
			target = current_b;
		}
		current_b = current_b->next;
	}
	if (best_match == LONG_MIN)
		return (find_max(b));
	return (target);
}

void	set_targets_a_to_b(t_stacks *stacks)
{
	t_node	*current_a;

	current_a = stacks->a;
	while (current_a)
	{
		current_a->target = find_target_a_to_b(current_a, stacks->b);
		current_a = current_a->next;
	}
}

static t_node	*find_target_b_to_a(t_node *current_b, t_node *a)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	current_a = a;
	target = NULL;
	best_match = LONG_MAX;
	while (current_a)
	{
		if (current_a->value > current_b->value
			&& current_a->value < best_match)
		{
			best_match = current_a->value;
			target = current_a;
		}
		current_a = current_a->next;
	}
	if (best_match == LONG_MAX)
		return (find_min(a));
	return (target);
}

void	set_targets_b_to_a(t_stacks *stacks)
{
	t_node	*current_b;

	current_b = stacks->b;
	while (current_b)
	{
		current_b->target = find_target_b_to_a(current_b, stacks->a);
		current_b = current_b->next;
	}
}
