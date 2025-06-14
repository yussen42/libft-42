/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:20:48 by yussen            #+#    #+#             */
/*   Updated: 2025/06/13 04:51:32 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	len = ft_strlen(s);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (len--)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
char	c(unsigned int a, char b)
{	
	(void)a;
	if (b >= 'a' && b <= 'z')
		return (b - 32);
	else
		return (b);
}
int	main()
{
	unsigned int a = 5;
	char b = 'A';
	
	char	res[20];
	printf("%s", ft_strmapi(res, (*c)(a, b)));
	char	str[] = "esduman";
	char	*result = ft_strmapi(str, c);
	printf("%s", result);
	free(result);
}*/