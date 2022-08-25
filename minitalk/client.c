/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:14:47 by jboo              #+#    #+#             */
/*   Updated: 2022/08/25 16:14:48 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int server_pid, char *message)
{
	int	message_len;
	int	i;	
	int	bit_count;
	int	bit;

	message_len = ft_strlen(message);
	i = -1;
	while (++i < (int)message_len)
	{
		bit_count = 8;
		while (--bit_count >= 0)
		{
			bit = (int)message[i] >> bit_count & 1;
			if (!bit)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(20);
		}
		usleep(20);
		//usleep 시간 설정
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("More or less arguments.");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	message = ft_strjoin(argv[2], "\n");
	if (!message)
		return (0);
	send_message(server_pid, message);
	free(message);
	return (0);
}
