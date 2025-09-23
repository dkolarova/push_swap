/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:18:33 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/28 17:42:45 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/* int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = malloc(10);
	node2->content = malloc(20);
	node3->content = malloc(30);

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	t_list *head = node1;

	ft_lstclear(&head, free);

	if (head == NULL)
		printf("List cleared successfully.\n");
	else
		printf("List not cleared.\n");

	return 0;
} */