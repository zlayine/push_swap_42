/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:41:56 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 13:12:28 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void	rotate_stack_a(t_list **stack, char *action, int direction, int counter)
{
	if (direction > 0)
		while (counter++ < ft_lstsize(*stack))
			ft_swapper(stack, NULL, action, 1);
	else
		while (counter--)
			ft_swapper(stack, NULL, action, 1);
}

void	rotate_stack_b(t_list **stack, char *action, int direction, int counter)
{
	if (direction > 0)
		while (counter++ < ft_lstsize(*stack))
			ft_swapper(NULL, stack, action, 1);
	else
		while (counter--)
			ft_swapper(NULL, stack, action, 1);
}
