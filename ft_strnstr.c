/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:02:26 by yussen            #+#    #+#             */
/*   Updated: 2025/06/01 16:48:45 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	size_t	l_len;

	i = 0;
	l_len = ft_strlen((char *)little);
	while (i <= len)
	{
		if (big[i] == little[i] && big[i])
		{
			if (is_match(((char *)(big + i)),(char *) little))
				return ((char *)(big + l_len));
		}
		i++;
	}
	return (0);
}
