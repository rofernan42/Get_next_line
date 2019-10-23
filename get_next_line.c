/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:27 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/23 13:07:55 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*fill_line(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (ft_strchr(str, '\n'))
	{
		if (!(*line = ft_substr(str, 0, i)))
			return (0);
	}
	else
		*line = str;
	if ((tmp = ft_strchr(str, '\n')))
	{
		if (!(tmp = ft_strdup(&str[i + 1])))
			return (0);
		free(str);
		str = tmp;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str = "\0";
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		if (str)
			tmp = ft_strdup(str);
		if (str && *str)
			free(str);
		str = ft_strnew(BUFFER_SIZE);
		if ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[ret] = '\0';
			if (!(str = ft_strjoin_free(str, buffer, 1)))
				return (-1);
			// printf("str vaut : %s\n", str);
		}
		if (ret == 0 && !*str && !*tmp)
			return (0);
		// printf("tmp vaut : %s\n", tmp);
		if (tmp)
		{
			// free(tmp);
			// tmp = ft_strdup("");
			str = ft_strjoin_free(tmp, str, 2);
		}
		// printf("str vaut : %s\n", str);
		if (ret == 0 && *str)
		{
			*line = str;
			str = ft_strnew(0);
			return (1);
		}
		if (ret < 0)
			return (-1);
	}
	if ((str = fill_line(str, line)))
		return (1);
	else
		return (-1);
}
