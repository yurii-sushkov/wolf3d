/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:39:34 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/22 17:44:57 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				total;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	total = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (total == 0 && i < n)
	{
		total = *(str1 + i) - *(str2 + i);
		if (i == n)
			return (0);
		i++;
	}
	return (total);
}
