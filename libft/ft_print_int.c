/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 07:25:27 by diana             #+#    #+#             */
/*   Updated: 2025/07/20 11:29:06 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint(int num, size_t *counter)
{
	char	*str;

	if (num < 0)
	{
		ft_putchar('-', counter);
		str = ft_extra((unsigned int)(-num), "0123456789");
	}
	else
	{
		str = ft_extra(num, "0123456789");
	}
	if (!str)
		return ;
	ft_putstr(str, counter);
	free(str);
}
