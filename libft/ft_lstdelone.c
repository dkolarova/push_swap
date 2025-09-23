/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:49:24 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/28 12:16:31 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del_funct(void *content)
{
	printf("Deleted: %s", (char *)content);
	free(content);
}

int	main(void)
{
	t_list *node = malloc(sizeof(t_list));
	node->content = malloc(15);
	node->next = NULL;

	char *str = "test content";
	for (int i = 0; i <= 12; i++) 
		((char *)node->content)[i] = str[i];

	node->next = NULL;

	ft_lstdelone(node, del_funct);

	return 0;
} */