#include "../libft/libft.h"
#include "stdio.h"
#include "limits.h"

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

char g_bonus;

void ft_stack_add(t_list **list, int item);
t_list *ft_add_items(int total, char **argv);
void ft_lst_swap(t_list *a);
void ft_lst_move(t_list **a, t_list **b);
void ft_lst_shift(t_list **stack);
void ft_lst_reshift(t_list **stack);
void ft_swapper(t_list **stack_a, t_list **stack_b, char *action);
void print_stacks(t_list *a, t_list *b);
void debug(t_list **stack_a, t_list **stack_b);
int ft_sorted(t_list *stack);
int valid_args(char **argv);
t_list *ft_lst_clone(t_list *list);
t_list *ft_swap_3(t_list *stack);
int get_median(t_list *stack);
char **fetch_medians(t_list *stack, int size, int total);
char **get_medians(t_list *stack);
void ft_swap_5(t_list **stack_a, t_list **stack_b);
int arr_len(int *arr);
void ft_split_to_b(t_list **stack_a, t_list **stack_b, char **mids);
int get_max_list(t_list *stack);
int get_min_list(t_list *stack);
void minimize_a(t_list **stack_a, t_list **stack_b);
void ft_swap_from_b(t_list **stack_a, t_list **stack_b);
void ft_swap_big(t_list **stack_a, t_list **stack_b);
void ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_swap_2(t_list **stack, int rev);
void	rotate_stack_a(t_list **stack, char *action, int direction, int counter);
void	rotate_stack_b(t_list **stack, char *action, int direction, int counter);
void print_color(char *action);
