/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:25:21 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 11:50:21 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	int		i;
	int		len;
	size_t	str_len;
	char	**new_arr;

	len = ft_arr_len(arr);
	new_arr = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		str_len = (int)ft_strlen(arr[i]);
		new_arr[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		ft_strcpy(new_arr[i], arr[i]);
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}
