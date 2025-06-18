/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:54:59 by yussen            #+#    #+#             */
/*   Updated: 2025/06/18 17:19:00 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*str;
	size_t			i;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	if (c == '\0')
		return (str + ft_strlen(s));
	while (n)
	{
		if (str[i] == uc)
			return (str + i);
		i++;
		n--;
	}
	return (NULL);
}
