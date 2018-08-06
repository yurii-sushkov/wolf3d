/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:43:02 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/28 16:56:24 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!dst && !src)
		return (dst);
	p = ft_strnew(len);
	if (p)
	{
		p = ft_memcpy(p, src, len);
		dst = ft_memcpy(dst, p, len);
	}
	free(p);
	return (dst);
}
