/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:20:28 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/30 16:44:09 by zlayine          ###   ########.fr       */
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
	ft_arr_del(mids);
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
}

void	ft_swap_5(t_list **stack_a, t_list **stack_b)
{
	int		mid;
	t_list	*tmp;

	mid = get_median(*stack_a);
	tmp = *stack_a;
	if (get_max_list(*stack_a) == 0)
		ft_swapper(stack_a, stack_b, RA, 1);
	while (!ft_sorted(*stack_a) || *stack_b)
	{
		tmp = *stack_a;
		if (ft_lstsize(*stack_a) == 3)
		{
			*stack_a = ft_swap_3(*stack_a, *stack_b);
			if (ft_lstsize(*stack_b) >= 2)
				ft_swap_2(stack_b, 0);
			ft_swapper(stack_a, stack_b, PA, 1);
			ft_swapper(stack_a, stack_b, PA, 1);
			break ;
		}
		else if (tmp->content < mid)
			ft_swapper(stack_a, stack_b, PB, 1);
		else
			ft_swapper(stack_a, stack_b, RA, 1);
	}
}

t_list	*ft_swap_3(t_list *stack_a, t_list *stack_b)
{
	int	mid;
	int	last;

	if (ft_sorted(stack_a))
		return (stack_a);
	mid = stack_a->next->content;
	last = stack_a->next->next->content;
	if (stack_a->content < mid && stack_a->content < last && mid > last)
	{
		ft_swapper(&stack_a, &stack_b, SA, 1);
		ft_swapper(&stack_a, &stack_b, RA, 1);
	}
	else if (stack_a->content < mid && stack_a->content > last && mid > last)
		ft_swapper(&stack_a, &stack_b, RRA, 1);
	else if (mid < last && last > stack_a->content)
		ft_swapper(&stack_a, &stack_b, SA, 1);
	else if (mid < last)
		ft_swapper(&stack_a, &stack_b, RA, 1);
	else
	{
		ft_swapper(&stack_a, &stack_b, SA, 1);
		ft_swapper(&stack_a, &stack_b, RRA, 1);
	}
	return (stack_a);
}

void	ft_swap_2(t_list **stack, int rev)
{
	if (!rev && (*stack)->content > (*stack)->next->content)
		return ;
	if (rev)
		ft_swapper(stack, NULL, SA, 1);
	else
		ft_swapper(NULL, stack, SB, 1);
}
