/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:02:54 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/12 20:55:07 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_largeur(long n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		i[3];
	char	*s;
	long	num;

	num = n;
	i[0] = ft_largeur(num);
	i[1] = 0;
	i[2] = i[0];
	if ((s = (char *)malloc(sizeof(char) * (i[0] + 1))) == NULL)
		return (NULL);
	s = ft_strnew(i[0]);
	if (num < 0)
	{
		i[1] = 1;
		num = num * -1;
		*(s) = '-';
	}
	i[2]--;
	while (i[2] >= i[1])
	{
		s[i[2]--] = num % 10 + '0';
		num /= 10;
	}
	return (s);
}
