/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:23:28 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:50:32 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_del(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_del(arr[i]);
	ft_del(arr);
}
