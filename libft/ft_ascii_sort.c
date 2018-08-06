/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:20:01 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/29 17:45:00 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ascii_sort(char **arr, size_t size)
{
	size_t	i;
	size_t	j;
	char	*t;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j > i)
		{
			if (ft_strcmp(arr[j - 1], arr[j]) > 0)
			{
				t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
			--j;
		}
		++i;
	}
}
