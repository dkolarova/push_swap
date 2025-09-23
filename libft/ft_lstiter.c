/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:13:32 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/28 13:23:38 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst || !f)
		return ;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/* void	printf_content(void *content)
{
	printf("%s\n", (char *)content);
}

int main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(size_t));
		
	node1->content = "Hi";
	node2->content = "how are";
	node3->content = "you?";
	
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	ft_lstiter(node1, printf_content);
} */
