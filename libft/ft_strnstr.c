/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:44:57 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/27 15:01:27 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (n[0] == '\0')
		return (h);
	while (*(h + i) && len-- >= ft_strlen(needle))
	{
		if ((*(h + i)) == *n)
		{
			if (ft_strncmp(h + i, n, ft_strlen(needle)) == 0)
			{
				return (h + i);
			}
		}
		i++;
	}
	return (NULL);
}
