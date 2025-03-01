/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:37:17 by albernar          #+#    #+#             */
/*   Updated: 2024/10/07 22:44:44 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;

	result = 0;
	while (n-- && !result)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			result = (unsigned char *)s;
		s++;
	}
	return ((void *)result);
}
