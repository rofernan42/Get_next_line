/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:27 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/21 11:42:30 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// char	*read_line(char *buffer)
// {
// 	int		ret;
// 	static char	*str;

// 	if (!(str = malloc(sizeof(char) * ft_strlen(buffer) + 1)))
// 		return (NULL);

// 	str = ft_strjoin(str, buffer);
// 	return (str);
// }

int		get_next_line(int fd, char **line)
{
	int			ret;
	int			i;
	static char	*str = "\0";
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	ret = 1;
	if (fd == 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!ft_strchr(str, '\n') || !*str)
	{
		while (!ft_strchr(str, '\n') && ret > 0) 
		{
			if ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
			{
				buffer[ret] = '\0';
				if (!(str = ft_strjoin(str, buffer)))
					return (-1);
			}
		}
	}
	printf("%s\n", str);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
		printf("%d\n", i);
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strchr(str, '\n');
			free(str);
			str = tmp;
		}
	} 
	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	int ret;
	char *line;

	ret = 1;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	// printf("%s\n", line); 
	// while (ret > 0) {
	// 	ret = get_next_line(fd, &line);
	//	printf("%s\n", line); 
	// }
	close(fd);
	return (0);
}
