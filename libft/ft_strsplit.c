/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:56:38 by ysushkov          #+#    #+#             */
/*   Updated: 2018/06/04 10:58:29 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (*(s + i) == c)
		i++;
	while (*(s + i) != '\0')
	{
		if ((*(s + i) != c && *(s + i + 1) == c) ||
			(*(s + i) != c && *(s + i + 1) == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char		*ft_string(char const *src, char c, size_t *i)
{
	char	*dst;
	size_t	k;

	if ((dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	k = 0;
	while (src[*i] != c && src[*i])
	{
		dst[k] = src[*i];
		k++;
		*i = *i + 1;
	}
	dst[k] = '\0';
	while (src[*i] == c)
		*i = *i + 1;
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**arr;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	if ((arr = (char **)malloc(sizeof(arr) * (ft_words(s, c) + 2))) == NULL)
		return (NULL);
	while (*(s + i) == c)
		i++;
	while (j < words && *(s + i))
	{
		*(arr + j) = ft_string(s, c, &i);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
