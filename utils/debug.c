/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:25:18 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 13:15:43 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void	print_stacks(t_list *a, t_list *b)
{
	char	*str;

	ft_putstr("--------------------\n");
	ft_putstr("a => ");
	while (a)
	{
		str = ft_itoa(a->content);
		ft_putstr(str);
		ft_putstr(" ");
		ft_del(str);
		a = a->next;
	}
	ft_putstr("\nb => ");
	while (b)
	{
		str = ft_itoa(b->content);
		ft_putstr(str);
		ft_putstr(" ");
		ft_del(str);
		b = b->next;
	}
	ft_putstr("\n--------------------\n");
}

void	debug(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		r;

	r = 1;
	print_stacks(*stack_a, *stack_b);
	while (r)
	{
		r = get_next_line(0, &line);
		ft_swapper(stack_a, stack_b, line, 0);
		print_stacks(*stack_a, *stack_b);
	}
}
