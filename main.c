/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:58:33 by ysushkov          #+#    #+#             */
/*   Updated: 2018/08/06 10:46:40 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	ft_usage(int n)
{
	if (n == 1)
		ft_putendl("usage : ./wolf3d [map]");
	exit(1);
}

void	ft_error(int n)
{
	if (n == 1)
	{
		ft_putendl("map error");
		ft_putendl("Your map can not be a directory.");
		ft_putendl("It must contain only digits: 0-6.");
		ft_putendl("Your map can not be surrounded by '0'.");
		ft_putendl("Player start position is [1][1], so it must be '0'.");
		ft_putendl("The number of digits in every row must be the same.");
		ft_putendl("Example of valid map:");
		ft_putendl("111");
		ft_putendl("101");
		ft_putendl("111");
	}
	if (n == 2)
		ft_putendl("Error");
	if (n == 3)
		ft_putendl("The size of your map is too big. Please, edit your map.");
	if (n == 4)
		ft_putendl("Texture error");
	exit(1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		validation(argv[1]);
	else
		ft_usage(1);
	return (0);
}
