/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:14:07 by kaoliiny          #+#    #+#             */
/*   Updated: 2018/11/11 00:08:34 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while ((n /= 10) > 0)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	int		size;
	int		minus;
	char	*str;

	minus = 0;
	size = count_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		minus = 1;
	}
	while (size-- > minus)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
