/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:21:44 by ashih             #+#    #+#             */
/*   Updated: 2018/01/03 20:22:58 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		skip_next_line(int fd, int n)
{
	char	*line;
	int		i;

	i = 0;
	while (i < n)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
		i++;
	}
}
