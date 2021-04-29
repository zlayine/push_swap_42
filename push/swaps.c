/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:20:28 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:15:05 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void	ft_swap_big(t_list **stack_a, t_list **stack_b)
{
	char	**mids;
	int		current;
	t_list	*tmp;
	int		size;

	mids = get_medians(*stack_a);
	tmp = *stack_a;
	ft_split_to_b(stack_a, stack_b, mids);
	while (!ft_sorted(*stack_a) || *stack_b)
	{
		size = ft_lstsize(*stack_a);
		if (ft_sorted(*stack_a) && *stack_b)
			ft_swap_from_b(stack_a, stack_b);
		else if (size <= 5)
			ft_swap_5(stack_a, stack_b);
		else
			minimize_a(stack_a, stack_b);
	}
	ft_del(mids);
}

void	ft_swap_5(t_list **stack_a, t_list **stack_b)
{
	int		mid;
	t_list	*tmp;

	mid = get_median(*stack_a);
	tmp = *stack_a;
	if (get_max_list(*stack_a) == 0)
		ft_swapper(stack_a, stack_b, RA);
	while (!ft_sorted(*stack_a) || *stack_b)
	{
		tmp = *stack_a;
		if (ft_lstsize(*stack_a) == 3)
		{
			*stack_a = ft_swap_3(*stack_a);
			ft_swap_2(stack_b, 1);
			ft_swapper(stack_a, stack_b, PA);
			ft_swapper(stack_a, stack_b, PA);
			break ;
		}
		else if (tmp->content < mid)
			ft_swapper(stack_a, stack_b, PB);
		else if (tmp->content > mid)
			ft_swapper(stack_a, stack_b, RA);
		else
			ft_swapper(stack_a, stack_b, SA);
	}
}

t_list	*ft_swap_3(t_list *stack)
{
	int	mid;
	int	last;

	if (ft_sorted(stack))
		return (stack);
	mid = stack->next->content;
	last = stack->next->next->content;
	if (stack->content < mid && stack->content < last && mid > last)
	{
		ft_swapper(&stack, NULL, SA);
		ft_swapper(&stack, NULL, RA);
	}
	else if (stack->content < mid && stack->content > last && mid > last)
		ft_swapper(&stack, NULL, RRA);
	else if (mid < last && last > stack->content)
		ft_swapper(&stack, NULL, SA);
	else if (mid < last)
		ft_swapper(&stack, NULL, RA);
	else
	{
		ft_swapper(&stack, NULL, SA);
		ft_swapper(&stack, NULL, RRA);
	}
	return (stack);
}

void	ft_swap_2(t_list **stack, int rev)
{
	if (ft_sorted(*stack) || rev)
		ft_swapper(stack, NULL, SA);
}
