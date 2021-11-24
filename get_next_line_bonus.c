/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:54:58 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/23 09:16:09 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(ft_strlen_until(s1, '\0')
			+ ft_strlen_until(s2, '\0') + 1);
	if (!s1 || !s2 || !new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		new[i] = *s2;
		s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_with(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(ft_strlen_until(s1, '\0')
			 + ft_strlen_until(s2, '\n') + 1);
	if (!s1 || !s2 || !new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2 != '\n')
	{
		new[i] = *s2;
		s2++;
		i++;
	}
	new[i] = '\n';
	new[i + 1] = '\0';
	return (new);
}

char	*setter_without(char *line, char *holder)
{
	char	*new_line;

	new_line = ft_strjoin(line, holder);
	free(line);
	line = NULL;
	holder[0] = '\0';
	return (new_line);
}

char	*setter_with(char *line, char *holder)
{
	char	*new_line;
	char	*temp;

	new_line = ft_strjoin_with(line, holder);
	temp = ft_substr(holder, based_on_ft_strchr(holder),
			ft_strlen_until(holder, '\0') - based_on_ft_strchr(holder));
	kinda_ft_strlcpy(holder, temp);
	free(line);
	free(temp);
	temp = NULL;
	line = NULL;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	holder[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			read_chars;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	line = (char *) malloc(1);
	line[0] = 0;
	while (!based_on_ft_strchr(holder[fd]))
	{
		if (holder[fd][0])
			line = setter_without(line, holder[fd]);
		read_chars = read(fd, holder[fd], BUFFER_SIZE);
		holder[fd][read_chars] = '\0';
		if (read_chars <= 0 && !*line)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		if (!based_on_ft_strchr(holder[fd])
			&& read_chars < BUFFER_SIZE && !based_on_ft_strchr(line))
			return (setter_without(line, holder[fd]));
	}
	return (setter_with(line, holder[fd]));
}
