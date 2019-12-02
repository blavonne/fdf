/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:57:28 by azomega           #+#    #+#             */
/*   Updated: 2019/09/16 14:08:40 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!s || !(ret = ft_strnew(len)))
		return (0);
	while (i++ < len)
		ret[i - 1] = s[i - 1 + (size_t)start];
	ret[i - 1] = '\0';
	return (ret);
}
