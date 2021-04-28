#include "../includes/push.h"

void ft_checker(t_list **stack_a, t_list **stack_b)
{
	char *line;
	int r;

	r = 1;
	while (r)
	{
		// print_stacks(*stack_a, *stack_b);
		r = get_next_line(0, &line);
		ft_swapper(stack_a, stack_b, line);
	}
	if (ft_sorted(*stack_a))
		puts("OK");
	else
		puts("KO");
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
	print_stacks(stack_a, stack_b);
	ft_checker(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b);
}