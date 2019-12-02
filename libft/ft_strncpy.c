/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:27:03 by azomega           #+#    #+#             */
/*   Updated: 2019/09/18 16:33:44 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	print_o;

	i = 0;
	print_o = 0;
	while (i++ < n)
		if ((print_o == 0) && src[i - 1])
			dest[i - 1] = src[i - 1];
		else
		{
			print_o = 1;
			dest[i - 1] = '\0';
		}
	return (dest);
}
