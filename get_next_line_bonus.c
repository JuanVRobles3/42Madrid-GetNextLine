/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:12:37 by jrobles-          #+#    #+#             */
/*   Updated: 2022/05/13 18:21:31 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		if (ft_strchr(stash, '\n'))
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
	char		*stash[257];
	static char	*rest[257];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	buf_read = get_buf_read();
	if (rest[fd])
		stash[fd] = rest[fd];
	else
		stash[fd] = ft_calloc(1, sizeof(char));
	stash[fd] = get_stash(fd, buf_read, stash[fd]);
	if (!stash[fd] || !buf_read)
		return (NULL);
	i = 0;
	while (stash[fd][i] != '\n' && stash[fd][i] != '\0')
		i++;
	rest[fd] = ft_substr(stash[fd], i + 1, ft_strlen(stash[fd]) - i);
	if (rest[fd][0] == 0)
	{
		free (rest[fd]);
		rest[fd] = 0;
	}
	return (get_line(stash[fd], buf_read, i));
}

/*File Descriptor Limit the default limit on the number 
of file descriptors that a process can open is 64.
Most 4.x applications can handle only 256 file descriptors.
*/
