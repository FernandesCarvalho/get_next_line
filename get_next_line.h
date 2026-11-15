/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 01:00:01 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/14 11:24:37 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef SEPARATOR
#  define SEPARATOR '\n'
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_read_stash(char *stash, char *buffer, int fd);
char	*ft_extract_line(char *stash);
char	*ft_update_stash(char *stash);
char	*ft_strjoin(char const *s1, char const *s2);

#endif