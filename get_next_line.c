/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:27 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/24 12:17:17 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(*line = ft_substr(str, 0, i)))
		return (0);
	if ((tmp = ft_strchr(str, '\n')))
	{
		if (!(tmp = ft_strdup(&str[i + 1])))
			return (0);
		free(str);
		str = tmp;
	}
	return (str);
}

int		read_line(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	if (str[fd])
		tmp = ft_strdup(str[fd]);
	if (*str[fd])
		free(str[fd]);
	str[fd] = ft_strdup("");
	if ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!(str[fd] = ft_strjoin_free(str[fd], buffer, 1)))
			return (-1);
	}
	str[fd] = ft_strjoin_free(tmp, str[fd], 2);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[1024];

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	while (!ft_strchr(str[fd], '\n'))
	{
		ret = read_line(fd, str);
		if (ret == 0 && !*str[fd])
			return (0);
		if (ret == 0 && *str[fd])
		{
			*line = str[fd];
			str[fd] = ft_strdup("");
			return (1);
		}
		if (ret < 0)
			return (-1);
	}
	str[fd] = fill_line(str[fd], line);
	return (1);
}
