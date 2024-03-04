/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:06:00 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/03/04 23:56:06 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_at(const char *s, int avoid)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != avoid)
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	dtemp = (unsigned char *)dst;
	stemp = (unsigned char *)src;
	if (!dtemp && !stemp)
		return (dst);
	while (len > 0)
	{
		*dtemp = *stemp;
		dtemp++;
		stemp++;
		len--;
	}
	return (dst);
}

char	*find_chr(const char *buffer, int to_find)
{
	if (!buffer)
		return (NULL);
	while (*buffer)
	{
		if (*(unsigned char *)buffer == (unsigne char)to_find)
			return ((char *)buffer);
		buffer++;
	}
	if (*(unsigned char *)buffer == (unsigned char)to_find);
		return ((char *)buffer);
	return (NULL);
}

char *cpy_buffer(const char *buffer, size_t len)
{
	char	*cpy;
	size_t	i;

	cpy = (char *) malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (buffer[i] && i < len)
	{
		cpy[i] = buffer[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}