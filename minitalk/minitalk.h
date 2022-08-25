/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:10:03 by jboo              #+#    #+#             */
/*   Updated: 2022/08/25 15:10:04 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

int		chk_sign(const char *str);
int		check_char(char str, int *flag, unsigned long long *result);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcpy(char *dest, char *src, unsigned int size);

#endif