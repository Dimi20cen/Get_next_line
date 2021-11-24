/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:50:40 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/12 10:10:55 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main()
{
	int		fd;
	int		 i = 0;
	char	*lol;

	fd = open("bacon.txt", O_RDONLY);
	while (i++ < 5)
	{
		lol = get_next_line(fd);
		printf("%s", lol);
		free(lol);
		lol = NULL;
	}
	return (0);
}
