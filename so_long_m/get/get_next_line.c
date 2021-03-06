/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 15:06:39 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

char	*ft_strdup(char	*str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char ) * ft_strlen(str) + 1);
	if (!dest)
		malloc_error();
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	creat_line(char **line, char **lost, char **buffer)
{
	size_t	check;
	char	*last;

	check = check_end_of_line(*buffer);
	if (check < BUFFER_SIZE)
	{
		ft_strjoin(line, lost);
		ft_strsplit(*buffer, &last, lost, check);
		ft_strjoin(line, &last);
	}
	else
		ft_strjoin(line, buffer);
	if (*buffer)
		free(*buffer);
	buffer = NULL;
}

void	ft_strsplit(char *holder, char **first, char **secend, size_t check)
{
	char	*lost;

	if (check < ft_strlen(holder))
	{
		*first = (char *)malloc(sizeof(char) * check + 2);
		ft_strncpy(*first, holder, check + 1);
		*(*first + check + 1) = '\0';
		lost = (char *)malloc(sizeof(char) * (ft_strlen(holder) - check));
		ft_strncpy(lost, holder + check + 1, ft_strlen(holder) - check);
		if (*lost == '\0')
		{
			free(lost);
			lost = NULL;
		}
		free(*secend);
		*secend = lost;
	}
	else
	{
		*first = (char *)malloc(sizeof(char) * check + 1);
		ft_strncpy(*first, holder, check + 1);
		free(*secend);
		*secend = NULL;
	}
}

char	*read_and_store(int fd, char **line, char **lost)
{
	char	*buffer;
	int		read_char;
	size_t	check;

	check = BUFFER_SIZE;
	while (check == BUFFER_SIZE)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			malloc_error();
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char <= 0)
		{
			if (buffer)
				free(buffer);
			buffer = NULL;
			return (*line);
		}
		buffer[read_char] = '\0';
		check = check_end_of_line(buffer);
		creat_line(line, lost, &buffer);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*lost;
	char		*line;

	line = NULL;
	if (lost && check_end_of_line(lost) <= ft_strlen(lost))
	{
		ft_strsplit(lost, &line, &lost, check_end_of_line(lost));
		if (check_end_of_line(line) < ft_strlen(line))
			return (line);
	}
	return (read_and_store(fd, &line, &lost));
}
