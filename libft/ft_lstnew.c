/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:11:36 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/26 12:28:39 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*s_list_n;

	s_list_n = malloc(sizeof(t_list));
	if (s_list_n)
	{
		s_list_n->content = content;
		s_list_n->next = NULL;
	}
	return (s_list_n);
}
