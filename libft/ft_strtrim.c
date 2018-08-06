/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:06:32 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/28 12:40:45 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhite(char w)
{
	if (w == ' ' || w == '\n' || w == '\t')
		return (1);
	else
		return (0);
}

static size_t	k_count(const char *s, size_t k)
{
	size_t x;

	while (s[k] != '\0')
	{
		if ((s[k] >= 33 && s[k] <= 127 && ft_iswhite(s[k + 1]) == 1) ||
			(s[k] >= 33 && s[k] <= 127 && s[k + 1] == '\0'))
			x = k + 1;
		k++;
	}
	return (x);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	x;
	char	*dst;

	i = 0;
	j = 0;
	if (!s || s == NULL)
		return (NULL);
	while (ft_iswhite(s[i]) == 1)
		i++;
	k = i;
	if (i != ft_strlen(s))
		x = k_count(s, k);
	else
		x = i;
	dst = (char *)malloc(sizeof(char) * (x - i + 1));
	if (dst == NULL)
		return (NULL);
	while (i < x)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}
