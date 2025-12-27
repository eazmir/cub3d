/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:58 by eazmir            #+#    #+#             */
/*   Updated: 2025/02/07 21:43:43 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*ft_strjoin_free(char *str, char *buf)
// {
// 	char	*tmp;

// 	tmp = ft_strjoin(str, buf);
// 	free(str);
// 	return (tmp);
// }

static char	*get_line(char *str)
{
	int		index;
	int		jndex;
	char	*ptr;

	index = 0;
	jndex = 0;
	if (!*str)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	ptr = (char *)ft_malloc(((index + 2) * sizeof(char)), 1);
	if (!ptr)
		return (NULL);
	while (jndex < index)
	{
		ptr[jndex] = str[jndex];
		jndex++;
	}
	if (str[jndex] == '\n')
		ptr[jndex++] = '\n';
	ptr[jndex] = '\0';
	return (ptr);
}

static char	*get_after_new_line(char *str)
{
	int		index;
	int		jndex;
	char	*ptr;

	index = 0;
	jndex = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		return (NULL);
	}
	ptr = (char *)ft_malloc(((ft_strlen(str) - index + 1) * sizeof(char)), 1);
	if (!ptr)
		return (NULL);
	index++;
	while (str[index])
		ptr[jndex++] = str[index++];
	ptr[jndex] = '\0';
	return (ptr);
}

static char	*read_line(int fd, char *str, char *buf)
{
	int	read_byte;

	if (!str)
		str = ft_strdup("");
	buf = ft_malloc(((BUFFER_SIZE + 1) * sizeof(char)), 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		buf[read_byte] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n') || read_byte == 0)
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		*buf;

	buf = NULL;
	str = read_line(fd, str, buf);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_after_new_line(str);
	return (line);
}
