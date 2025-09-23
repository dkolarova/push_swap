/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:19:31 by diana             #+#    #+#             */
/*   Updated: 2025/07/20 11:42:24 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned long long n, char *base)
{
	size_t					len;
	unsigned long long		base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_extra(unsigned long long n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putint(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putdec(va_arg(va, unsigned int), counter);
	else if (*str == 'x')
		ft_puthex(va_arg(va, unsigned int), counter, HEX_LOWER_BASE);
	else if (*str == 'X')
		ft_puthex(va_arg(va, unsigned int), counter, HEX_UPPER_BASE);
	else if (*str == '%')
		ft_putchar('%', counter);
}

int	ft_printf(char const *str, ...)
{
	va_list			va;
	size_t			counter;

	counter = 0;
	if (!str)
		return (0);
	va_start(va, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else
			ft_putchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}

/* int main(void)
{
	int count = ft_printf(" %p %p ", 0, 0);
	printf(" %p %p ", (void *)0, (void *)0);
	write(1, "\n", 1);
	ft_printf("Return value: %d\n", count);
	return (0);
}  */
/* int	main(void)
{
	int	count;

	count = ft_printf("Hola como esta todo?\n");
	ft_printf("printed chars %d\n", count);
	
	ft_printf("char: %c\n", 'a');
	ft_printf("string: %s\n", "holis tu");
	ft_printf(" %p %p \n", 0, 0);
	ft_printf("pointer: %p\n", (void *)0x1234abcd);
	ft_printf("int: %d\n", 30);
	ft_printf("negative int: %d\n", -22);
	ft_printf("unsigned: %u\n", 455);
	ft_printf("hex lowe: %x\n", 255);
	ft_printf("hex upper: %X\n", 233);
	ft_printf("sign: %%\n");
} */