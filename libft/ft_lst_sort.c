/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:58:37 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/26 16:02:41 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_swap(t_list *list)
{
	void	*content;

	content = list->content;
	list->content = list->next->content;
	list->next->content = content;
}

int cmp(int s1, int s2)
{
	size_t i;

	i = 0;
	while (s1 || s2)
	{
		if (s1 != s2)
			return (s1 - s2);
		i++;
	}
	return (0);
}

void ft_lst_sort(t_list **begin)
{
	t_list *a;
	t_list *b;

	a = *begin;
	while (a != NULL)
	{
		b = *begin;
		while (b->next != NULL)
		{
			if (cmp(b->content, b->next->content) > 0)
				ft_lst_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}
