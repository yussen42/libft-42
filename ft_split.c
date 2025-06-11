/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:40:33 by yussen            #+#    #+#             */
/*   Updated: 2025/06/11 05:33:29 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	w_count;
	int	flag;

	flag = 0;
	i = 0;
	w_count = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			flag = 1;
		}
		if (flag)
			w_count++;
	}
	return (w_count);
}

void	fill_word(char const *s, char c, char **res)
{
	int	i;
	int	start;
	int	l_word;
	
	start = 0;
	i = 0;
	while (s[i])
	{
		l_word = 0;
		while (s[i] == c && s[i])
		{
			i++;
			start++;
		}
		while (s[i] != c && s[i])
		{
			i++;
			l_word++;
		}
		*res++ = ft_substr(s, start, l_word);
		start += l_word;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	fill_word(s, c, res);
	return (res);
	
}

int	main()
{
	char	s[] = "yusuf talha sen";
	
	char **res = ft_split(s, ' ');
	
	//int i = 0;
	//while (i < sizeof(res))
	//{
	//	printf("%s", res[i++]);
	//}
	printf("%s\n", res[0]);
	printf("%s\n", res[1]);
	printf("%s\n", res[2]);
	printf("%s\n", res[3]);
}