/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:14:12 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/25 18:43:18 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char			*str;
	const unsigned long	*lw_ptr;
	unsigned long		lw;

	str = s;
	while (((unsigned long)s & (sizeof(unsigned long) - 1)) != 0 && *s)
		s++;
	lw_ptr = (const unsigned long *)s;
	while (1)
	{
		lw = *lw_ptr;
		if (((lw - 0x0101010101010101UL) & ~lw & 0x8080808080808080UL) != 0)
		{
			s = (const char *)lw_ptr;
			while (*s)
				++s;
			return (s - str);
		}
		lw_ptr++;
	}
}
