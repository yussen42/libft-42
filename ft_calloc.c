/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussen <yussen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 05:16:44 by yussen            #+#    #+#             */
/*   Updated: 2025/06/01 13:11:35 by yussen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*calloc(size_t nmemb, size_t size)
{
	unsigned char *	res;
	if (nmemb == 0 && size == 0)
		return (NULL);
	res = malloc(size * nmemb);
	return (ft_bzero(res,nmemb));
}

int	main()
{
	
}
