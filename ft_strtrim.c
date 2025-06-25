/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:53:18 by yussen            #+#    #+#             */
/*   Updated: 2025/06/24 06:11:38 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	beginning_count(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	size_t	control;

	i = 0;
	control = 0;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j++])
			{
				flag = 1;
				break ;
			}
		}
		control++;
		if (flag == 0)
			break ;
		i++;
	}
	return (control - 1);
}

static size_t	ending_count(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	size_t	control;

	i = ft_strlen(s1) - 1;
	control = 0;
	while (i > 0)
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j++])
			{
				flag = 1;
				break ;
			}
		}
		control++;
		if (flag == 0)
			break ;
		i--;
	}
	return (control - 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	b_l;
	size_t	new_len;
	size_t	i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_calloc(1, 1));
	i = 0;
	b_l = beginning_count(s1, set);
	new_len = ft_strlen(s1) - (b_l + ending_count(s1, set));
	if (new_len > ft_strlen(s1))
		return (ft_strdup(""));
	res = malloc(new_len + 1);
	if (!res)
		return (NULL);
	while (i < new_len)
	{
		res[i] = s1[i + b_l];
		i++;
	}
	res[i] = '\0';
	return (res);
}
