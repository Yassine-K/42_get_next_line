/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:49:39 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/19 17:53:36 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define B_S 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# if BUFFER_SIZE < 0
#  undef B_S
#  define B_S -BUFFER_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE B_S
#  undef B_S
#  define B_S -1
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);

#endif
