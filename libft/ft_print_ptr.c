/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 07:11:43 by diana             #+#    #+#             */
/*   Updated: 2025/07/20 11:29:16 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr, size_t *counter)
{
	char				*str;
	uintptr_t			ptr_address;

	if (ptr == NULL)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	ptr_address = (uintptr_t)ptr;
	str = ft_extra((unsigned long long)ptr_address, HEX_LOWER_BASE);
	if (!str)
		return ;
	ft_putstr("0x", counter);
	ft_putstr(str, counter);
	free(str);
}
