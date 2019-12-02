/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:47:20 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/14 15:24:11 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alloc(int n)
{
	int		count;
	int		size;

	count = 0;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	if (n < 0)
		return (size = count + 1 + 1);
	else
		return (size = count + 1);
}

static char	*ft_reverse(char *str)
{
	char	c;
	int		begin;
	int		end;

	begin = 0;
	end = ft_strlen(str) - 1;
	while (begin < end)
	{
		c = str[begin];
		str[begin] = str[end];
		str[end] = c;
		begin++;
		end--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char			*buf;
	int				i;
	unsigned int	res;

	if (n >= 0)
		res = n;
	else
		res = -n;
	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * ft_alloc(n) + 1)))
		return (NULL);
	while (res / 10)
	{
		buf[i] = res % 10 + '0';
		res /= 10;
		i++;
	}
	if (!(res / 10))
		buf[i++] = res + '0';
	if (n < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	return (ft_reverse(buf));
}
