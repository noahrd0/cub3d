/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:02:34 by nradal            #+#    #+#             */
/*   Updated: 2023/07/31 18:51:02 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*gnl_read_to_left_str(int fd, char *left_str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *left_str, char *buff);
size_t	gnl_strlen(char *s);
char	*gnl_get_line(char *left_str);
char	*gnl_new_left_str(char *left_str);

#endif
