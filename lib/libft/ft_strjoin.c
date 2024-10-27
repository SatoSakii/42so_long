/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:45:36 by albernar          #+#    #+#             */
/*   Updated: 2024/10/08 16:49:22 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_s1, int free_s2)
{
	char	*tmp_dest;
	char	*dest;
	char	*tmp_s1;
	char	*tmp_s2;

	if (!s1 || !s2)
		return (NULL);
	tmp_s1 = (char *)s1;
	tmp_s2 = (char *)s2;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	tmp_dest = dest;
	while (*s1)
		*tmp_dest++ = *s1++;
	while (*s2)
		*tmp_dest++ = *s2++;
	*tmp_dest = 0;
	if (free_s1)
		free(tmp_s1);
	if (free_s2)
		free(tmp_s2);
	return (dest);
}
