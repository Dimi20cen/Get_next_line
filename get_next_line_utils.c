/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:47:12 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/19 09:03:35 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_until(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c)
	{
		len++;
		s++;
	}
	if (c == '\n')
		return (len + 1);
	return (len);
}

int	based_on_ft_strchr(const char *s)
{
	int	i;

	i = 1;
	while (*s != '\0')
	{
		if (*s == '\n')
			return (i);
		s++;
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(len + 1);
	if (!s || !new)
		return (0);
	while ((start + i) < ft_strlen_until(s, '\0') && len > 0)
	{
		new[i] = s[start + i];
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}

void	kinda_ft_strlcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
