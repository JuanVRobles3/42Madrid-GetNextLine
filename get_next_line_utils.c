/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:42:27 by jrobles-          #+#    #+#             */
/*   Updated: 2022/05/13 18:22:04 by jrobles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	if (str == NULL)
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((i >= start) && (j < len))
			sub[j++] = str[i];
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*join;
	int		len1;
	int		len2;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i])
		join[len1++] = str2[i++];
	join[len1] = '\0';
	return (join);
}

void	*ft_calloc(size_t count, size_t size)

{
	char	*ptr;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < (count * size))
		ptr[i++] = '\0';
	return (ptr);
}
