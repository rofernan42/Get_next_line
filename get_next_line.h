/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:07:39 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/24 18:22:30 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char const *s1, char const *s2, int par);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*fill_line(char **str, char **line, int fd);
int		read_line(int fd, char **str);
int		get_next_line(int fd, char **line);

#endif
