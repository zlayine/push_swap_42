/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:23:05 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:36:24 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void	ft_stack_add(t_list **list, int item)
{
	t_list	*new;

	new = ft_lstnew(item);
	ft_lstadd_back(list, new);
}

t_list	*ft_lst_clone(t_list *list)
{
	t_list	*clone;

	clone = NULL;
	while (list)
	{
		if (!clone)
			clone = ft_lstnew(list->content);
		else
			ft_lstadd_back(&clone, ft_lstnew(list->content));
		list = list->next;
	}
	return (clone);
}

int	ft_lst_item_exist(t_list *stack, int num)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_bonus(char c)
{
	if (c == 'v' || c == 'c')
	{
		if (g_bonus != 0)
			g_bonus = 1;
		else
			g_bonus = c;
		return (1);
	}
	return (0);
}
