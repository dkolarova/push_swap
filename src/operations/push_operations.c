/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:46:38 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:21 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		(*dest)->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stacks *stacks, bool silent)
{
	push_node(&stacks->a, &stacks->b);
	stacks->size_a++;
	stacks->size_b--;
	if (!silent)
		ft_printf("pa\n");
}

void	pb(t_stacks *stacks, bool silent)
{
	push_node(&stacks->b, &stacks->a);
	stacks->size_b++;
	stacks->size_a--;
	if (!silent)
		ft_printf("pb\n");
}
