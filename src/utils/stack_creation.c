/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:54:03 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:28:00 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->next = NULL;
	node->prev = NULL;
	node->target = NULL;
	return (node);
}

void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new_node;
	new_node->prev = last;
}

t_stacks	*init_stacks(char **args)
{
	t_stacks	*stacks;
	t_node		*node;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	i = 0;
	while (args[i])
	{
		node = create_node(ft_atoi(args[i]));
		if (!node)
		{
			free_stacks(stacks);
			return (NULL);
		}
		add_node_back(&stacks->a, node);
		stacks->size_a++;
		i++;
	}
	return (stacks);
}
