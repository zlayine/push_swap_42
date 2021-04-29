/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:06:13 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 12:02:29 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_str(long n, int len)
{
	char	*ptr;
	long	nbr;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	ptr[len] = '\0';
	if (n < 0)
		*ptr = '-';
	nbr = n;
	if (n < 0)
		nbr = -(long)n;
	while (nbr > 9)
	{
		ptr[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	ptr[--len] = nbr + '0';
	return (ptr);
}

char	*ft_itoa(long n)
{
	long	nbr;
	int		len;

	len = 1;
	if (n < 0)
		len++;
	nbr = n;
	if (n < 0)
		nbr = -(long)n;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (get_str(n, len));
}
