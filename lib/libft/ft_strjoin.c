/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:49:11 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/03 16:30:56 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)debug_malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (*s1)
	{
		*res++ = *s1++;
	}
	while (*s2)
	{
		*res++ = *s2++;
	}
	*(res) = '\0';
	// free(s1);
	return (res - len);
}
