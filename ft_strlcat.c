/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:33:36 by yussen            #+#    #+#             */
/*   Updated: 2025/06/02 18:34:09 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	i;
	
	i = 0;
	d_len = ft_strlen(dst);
	while (src[i] && i < size)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	return (i);
	
}
int	main()
{
	char	dst[] = "tal";
	char	src[] = "ha";
	printf("%zu\n", ft_strlcat(dst, src, 6));
	printf("%s\n", dst);
}