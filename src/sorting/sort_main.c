/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:07:24 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:26:42 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks)
{
	if (stacks->size_a == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			sa(stacks, false);
	}
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else
		turk_sort(stacks);
}

void	sort_three(t_stacks *stacks)
{
	t_node	*biggest;

	biggest = find_max(stacks->a);
	if (biggest == stacks->a)
		ra(stacks, false);
	else if (stacks->a->next == biggest)
		rra(stacks, false);
	if (stacks->a->value > stacks->a->next->value)
		sa(stacks, false);
}
