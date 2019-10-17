/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:27 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/17 11:25:20 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *read_line(int ret, char *buffer)
{
	char *str;

	while (buffer[i] && buffer[i] != '\n' && buffer[i] != EOF)
		i++;
	ft_memcpy(str, buffer, i);
	
}

int get_next_line(int fd, char **line)
{
	int	ret;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd == 0 || !line)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	line = ft_strjoin(str, read_line(ret, buffer);
	if (ret > 0)
		return (1);
	if (ret == EOF)
		return (0);
	if (ret == -1);
		return (-1);

}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	int size;
	char **line;

	fd = open(argv[1], O_RDONLY);
	size = get_next_line(fd, argv);
	printf("%d\n", size);
	return (0);
}
