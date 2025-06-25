/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:20:48 by yussen            #+#    #+#             */
/*   Updated: 2025/06/23 01:05:17 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s || !f)
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
