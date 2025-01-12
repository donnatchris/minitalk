/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:36:21 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/12 10:32:20 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

// Function to send a message to the server
void	send_message(int server_pid, char *str)
{
	send_len(server_pid, ft_strlen(str));
	send_str(server_pid, str);
	send_char(server_pid, '\0');
}

// Function to send a character to the server using only 0 and 1
// The signal is sent bit by bit
// If the bit is 1, the signal is SIGUSR2
// If the bit is 0, the signal is SIGUSR1
void	send_char(int server_pid, char c)
{
	int	i;
	int	timer;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i++;
		g_client->confirmed = 0;
		timer = 0;
		while (!g_client->confirmed)
		{
			usleep(100);
			timer++;
			if (timer >= 1000)
				error("Server did not confirm. Communication have failed.");
		}
	}
}

// Function to send a string to the server using only 0 and 1
void	send_str(int server_pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
}

// Function to send our own pid (in a 10 characters format) to the server
// If the pid is less than 10 characters long,
// we send 0 until the pid is 10 characters long
void	send_len(int server_pid, int len)
{
	long	backup;
	char	*msg_len;

	backup = (long) len;
	while (backup < 1000000000)
	{
		send_char(server_pid, '0');
		backup *= 10;
	}
	msg_len = ft_itoa(len);
	if (!msg_len)
		error("memory allocation failed.");
	send_str(server_pid, msg_len);
	free(msg_len);
}
