/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:20:41 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 12:19:59 by zlayine          ###   ########.fr       */
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
		ft_swapper(stack_a, stack_b, line);
	}
	if (ft_sorted(*stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!valid_args(argv))
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	stack_b = NULL;
	stack_a = ft_add_items(argc, argv);
	ft_checker(&stack_a, &stack_b);
	return (0);
}
