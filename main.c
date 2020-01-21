/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:42:49 by rofernan          #+#    #+#             */
/*   Updated: 2020/01/21 10:56:53 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line;
	int		ret;

	if (argc < 3)
	{
		if (argc == 1)
			fd = 0;
		else
			fd = open(argv[1], O_RDONLY);

		/* Read file line by line */
		/*
		ret = get_next_line(fd, &line);
		printf("%d -> %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("%d -> %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("%d -> %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("%d -> %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("%d -> %s\n", ret, line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("%d -> %s\n", ret, line);
		free(line);
		*/

		/* Read all file */

		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d -> %s\n", ret, line);
			free(line);
		}
		printf("%d -> %s\n", ret, line);
		free(line);

		close(fd);
	}
	else if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd1, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d -> line: %s\n", ret, line);
		free(line);
		close(fd1);
		close(fd2);
	}
	return (0);
}
