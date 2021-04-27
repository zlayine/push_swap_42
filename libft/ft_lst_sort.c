/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:58:37 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/27 14:15:55 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_swap_sort(t_list *list)
{
	int content;

	content = list->content;
	list->content = list->next->content;
	list->next->content = content;
}

int cmp(int s1, int s2)
{
	if (s1 != s2)
		return (s1 - s2);
	return (0);
}

t_list *ft_lst_sort(t_list *begin)
{
	t_list *a;
	t_list *b;

	a = begin;
	while (a)
	{
		b = begin;
		while (b->next)
		{
			if (cmp(b->content, b->next->content) > 0)
				ft_lst_swap_sort(b);
			b = b->next;
		}
		a = a->next;
	}
	return begin;
}
