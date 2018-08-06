/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:59:36 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/27 14:11:25 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (h[0] != '\0' && n[0] == '\0')
		return (h);
	if (h[0] == '\0' && n[0] == '\0')
		return (h);
	while (*(h + i))
	{
		if ((*(h + i)) == *n)
		{
			if (ft_strncmp(h + i, n, ft_strlen(needle)) == 0)
				return (h + i);
		}
		i++;
	}
	return (NULL);
}
