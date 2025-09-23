/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:44:11 by dkolarov          #+#    #+#             */
/*   Updated: 2025/07/20 11:29:02 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putdec(unsigned int n, size_t *counter)
{
	int	count;

	count = 0;
	if (n >= 10)
		ft_putdec(n / 10, counter);
	ft_putchar((n % 10) + '0', counter);
	return (count);
}
