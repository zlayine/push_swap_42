/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:22:11 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/28 13:32:10 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

int	get_median(t_list *stack)
{
	t_list	*new;
	t_list	*tmp;
	int		size;
	int		res;

	new = ft_lst_clone(stack);
	tmp = ft_lst_sort(new);
	size = ft_lstsize(tmp) / 2;
	while (size--)
		tmp = tmp->next;
	res = tmp->content;
	ft_lstclear(&new);
	return (res);
}

int	*fetch_medians(t_list *stack, int size, int total)
{
	int		i;
	int		save;
	int		*medians;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	save = size;
	medians = malloc(sizeof(int) * (total + 1));
	while (i < total - 1 && tmp->next)
	{
		size = save;
		while (size-- && tmp->next)
			tmp = tmp->next;
		medians[i] = tmp->content;
		i++;
	}
	medians[i] = 0;
	return (medians);
}

int	*get_medians(t_list *stack)
{
	t_list	*new;
	t_list	*tmp;
	int		size;
	int		*medians;

	new = ft_lst_clone(stack);
	tmp = ft_lst_sort(new);
	size = ft_lstsize(tmp);
	if (size <= 20)
		medians = fetch_medians(tmp, size / 2, 2);
	else if (size <= 100)
		medians = fetch_medians(tmp, size / 5, 5);
	else if (size > 100)
		medians = fetch_medians(tmp, size / 12, 12);
	ft_lstclear(&new);
	return (medians);
}
