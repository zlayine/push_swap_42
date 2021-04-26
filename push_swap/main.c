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

#include "../libft/libft.h"
#include "stdio.h"

#define SA "sa"
#define SB "sb"
#define SS "ss"
#define PA "pa"
#define PB "pb"
#define RA "ra"
#define RB "rb"
#define RR "rr"
#define RRA "rra"
#define RRB "rrb"
#define RRR "rrr"

void ft_stack_add(t_list **list, int item)
{
	t_list *new;

	new = ft_lstnew(item);
	ft_lstadd_back(list, new);
}

t_list *ft_add_items(int total, char **argv)
{
	int i;
	int item;
	t_list *stack;

	i = 0;
	stack = NULL;
	while (++i < total)
	{
		item = ft_atoi(argv[i]);
		if (!item)
		{
			puts("error");
			break;
		}
		else
		{
			if (stack)
				ft_stack_add(&stack, item);
			else
				stack = ft_lstnew(item);
		}
	}
	return stack;
}

void ft_lst_swap(t_list *a, char *action)
{
	int tmp;

	if (a)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
		if (action)
			puts(action);
	}
}

void ft_lst_move(t_list **a, t_list **b, char *action)
{
	t_list *tmp;

	if (a && *a)
	{
		tmp = (*a)->next;
		ft_lstadd_front(b, *a);
		*a = tmp;
		puts(action);
	}
}

void ft_lst_shift(t_list **stack, char *action)
{
	t_list *tmp;
	t_list *last;

	if (stack && *stack)
	{
		last = ft_lstlast(*stack);
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		last->next = tmp;
		puts(action);
	}
}

void ft_lst_reshift(t_list **stack, char *action)
{
	t_list *tmp;
	t_list *last;

	if (stack && *stack)
	{
		tmp = *stack;
		while (tmp->next)
		{
			if (tmp->next && !tmp->next->next)
			{
				last = tmp->next;
				tmp->next = NULL;
				break;
			}
			tmp = tmp->next;
		}
		last->next = *stack;
		*stack = last;
		puts(action);
	}
}

void ft_swapper(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, SA))
		ft_lst_swap(*stack_a, action);
	else if (!ft_strcmp(action, SB))
		ft_lst_swap(*stack_b, action);
	else if (!ft_strcmp(action, SS))
	{
		ft_lst_swap(*stack_a, action);
		ft_lst_swap(*stack_b, action);
	}
	else if (!ft_strcmp(action, PA))
		ft_lst_move(stack_b, stack_a, action);
	else if (!ft_strcmp(action, PB))
		ft_lst_move(stack_a, stack_b, action);
	else if (!ft_strcmp(action, RA))
		ft_lst_shift(stack_a, action);
	else if (!ft_strcmp(action, RB))
		ft_lst_shift(stack_b, action);
	else if (!ft_strcmp(action, RR))
	{
		ft_lst_shift(stack_a, action);
		ft_lst_shift(stack_b, action);
	}
	else if (!ft_strcmp(action, RRA))
		ft_lst_reshift(stack_a, action);
	else if (!ft_strcmp(action, RRB))
		ft_lst_reshift(stack_b, action);
	else if (!ft_strcmp(action, RRR))
	{
		ft_lst_reshift(stack_a, action);
		ft_lst_reshift(stack_b, action);
	}
}

void print_stacks(t_list *a, t_list *b)
{
	printf("a => ");
	while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\nb => ");
	while (b)
	{
		printf("%d ", b->content);
		b = b->next;
	}
	printf("\n");
}

void debug(t_list **stack_a, t_list **stack_b)
{
	char *line;
	int r;

	r = 1;
	print_stacks(*stack_a, *stack_b);
	while (r)
	{
		r = get_next_line(0, &line);
		ft_swapper(stack_a, stack_b, line);
		print_stacks(*stack_a, *stack_b);
	}
}

int ft_sorted(t_list *stack)
{
	while (stack)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return 0;
	}
	return 1;
}

t_list *get_middle(t_list *stack)
{
	t_list *middle;
	t_list *tmp;

	tmp = stack->next;
	middle = stack;
	if (stack->content < tmp->content && stack->content < tmp->next->content)
		middle = tmp;
	else if (stack->content > tmp->content && stack->content > tmp->next->content)
		middle = tmp;
	tmp = tmp->next;
	if (middle->content > tmp->content && tmp->content > stack->content)
		middle = tmp;
	else if (tmp->content < stack->content && tmp->content > stack->next->content)
		middle = tmp;

	return middle;
}

t_list *ft_swap_3(t_list *stack)
{
	t_list *mid;
	t_list *last;

	if (ft_sorted(stack))
		return stack;
	mid = stack->next;
	last = mid->next;
	if (stack->content < mid->content)
	{
		if (stack->content < last->content && mid->content > last->content)
		{
			ft_swapper(&stack, NULL, SA);
			ft_swapper(&stack, NULL, RA);
		}
		else if (stack->content > last->content && mid->content > last->content)
			ft_swapper(&stack, NULL, RRA);
	}
	else
	{
		if (mid->content < last->content && last->content > stack->content)
			ft_swapper(&stack, NULL, SA);
		else if (mid->content < last->content)
			ft_swapper(&stack, NULL, RA);
		else
		{
			ft_swapper(&stack, NULL, RA);
			ft_swapper(&stack, NULL, SA);
		}
	}
	return stack;
}

void ft_swap_2(t_list **stack)
{
	ft_swapper(stack, NULL, SA);
}

t_list *get_median(t_list *stack)
{
	t_list *sorted;

	sorted = ft_lst_sort(stack);
}

t_list *ft_swap_5(t_list *stack)
{
	
}

void ft_push_swap(t_list *stack_a, t_list *stack_b)
{
	while (!ft_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			ft_swap_2(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			stack_a = ft_swap_3(stack_a);
		else if (ft_lstsize(stack_a) <= 5)
			stack_a = ft_swap_5(stack_a);
	}
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_b = NULL;
	stack_a = ft_add_items(argc, argv);
	ft_push_swap(stack_a, stack_b);
	// stack_a = ft_swap_3(stack_a);
	// print_stacks(stack_a, NULL);
}
