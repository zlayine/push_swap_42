/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:23:54 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:24:35 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void	ft_lst_swap(t_list *a)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
}

void	ft_lst_move(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (a && *a)
	{
		tmp = (*a)->next;
		ft_lstadd_front(b, *a);
		*a = tmp;
	}
}

void	ft_lst_shift(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (stack && *stack)
	{
		last = ft_lstlast(*stack);
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		last->next = tmp;
	}
}

void	ft_lst_reshift(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	last = NULL;
	if (stack && *stack)
	{
		tmp = *stack;
		while (tmp->next)
		{
			if (tmp->next && !tmp->next->next)
			{
				last = tmp->next;
				tmp->next = NULL;
				break ;
			}
			tmp = tmp->next;
		}
		if (last)
			last->next = *stack;
		*stack = last;
	}
}

int	ft_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
