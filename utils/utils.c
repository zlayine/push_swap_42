/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:20:23 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:36:14 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

int	ft_swapper_a(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, SA))
		ft_lst_swap(*stack_a);
	else if (!ft_strcmp(action, PA))
		ft_lst_move(stack_b, stack_a);
	else if (!ft_strcmp(action, RA))
		ft_lst_shift(stack_a);
	else if (!ft_strcmp(action, RRA))
		ft_lst_reshift(stack_a);
	else
		return (0);
	return (1);
}

int	ft_swapper_b(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, SB))
		ft_lst_swap(*stack_b);
	else if (!ft_strcmp(action, PB))
		ft_lst_move(stack_a, stack_b);
	else if (!ft_strcmp(action, RB))
		ft_lst_shift(stack_b);
	else if (!ft_strcmp(action, RRB))
		ft_lst_reshift(stack_b);
	else
		return (0);
	return (1);
}

void	print_color(char *action)
{
	if (ft_strchr(action, 's'))
		ft_putstr("\033[32m");
	else if (ft_strchr(action, 'p'))
		ft_putstr("\033[35m");
	else if (ft_strchr(action, 'r'))
		ft_putstr("\033[36m");
	ft_putendl_fd(action, 1);
	ft_putstr("\e[0m");
}

void	ft_swapper(t_list **stack_a, t_list **stack_b, char *action)
{
	if (ft_swapper_a(stack_a, stack_b, action)
		|| ft_swapper_b(stack_a, stack_b, action))
		ft_putstr("");
	else
	{
		ft_putendl_fd("Error", 1);
		return ;
	}
	if (g_bonus == 'c' || g_bonus == 1)
		print_color(action);
	else
		ft_putendl_fd(action, 1);
	if (g_bonus == 'v' || g_bonus == 1)
	{
		if (!stack_a)
			print_stacks(NULL, *stack_b);
		else if (!stack_b)
			print_stacks(*stack_a, NULL);
		else
			print_stacks(*stack_a, *stack_b);
	}
}

t_list	*ft_add_items(int total, char **argv)
{
	int		i;
	t_list	*stack;

	i = 0;
	stack = NULL;
	while (++i < total)
	{
		if ((ft_strchr(argv[i], ' ') && !add_numbers(&stack, argv[i])))
		{
			ft_lstclear(&stack);
			return (NULL);
		}
		else if (!add_number(&stack, argv[i]))
		{
			ft_lstclear(&stack);
			return (NULL);
		}
	}
	return (stack);
}
