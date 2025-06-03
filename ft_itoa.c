/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:21:05 by yussen            #+#    #+#             */
/*   Updated: 2025/06/03 23:52:22 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base(int n)
{
	int	res;

	res = 0;
	if (n < 0)
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

static char *fill(int n, char *res, int i)
{
	int t;
	char tmp;
	
	t = i;
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n)
	{
		tmp = (n % 10) + '0';
		res[t] = tmp;
		n = n / 10;
		t--;
	}
	return (res);
}
char	*ft_itoa(int n)
{
	int		n_base;
	char	*res;

	n_base = base(n);
	res = (char *)malloc(n_base);
	if (!res)
		return (NULL);
	res[n_base] = '\0';
	fill(n, res, n_base -1);
	return (res);
}

int	main()
{
	printf("%s\n", ft_itoa(-1234));
}