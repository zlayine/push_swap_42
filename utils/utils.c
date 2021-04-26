#include "../includes/push.h"

void ft_stack_add(t_list **list, int item)
{
	t_list *new;

	new = ft_lstnew(item);
	ft_lstadd_back(list, new);
}

t_list *ft_lst_clone(t_list *list)
{
	t_list *clone;

	while (list)
	{
		if (!clone)
			clone = ft_lstnew(list->content);
		else
			ft_lstadd_back(&clone, ft_lstnew(list->content));
		list = list->next;
	}
	return clone;
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
		if (stack)
			ft_stack_add(&stack, item);
		else
			stack = ft_lstnew(item);
	}
	return stack;
}

void ft_lst_swap(t_list *a, char *action)
{
	int tmp;

	if (a && a->next)
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

void ft_swapper_a(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, SA))
		ft_lst_swap(*stack_a, action);
	else if (!ft_strcmp(action, PA))
		ft_lst_move(stack_b, stack_a, action);
	else if (!ft_strcmp(action, RA))
		ft_lst_shift(stack_a, action);
	else if (!ft_strcmp(action, RRA))
		ft_lst_reshift(stack_a, action);
}

void ft_swapper_b(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, SB))
		ft_lst_swap(*stack_b, action);
	else if (!ft_strcmp(action, PB))
		ft_lst_move(stack_a, stack_b, action);
	else if (!ft_strcmp(action, RB))
		ft_lst_shift(stack_b, action);
	else if (!ft_strcmp(action, RRB))
		ft_lst_reshift(stack_b, action);
}

void ft_swapper(t_list **stack_a, t_list **stack_b, char *action)
{
	ft_swapper_a(stack_a, stack_b, action);
	ft_swapper_b(stack_a, stack_b, action);
	if (!ft_strcmp(action, SS))
	{
		ft_lst_swap(*stack_a, action);
		ft_lst_swap(*stack_b, action);
	}
	else if (!ft_strcmp(action, RR))
	{
		ft_lst_shift(stack_a, action);
		ft_lst_shift(stack_b, action);
	}
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
	while (stack && stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return 0;
	}
	return 1;
}

int valid_args(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return 0;
		}
	}
	return 1;
}