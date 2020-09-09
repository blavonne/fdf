/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:20:34 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/30 17:06:48 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_wrds(const char *tmp, char c)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != c && (tmp[i + 1] == c || tmp[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int				check_filename(char *argv)
{
	int		end;

	end = ft_strlen(argv);
	if (end < 5 || argv[end - 1] != 'f' || argv[end - 2] != 'd' || argv[end -
	3] != 'f' || argv[end - 4] != '.')
		return (0);
	return (1);
}

int				check_symb(const char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int				check_input(char *line, int *rows)
{
	if (!*rows)
		*rows = count_wrds(line, ' ');
	else if (*rows && *rows != count_wrds(line, ' '))
		return (0);
	if (!check_symb(line))
		return (0);
	return (1);
}
