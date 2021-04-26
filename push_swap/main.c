/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:32 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/26 13:23:39 by zlayine          ###   ########.fr       */
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

void ft_lst_swap(t_list *a)
{
	int tmp;

	if (a)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
}

void ft_lst_move(t_list **a, t_list **b)
{
	t_list *tmp;

	if (a && *a)
	{
		tmp = (*a)->next;
		ft_lstadd_front(b, *a);
		*a = tmp;
	}
}

void ft_lst_shift(t_list **stack)
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
	}
}

void ft_lst_reshift(t_list **stack)
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
	}
}

void ft_swapper(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, SA))
		ft_lst_swap(*stack_a);
	else if (!ft_strcmp(action, SB))
		ft_lst_swap(*stack_b);
	else if (!ft_strcmp(action, SS))
	{
		ft_lst_swap(*stack_a);
		ft_lst_swap(*stack_b);
	}
	else if (!ft_strcmp(action, PA))
		ft_lst_move(stack_b, stack_a);
	else if (!ft_strcmp(action, PB))
		ft_lst_move(stack_a, stack_b);
	else if (!ft_strcmp(action, RA))
		ft_lst_shift(stack_a);
	else if (!ft_strcmp(action, RB))
		ft_lst_shift(stack_b);
	else if (!ft_strcmp(action, RR))
	{
		ft_lst_shift(stack_a);
		ft_lst_shift(stack_b);
	}
	else if (!ft_strcmp(action, RRA))
		ft_lst_reshift(stack_a);
	else if (!ft_strcmp(action, RRB))
		ft_lst_reshift(stack_b);
	else if (!ft_strcmp(action, RRR))
	{
		ft_lst_reshift(stack_a);
		ft_lst_reshift(stack_b);
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

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	char *line;
	int r;

	stack_b = NULL;
	stack_a = ft_add_items(argc, argv);
	r = 1;
	print_stacks(stack_a, stack_b);
	while (r)
	{
		r = get_next_line(0, &line);
		ft_swapper(&stack_a, &stack_b, line);
		print_stacks(stack_a, stack_b);
	}
}
