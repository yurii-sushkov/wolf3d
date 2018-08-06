/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:57:50 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/23 20:32:39 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	int		total;

	i = 0;
	total = 0;
	if (!s1 || !s2)
		return (0);
	while (total == 0)
	{
		total = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	if (total == 0)
		return (1);
	else
		return (0);
}
