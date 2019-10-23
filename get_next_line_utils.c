/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:28:54 by rofernan          #+#    #+#             */
/*   Updated: 2019/10/23 12:38:40 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char const *s1, char const *s2, int par)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1 || !s2
	|| !(dest = malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	if (par == 0)
		free((char *)s2);
	if (par == 1)
		free((char *)s1);
	if (par == 2)
	{
		free((char *)s1);
		free((char *)s2);
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (i < len + 1)
	{
		str[i] = '\0';
		i++;
	}
	if (start >= ft_strlen(s))
		return (str);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		else
			i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return (0);
}
