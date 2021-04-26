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

void ft_stack_add(t_list **list, int item);
t_list *ft_add_items(int total, char **argv);
void ft_lst_swap(t_list *a, char *action);
void ft_lst_move(t_list **a, t_list **b, char *action);
void ft_lst_shift(t_list **stack, char *action);
void ft_lst_reshift(t_list **stack, char *action);
void ft_swapper(t_list **stack_a, t_list **stack_b, char *action);
void print_stacks(t_list *a, t_list *b);
void debug(t_list **stack_a, t_list **stack_b);
int ft_sorted(t_list *stack);
int valid_args(char **argv);
