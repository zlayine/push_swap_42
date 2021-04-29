/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:41:10 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:42:01 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*s_list;
	t_list	*temp;

	s_list = *lst;
	while (s_list)
	{
		temp = s_list->next;
		ft_lstdelone(s_list);
		s_list = temp;
	}
	*lst = NULL;
}
