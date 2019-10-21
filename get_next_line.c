/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:27 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/21 15:21:32 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_line(char *str, char **line)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(*line = ft_substr(str, 0, i)))
		return (0);
	if (ft_strchr(str, '\n'))
		str = &str[i + 1];
	else
		return (0);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str = "\0";
	char		buffer[BUFFER_SIZE + 1];

	ret = 1;
	if (fd == 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_strchr(str, '\n') && ret > 0)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[ret] = '\0';
			if (!(str = ft_strjoin(str, buffer)))
				return (-1);
		}
	}
	if (ret < 0)
		return (-1);
	if (ret == 0)
		*line = str;
	if ((str = fill_line(str, line)))
		return (1);
	free(str);
	str = "\0";
	return (0);
}
