/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:24:39 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 16:05:57 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"

int	check_number(char *num)
{
	int		i;
	char	*str;

	i = -1;
	if (num[0] == '-')
		i++;
	if (check_bonus(num[i + 1]))
		return (1);
	if (!num[i + 1] && num[i + 1] != 'v' && num[i + 1] != 'c'
		&& num[i + 1] != 'd')
		return (0);
	while (num[++i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
	}
	str = ft_itoa(ft_atoi(num));
	if (ft_strcmp(str, num))
	{
		ft_del(str);
		return (0);
	}
	ft_del(str);
	return (1);
}

int	valid_args(char **argv)
{
	int		i;

	i = 0;
	if (!argv[1])
		return (0);
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!check_numbers(argv[i]))
				return (0);
		}
		else if (!check_number(argv[i]))
			return (0);
	}
	return (1);
}

int	check_numbers(char *str)
{
	int		j;
	char	**numbers;

	j = -1;
	numbers = ft_split(str, ' ');
	while (numbers[++j])
	{
		if (!check_number(numbers[j]))
		{
			ft_arr_del(numbers);
			return (0);
		}
	}
	ft_arr_del(numbers);
	return (1);
}

int	add_number(t_list **stack, char *str)
{
	int	item;

	if (!ft_strcmp(str, "-v") || !ft_strcmp(str, "-c") || !ft_strcmp(str, "-d"))
		return (1);
	item = ft_atoi(str);
	if (ft_lst_item_exist(*stack, item))
		return (0);
	if (*stack)
		ft_stack_add(stack, item);
	else
		*stack = ft_lstnew(item);
	return (1);
}

int	add_numbers(t_list **stack, char *str)
{
	int		j;
	char	**numbers;

	j = -1;
	numbers = ft_split(str, ' ');
	while (numbers[++j])
	{
		if (!add_number(stack, numbers[j]))
		{
			ft_arr_del(numbers);
			return (0);
		}
	}
	ft_arr_del(numbers);
	return (1);
}
