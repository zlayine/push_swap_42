/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:22:40 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/28 13:32:45 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

int	arr_len(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	get_max_list(t_list *stack)
{
	int		counter;
	int		save;
	t_list	*tmp;
	t_list	*curr;

	counter = 0;
	save = 0;
	curr = stack;
	tmp = stack;
	while (tmp)
	{
		if (curr->content < tmp->content)
		{
			curr = tmp;
			save = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	return (save);
}

int	get_min_list(t_list *stack)
{
	int		counter;
	int		save;
	t_list	*tmp;
	t_list	*curr;

	counter = 0;
	save = 0;
	curr = stack;
	tmp = stack;
	while (tmp)
	{
		if (curr->content > tmp->content)
		{
			curr = tmp;
			save = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	return (save);
}
