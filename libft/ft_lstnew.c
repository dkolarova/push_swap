/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:07:00 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/27 18:29:58 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/* int main(void)
{
	char *data = "Hola, amigo";
	t_list *node = ft_lstnew(data);

	if (!node)
	{
		printf("Test failed: node is NULL\n");
		return (1);
	}
	if (node->content != data)
	{
		printf("Test failed: content does not match\n");
		free(node);
		return (1);
	}
	if (node->next != NULL)
	{
		printf("Test failed: next is not NULL\n");
		free(node);
		return (1);
	}

	printf("Test passed:\n");
	printf("  content: %s\n", (char *)node->content);
	printf("  next: %p\n", (void *)node->next);

	free(node);
	return (0);
} */