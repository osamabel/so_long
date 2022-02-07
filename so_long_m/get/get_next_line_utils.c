/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:38:41 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 15:06:39 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

size_t	check_end_of_line(char	*buf)
{
	size_t	i;

	i = 0;
	if (buf)
	{
		while (buf[i] != '\n' && buf[i])
			i++;
	}
	return (i);
}

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	malloc_error(void)
{
	write(2, "malloc error\n", 13);
	exit(5);
}

char	*ft_strjoin(char **line, char **str)
{
	char	*temp;

	if (!*line && *str)
	{
		*line = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
		if (!*line)
			malloc_error();
		ft_strncpy(*line, *str, ft_strlen(*str) + 1);
		free(*str);
		*str = NULL;
		return (*line);
	}
	if (*line && *str)
	{
		temp = *line;
		*line = malloc(sizeof(char) * (ft_strlen(*line) + ft_strlen(*str) + 1));
		if (!*line)
			malloc_error();
		ft_strncpy(*line, temp, ft_strlen(temp));
		ft_strncpy(*line + ft_strlen(temp), *str, ft_strlen(*str) + 1);
		free(*str);
		*str = NULL;
		free(temp);
	}
	return (*line);
}

void	ft_strncpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < len)
	{
		*(dest + i) = '\0';
		i++;
	}
}
