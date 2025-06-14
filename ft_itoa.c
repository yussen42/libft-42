/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:21:05 by yussen            #+#    #+#             */
/*   Updated: 2025/06/15 02:30:52 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base(int n)
{
	int	res;

	res = 0;
	if (n <= 0)
	{
		res++;
	}
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

static char	*fill(int n, char *res, int i)
{
	char	tmp;

	if (n == 0)
	{
		res[i] = '0';
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[i--] = '8';
			n = -214748364;
		}
		n *= -1;
	}
	while (n)
	{
		tmp = (n % 10) + '0';
		res[i] = tmp;
		n = n / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		n_base;
	char	*res;

	n_base = base(n);
	res = (char *)malloc(n_base + 1);
	if (!res)
		return (NULL);
	res[n_base] = '\0';
	fill(n, res, n_base - 1);
	return (res);
}
