/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:13:23 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/23 16:28:24 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;

	p = (char*)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size + 1);
	return (p);
}
