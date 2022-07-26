/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:05 by wyu               #+#    #+#             */
/*   Updated: 2022/07/26 21:55:16 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef FD_SIZE
#  define FD_SIZE 256
# endif

// get_next_line.c
char			*get_next_line(int fd);

// get_next_line_uils.c
char			*ft_strjoin_gnl(char const *s1, char const *s2);
#endif
