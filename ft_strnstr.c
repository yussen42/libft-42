/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:02:26 by yussen            #+#    #+#             */
/*   Updated: 2025/06/24 06:01:59 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char *s1, char *s2, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (s2[j] && i < len)
	{
		if (s1[i] == s2[j])
		{
			j++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (*big == '\0')
		return (NULL);
	if (big == little)
		return ((char *)big);
	while (i <= len)
	{
		if (big[i] == little[0] && i <= len)
		{
			if (is_match(((char *)(big)), (char *)little, i, len)
				&& (ft_strlen(little) + i) <= len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
