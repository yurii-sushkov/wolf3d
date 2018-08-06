/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:16:18 by ysushkov          #+#    #+#             */
/*   Updated: 2018/04/30 18:57:17 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_glue(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if ((dst = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}

static char		*redding(const int fd, char **str)
{
	int				ret;
	char			*temp;
	char			buf[BUFF_SIZE + 1];

	if (str == NULL || fd < 0)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_glue(*str, buf);
		ft_strdel(str);
		*str = ft_strdup(temp);
		ft_strdel(&temp);
		if (ft_strchr(buf, 10))
			break ;
	}
	if (ret < 0)
	{
		ft_strdel(str);
		return (NULL);
	}
	return (*str);
}

static int		ft_check(const int *fd, char **line, char **str)
{
	static int		temp = 0;

	if (temp != *fd)
	{
		temp = *fd;
		if (*str)
			ft_strdel(str);
	}
	if (*fd < 0 || *fd > 4864 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	if (!(*str))
	{
		if ((*str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (-1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	char			*temp;
	size_t			r;

	if (!(ft_check(&fd, line, &str)))
		return (-1);
	if ((!(str = redding(fd, &str))))
		return (-1);
	r = 0;
	if (*(str + r) != 0)
	{
		while (*(str + r) != 10 && *(str + r) != 0)
			r++;
		*line = ft_strsub(str, 0, r);
		if (*(str + r) == 10)
			r++;
		temp = ft_strsub(str, r, (ft_strlen(str) - r));
		ft_strdel(&str);
		str = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	return (0);
}
