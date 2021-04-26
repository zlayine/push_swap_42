/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:32 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/26 16:00:28 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

t_list *ft_swap_3(t_list *stack)
{
	t_list *mid;
	t_list *last;

	if (ft_sorted(stack))
		return stack;
	mid = stack->next;
	last = mid->next;
	// if (stack->content < mid->content)
	// {
	// 	if (stack->content < last->content && mid->content > last->content)
	// 	{
	// 		ft_swapper(&stack, NULL, SA);
	// 		ft_swapper(&stack, NULL, RA);
	// 	}
	// 	else if (stack->content > last->content && mid->content > last->content)
	// 		ft_swapper(&stack, NULL, RRA);
	// }
	// else
	// {
	// 	if (mid->content < last->content && last->content > stack->content)
	// 		ft_swapper(&stack, NULL, SA);
	// 	else if (mid->content < last->content)
	// 		ft_swapper(&stack, NULL, RA);
	// 	else
	// 	{
	// 		ft_swapper(&stack, NULL, SA);
	// 		ft_swapper(&stack, NULL, RRA);
	// 	}
	// }
	if (stack->content < mid->content && stack->content < last->content && mid->content > last->content)
	{
		ft_swapper(&stack, NULL, SA);
		ft_swapper(&stack, NULL, RA);
	}
	else if (stack->content < mid->content && stack->content > last->content && mid->content > last->content)
		ft_swapper(&stack, NULL, RRA);
	else if (mid->content < last->content && last->content > stack->content)
		ft_swapper(&stack, NULL, SA);
	else if (mid->content < last->content)
		ft_swapper(&stack, NULL, RA);
	else
	{
		ft_swapper(&stack, NULL, SA);
		ft_swapper(&stack, NULL, RRA);
	}

	return stack;
}

void ft_swap_2(t_list **stack, int rev)
{
	if (ft_sorted(*stack) || rev)
		ft_swapper(stack, NULL, SA);
}

int get_median(t_list *stack)
{
	t_list *new;
	t_list *tmp;
	int size;

	new = ft_lst_clone(stack);
	tmp = ft_lst_sort(new);
	size = ft_lstsize(tmp) / 2;
	while (size--)
		tmp = tmp->next;
	return tmp->content;
}

void ft_swap_5(t_list **stack_a, t_list **stack_b)
{
	int mid;
	t_list *tmp;

	mid = get_median(*stack_a);
	tmp = *stack_a;
	while (!ft_sorted(*stack_a) || *stack_b)
	{
		// print_stacks(*stack_a, *stack_b);
		tmp = *stack_a;
		if (ft_lstsize(*stack_a) == 3)
		{
			*stack_a = ft_swap_3(*stack_a);
			ft_swap_2(stack_b, 0);
			ft_swapper(stack_a, stack_b, PA);
			ft_swapper(stack_a, stack_b, PA);
			if (!ft_sorted(*stack_a))
				ft_swapper(stack_a, NULL, SA);
			break;
		}
		else if (tmp->content < mid)
			ft_swapper(stack_a, stack_b, PB);
		else if (tmp->content > mid)
			ft_swapper(stack_a, stack_b, RRA);
		else
			ft_swapper(stack_a, stack_b, SA);
	}
}

void ft_swap_big(t_list **stack_a, t_list **stack_b)
{
}

void ft_push_swap(t_list **stack_a, t_list **stack_b)
{

	if (!ft_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
			ft_swap_2(stack_a, 1);
		else if (ft_lstsize(*stack_a) == 3)
			*stack_a = ft_swap_3(*stack_a);
		else if (ft_lstsize(*stack_a) <= 5)
			ft_swap_5(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) > 5)
			ft_swap_big(stack_a, stack_b);
	}
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	//check duplications
	// allow spaces
	if (!valid_args(argv))
	{
		puts("Error");
		return 1;
	}
	stack_b = NULL;
	stack_a = ft_add_items(argc, argv);
	// print_stacks(stack_a, stack_b);
	ft_push_swap(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b);
}
