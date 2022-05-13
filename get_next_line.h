/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:42:39 by jrobles-          #+#    #+#             */
/*   Updated: 2022/05/12 11:43:36 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

//functions allowed.
void	*malloc(size_t size);
void	free(void *ptr);
ssize_t	read(int fildes, void *buf, size_t nbyte);

//functions in Libft and get_next_line_utils.c
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);

//functions in get_next_line.c
char	*get_buf_read(void);
char	*get_stash(int fd, char *buf_read, char *stash);
char	*get_line(char *stash, char	*buf_read, int i);
char	*get_next_line(int fd);

#endif
