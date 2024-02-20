/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:36:58 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 23:37:57 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *next_line;
    int     count;

    count = 0; 
    fd = open("example.txt, O_RDONLY");
    next_line = get_next_line_basic(fd);
    count++;
    printf("[%d]: %s\n", count, next_line);
    next_line = NULL;

    close(fd);
    return (0);
}