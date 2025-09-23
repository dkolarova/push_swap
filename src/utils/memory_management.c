/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:54:03 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:28:12 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(&stacks->a);
	free_stack(&stacks->b);
	free(stacks);
}

void	error_exit(const char *message)
{
	ft_putstr_fd((char *)message, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	cleanup_and_exit(t_stacks *stacks, char **args)
{
	free_stacks(stacks);
	free_args(args);
	exit(0);
}
