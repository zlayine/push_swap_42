/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:22:40 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:13:33 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

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

void	get_rot_less_med(t_list **stack, int med)
{
	int		i;
	int		size;
	t_list	*tmp;

	tmp = *stack;
	i = 0;
	size = ft_lstsize(*stack);
	while (tmp)
	{
		if (tmp->content < med)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
		rotate_stack_a(stack, RA, 0, i);
	else
		rotate_stack_a(stack, RRA, 1, i);
}
