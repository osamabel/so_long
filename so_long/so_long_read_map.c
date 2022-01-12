/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:19:53 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 16:49:07 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

char	*read_map(int fd, t_data *data)
{
	char	*buf;
	char	*map;
	int		widht;

	data->Y_block = 0;
	map = NULL;
	buf = get_next_line(fd);
	data->X_block = check_end_of_line(buf);
	while (buf)
	{
		data->Y_block++;
		ft_strjoin(&map, &buf);
		buf = get_next_line(fd);
		widht = check_end_of_line(buf);
		if (data->X_block != widht && buf)
			return (0);
	}
	return (map);
}

int	wcount(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

int	spliting_problem(char **result, int n)
{
	if (!result[n])
	{
		while (n >= 0)
			free (result[n--]);
		free (result);
		return (1);
	}
	return (0);
}

char	**str_to_split(char **result, char *str, char c)
{
	int	i;
	int	j;
	int	wc;
	int	word;

	i = 0;
	j = 0;
	wc = wcount(str, c);
	word = 0;
	while (str[i])
	{
		str_to_split_utils(str, &i, &j, c);
		if (i < j)
		{
			result[word] = (char *)malloc((j - i) * sizeof(char));
			if (spliting_problem(result, word))
				return (0);
			ft_strncpy(result[word++], str + i, j - i);
		}
		if (word <= wc)
			result[word - 1][j - i] = '\0';
		i = j;
	}
	result[word] = 0;
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**split_str;

	if (!s)
		return (0);
	split_str = NULL;
	split_str = (char **) malloc((wcount(s, c) + 1) * sizeof(char *));
	if (!split_str)
		return (0);
	return (str_to_split(split_str, s, c));
}
