/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:30:22 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/28 13:14:40 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main(void)
{
	t_list node1 = { "Node 1", NULL };
	t_list node2 = { "Node 2", NULL };

	t_list *head = &node1;
	ft_lstadd_front(&head, &node2);

	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)head->next->content);
} */