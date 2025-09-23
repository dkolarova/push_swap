/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:08:00 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:27:04 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(const char *str)
{
	long	num;
	int		i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1])
			return (false);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	num = ft_atoi(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

bool	has_duplicates(char **args)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (args[i])
	{
		num1 = ft_atoi(args[i]);
		j = i + 1;
		while (args[j])
		{
			num2 = ft_atoi(args[j]);
			if (num1 == num2)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	validate_input(char **args)
{
	int	i;

	if (!args || !args[0])
		return (false);
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			return (false);
		i++;
	}
	return (!has_duplicates(args));
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
