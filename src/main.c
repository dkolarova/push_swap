/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:54:03 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:26:19 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	args = parse_arguments(argc, argv);
	if (!validate_input(args))
	{
		free_args(args);
		error_exit("Error");
	}
	stacks = init_stacks(args);
	if (!stacks)
	{
		free_args(args);
		error_exit("Error");
	}
	if (!is_sorted(stacks->a))
		sort_stack(stacks);
	cleanup_and_exit(stacks, args);
	return (0);
}
