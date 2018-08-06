/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:34:49 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/27 15:20:12 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*sub;

	j = 0;
	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	if ((sub = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (len-- && *(s + start))
	{
		*(sub + j) = *(s + start);
		start++;
		j++;
	}
	*(sub + j) = '\0';
	return (sub);
}
