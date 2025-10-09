/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:08:00 by dkolarov          #+#    #+#             */
/*   Updated: 2025/10/09 06:34:09 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
bool	is_valid_format(const char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[++i])
			return (false);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_number(const char *str)
{
	int		i;
	int		sign;
	long	num;

	if (!is_valid_format(str))
		return (false);
	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > (long)INT_MAX + 1))
			return (false);
		i++;
	}
	return (true);
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
