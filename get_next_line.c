/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:42:14 by jrobles-          #+#    #+#             */
/*   Updated: 2022/05/12 11:43:06 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buf_read(void)
{
	char	*buf_read;

	buf_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_read)
		return (NULL);
	return (buf_read);
}

char	*get_stash(int fd, char *buf_read, char	*stash)
{
	int		byte_return;
	char	*temp;

	byte_return = 1;
	while (byte_return)
	{
		byte_return = read(fd, buf_read, BUFFER_SIZE);
		if (byte_return <= 0 && stash[0] == 0)
		{
			free(stash);
			free(buf_read);
			return (NULL);
		}
		buf_read[byte_return] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buf_read);
		free (temp);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))			//si encuentro un salto de linea paro, e imprimo
			break ;
	}
	return (stash);
}

char	*get_line(char *stash, char	*buf_read, int i)
{
	char	*line;

	line = ft_substr(stash, 0, i + 1);
	free (stash);
	free (buf_read);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf_read;
	char		*stash;
	static char	*rest;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_read = get_buf_read();
	if (rest)
		stash = rest;				//la segunda vez que lo llamo, en stash voy a guardar el resto y volveré a hacer lo mismo
	else
		stash = ft_calloc(1, sizeof(char));
	stash = get_stash(fd, buf_read, stash);
	if (!stash || !buf_read)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	rest = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	if (rest[0] == 0)
	{
		free (rest);
		rest = 0;
	}
	return (get_line(stash, buf_read, i));
}
