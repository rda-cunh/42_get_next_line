/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_basic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:40:25 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/02/21 23:08:44 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_basic.h"

char    *get_next_line_basic(int fd)
{
int     bytes_read;
char    *cup_buffer;

cup_buffer = malloc (3 + 1 * sizeof(char));
if (cup_buffer == NULL)
    return (NULL);
bytes_read = read(fd, cup_buffer, 3);
if (bytes_read <= 0)
    return (NULL);
return (cup_buffer);
}
