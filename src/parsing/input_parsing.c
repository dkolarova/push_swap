/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:10:28 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:15 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_single_argument(char *arg)
{
	return (ft_split(arg, ' '));
}

static char	**copy_multiple_arguments(int argc, char **argv)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * argc);
	if (!args)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_strdup(argv[i + 1]);
		if (!args[i])
		{
			while (--i >= 0)
				free(args[i]);
			free(args);
			return (NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}

char	**parse_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!argv[1][0])
			return (NULL);
		return (split_single_argument(argv[1]));
	}
	else
		return (copy_multiple_arguments(argc, argv));
}
