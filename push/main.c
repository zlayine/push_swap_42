/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:32 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/28 13:12:34 by zlayine          ###   ########.fr       */
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
	int res;

	new = ft_lst_clone(stack);
	tmp = ft_lst_sort(new);
	size = ft_lstsize(tmp) / 2;
	while (size--)
		tmp = tmp->next;
	// res = tmp->content;
	// ft_lstclear(&new);
	return (tmp->content);
}

int *fetch_medians(t_list *stack, int size, int total)
{
	int i;
	int save;
	int *medians;
	t_list *tmp;

	i = 0;
	tmp = stack;
	save = size;
	medians = malloc(sizeof(int) * (total + 1));
	while (i < total - 1 && tmp->next)
	{
		size = save;
		while (size-- && tmp->next)
			tmp = tmp->next;
		medians[i] = tmp->content;
		i++;
	}
	medians[i] = 0;
	return (medians);
}

int *get_medians(t_list *stack)
{
	t_list *new;
	t_list *tmp;
	int size;
	int *medians;

	new = ft_lst_clone(stack);
	tmp = ft_lst_sort(new);
	size = ft_lstsize(tmp);
	if (size <= 20)
		medians = fetch_medians(tmp, size / 2, 2);
	else if (size <= 100)
		medians = fetch_medians(tmp, size / 5, 5);
	else if (size > 100)
		medians = fetch_medians(tmp, size / 12, 12);
	ft_lstclear(&new);
	return (medians);
}

void ft_swap_5(t_list **stack_a, t_list **stack_b)
{
	int mid;
	t_list *tmp;
	int max;

	mid = get_median(*stack_a);
	tmp = *stack_a;
	while (!ft_sorted(*stack_a) || *stack_b)
	{
		tmp = *stack_a;
		max = get_max_list(*stack_a);
		if (max == 0)
			ft_swapper(stack_a, stack_b, RA);
		else
		{
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
				ft_swapper(stack_a, stack_b, RA);
			else
				ft_swapper(stack_a, stack_b, SA);
		}
	}
}

int arr_len(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void ft_split_to_b(t_list **stack_a, t_list **stack_b, int *mids)
{
	t_list *tmp;
	int current;
	int len;
	int save;

	current = 0;
	tmp = *stack_a;
	len = ft_lstsize(*stack_a) / (arr_len(mids) + 1);
	while (mids[current])
	{
		save = len;
		while (save)
		{
			if (tmp->content < mids[current] && save--)
				ft_swapper(stack_a, stack_b, PB);
			else
				ft_swapper(stack_a, stack_b, RA);
			tmp = *stack_a;
		}
		current++;
	}
}

int get_max_list(t_list *stack)
{
	int counter;
	int save;
	t_list *tmp;
	t_list *curr;

	counter = 0;
	save = 0;
	curr = stack;
	tmp = stack;
	while (tmp)
	{
		if (curr->content < tmp->content)
		{
			curr = tmp;
			save = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	return (save);
}

int get_min_list(t_list *stack)
{
	int counter;
	int save;
	t_list *tmp;
	t_list *curr;

	counter = 0;
	save = 0;
	curr = stack;
	tmp = stack;
	while (tmp)
	{
		if (curr->content > tmp->content)
		{
			curr = tmp;
			save = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	return (save);
}

void minimize_a(t_list **stack_a, t_list **stack_b)
{
	int counter;
	int save;

	counter = get_min_list(*stack_a);
	if (counter == 1)
	{
		ft_swapper(stack_a, stack_b, SA);
		ft_swapper(stack_a, stack_b, PB);
	}
	else
	{
		save = counter;
		if (counter > ft_lstsize(*stack_a) / 2)
			while (counter++ < ft_lstsize(*stack_a))
				ft_swapper(stack_a, stack_b, RRA);
		else
			while (counter--)
				ft_swapper(stack_a, stack_b, RA);
		ft_swapper(stack_a, stack_b, PB);
		counter = save;
		if (counter > ft_lstsize(*stack_a) / 2)
			while (counter++ < ft_lstsize(*stack_a))
				ft_swapper(stack_a, stack_b, RA);
		else
			while (counter--)
				ft_swapper(stack_a, stack_b, RRA);
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
			while (counter++ < ft_lstsize(*stack_b))
				ft_swapper(stack_a, stack_b, RRB);
		else
			while (counter--)
				ft_swapper(stack_a, stack_b, RB);
		ft_swapper(stack_a, stack_b, PA);
		counter = save;
		if (ft_lstsize(*stack_b) == 1)
			ft_swapper(stack_a, stack_b, PA);
		else
		{
			if (counter > ft_lstsize(*stack_b) / 2)
				while (counter++ < ft_lstsize(*stack_b))
					ft_swapper(stack_a, stack_b, RB);
			else
				while (counter--)
					ft_swapper(stack_a, stack_b, RRB);
		}
	}
}

void ft_swap_big(t_list **stack_a, t_list **stack_b)
{
	int *mids;
	int current;
	t_list *tmp;
	int size;

	mids = get_medians(*stack_a);
	tmp = *stack_a;
	ft_split_to_b(stack_a, stack_b, mids);
	while (!ft_sorted(*stack_a) || *stack_b)
	{
		size = ft_lstsize(*stack_a);
		if (ft_sorted(*stack_a) && *stack_b)
			ft_swap_from_b(stack_a, stack_b);
		else if (size == 5)
			ft_swap_5(stack_a, stack_b);
		else
			minimize_a(stack_a, stack_b);
	}
	ft_del(mids);
}

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
		puts("Error");
		return 1;
	}
	stack_b = NULL;
	stack_a = ft_add_items(argc, argv);
	if (!stack_a)
		return 0;
	// print_stacks(stack_a, stack_b);
	ft_push_swap(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a);
}
