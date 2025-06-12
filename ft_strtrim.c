/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:53:18 by yussen            #+#    #+#             */
/*   Updated: 2025/06/10 15:42:19 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	le_s1(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static size_t	b_c(const char *s1, const char *set)
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

static size_t	e_c(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	size_t	control;

	i = le_s1(s1) - 1;
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
	size_t	first_len;
	int		i;
	char	*res;

	first_len = le_s1(s1);
	i = 0;
	b_l = b_c(s1, set);
	new_len = first_len - (b_l + e_c(s1, set)) + 1;
	res = malloc(new_len + 1);
	if (!res)
		return (NULL);
	while (i < new_len - 1)
	{
		res[i] = s1[i + b_l];
		i++;
	}
	res[i] = '\0';
	return (res);
}
