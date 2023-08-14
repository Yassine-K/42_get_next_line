/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:41 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/19 17:53:24 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
