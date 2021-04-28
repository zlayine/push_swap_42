/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:32 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/28 16:49:36 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

void ft_split_to_b(t_list **stack_a, t_list **stack_b, char **mids)
{
	t_list *tmp;
	int current;
	int len;
	int save;
	int curr;
	int len_a;
	int len_b;

	current = 0;
	tmp = *stack_a;
	len = ft_lstsize(*stack_a) / (ft_arr_len(mids));
	while (current < 4)
	{
		save = len;
		while (save && tmp)
		{
			// blan dial amine
			curr = ft_atoi(mids[current]);
			if 
			
			else
				ft_swapper(stack_a, stack_b, RA);
			else if (tmp->content < curr && save--)
				ft_swapper(stack_a, stack_b, PB);
			tmp = *stack_a;
		}
		current++;
		// print_stacks(*stack_a, *stack_b);
	}
}

void minimize_a(t_list **stack_a, t_list **stack_b)
{
	int counter;
	int save;

	counter = get_min_list(*stack_a);
	// printf("%d \n", counter);
	if (counter == 1)
	{
		ft_swapper(stack_a, stack_b, SA);
		ft_swapper(stack_a, stack_b, PB);
	}
	else
	{
		save = counter;
		if (counter > ft_lstsize(*stack_a) / 2)
			rotate_stack_a(stack_a, RRA, 1, counter);
		else
			rotate_stack_a(stack_a, RA, 0, counter);
		ft_swapper(stack_a, stack_b, PB);
		counter = save;
		if (counter > ft_lstsize(*stack_a) / 2)
			rotate_stack_a(stack_a, RA, 1, counter);
		else
			rotate_stack_a(stack_a, RRA, 0, counter);
		// print_stacks(*stack_a, *stack_b);
	}
}

void ft_swap_from_b(t_list **stack_a, t_list **stack_b)
{
	int counter;
	int save;

	counter = get_max_list(*stack_b);
	if (counter == 1)
	{
		ft_swapper(stack_a, stack_b, SB);
		ft_swapper(stack_a, stack_b, PA);
	}
	else
	{
		save = counter;
		if (counter > ft_lstsize(*stack_b) / 2)
			rotate_stack_b(stack_b, RRB, 1, counter);
		else
			rotate_stack_b(stack_b, RB, 0, counter);
		ft_swapper(stack_a, stack_b, PA);
		counter = save;
		if (ft_lstsize(*stack_b) == 1)
			ft_swapper(stack_a, stack_b, PA);
		else if (ft_lstsize(*stack_b) > 1 && counter > ft_lstsize(*stack_b) / 2)
			rotate_stack_b(stack_b, RB, 1, counter);
		else if (ft_lstsize(*stack_b) > 1)
			rotate_stack_b(stack_b, RRB, 0, counter);
	}
}
//ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
void ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int size;

	size = ft_lstsize(*stack_a);
	if (!ft_sorted(*stack_a))
	{
		if (size == 2)
			ft_swap_2(stack_a, 1);
		else if (size == 3)
			*stack_a = ft_swap_3(*stack_a);
		else if (size <= 5)
			ft_swap_5(stack_a, stack_b);
		else if (size > 5)
			ft_swap_big(stack_a, stack_b);
	}
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

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
	ft_push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
