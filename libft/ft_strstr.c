/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:52:53 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/14 15:24:11 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*begin;
	char	*tmp;

	tmp = (char *)needle;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			begin = (char *)haystack;
			while (*haystack++ == *needle++)
				if (!*needle)
					return ((char *)begin);
			if (needle + 1 && needle + 1 != haystack + 1)
			{
				haystack = begin;
				needle = tmp;
			}
		}
		haystack++;
	}
	return (NULL);
}
