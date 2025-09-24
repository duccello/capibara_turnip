/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:57:50 by duccello          #+#    #+#             */
/*   Updated: 2025/05/26 13:57:54 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!lst)
		return ;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}
