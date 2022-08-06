/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:54:44 by jboo              #+#    #+#             */
/*   Updated: 2022/08/06 14:55:56 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*join_and_check(char **back_up, char *buffer_read);
char	*make_return(char **back_up);
char	*chk_back_up(char **back_up);
int		ft_strlen(char *str);
int		chk_nl(char *back_up);
void	clean_back_up(char **back_up, int nl_index);
void	reset_buffer(char *buffer_read);
size_t	ft_strlcpy(char *dest, char *src, unsigned int size);

#endif
