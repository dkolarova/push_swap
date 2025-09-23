/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:31:01 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/27 17:46:58 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_to_trim(set, s1[i]))
		i++;
	while (ft_to_trim(set, s1[j]))
		j--;
	return (new_str(s1, i, j - (i - 1)));
}
	/*
     * i : the start index of the trimmed string in the full string
     * j : the end index of the trimmed string in the full string
     * Here what the values would be with the example I talked about
     * above.
     * s1 : "ababaaaMy name is Simonbbaaabbad"
     * ft_strlen(s1) : 33
     * after looping both ways, we have this :
     * i : 8
     * j : 23
     * but since we don't pass the end index, we pass the length of 
     * the new string we have to some "maths" 
     * j - (i - 1) : 23 - (8 - 1) = 23 - 7 = 16
     */
