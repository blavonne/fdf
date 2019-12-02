/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:03:52 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/14 15:24:11 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*obj;

	if (size + 1 == 0)
		return (NULL);
	obj = 0;
	if (!(obj = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(obj, size + 1);
	return (obj);
}
