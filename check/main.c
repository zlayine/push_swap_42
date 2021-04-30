/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:20:41 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 16:13:06 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		r;

	r = 1;
	while (r)
	{
		r = get_next_line(0, &line);
		if (r)
		{
			r = ft_swapper(stack_a, stack_b, line, 0);
			if (!r)
			{
				ft_del(line);
				return ;
			}
		}
		ft_del(line);
	}
	if (ft_sorted(*stack_a) && !*stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	g_bonus = 0;
	g_debug = 0;
	if (argc == 1)
		return (0);
	if (!valid_args(argv))
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	stack_b = NULL;
	stack_a = ft_add_items(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	ft_checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
