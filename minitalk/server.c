/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:20:12 by jboo              #+#    #+#             */
/*   Updated: 2022/08/25 15:20:13 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	result;
	static int	count = 0;

	result *= 2;
	if (signal == SIGUSR2)
		++result;
	if (count == 7)
	{
		ft_printf("%c", result);
		count = 0;
		result = 0;
		return ;
	}
	++count;
}

int	main(void)
{
	ft_printf("server PID : %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
