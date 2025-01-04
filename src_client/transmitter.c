/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:06:13 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 18:08:41 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// Function to send a message to the server
void	send_message(int server_pid, char *str)
{
	send_pid(server_pid, getpid());
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

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(150);
		i++;
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
// If the pid is less than 10 characters long, we send 0 until the pid is 10 characters long
void	send_pid(int server_pid, int client_pid)
{
	long	backup;
	char	*pid;

	backup = (long) client_pid;
	while (backup < 1000000000)
	{
		send_char(server_pid, '0');
		backup *= 10;
	}
	pid = ft_itoa(client_pid);
	if (!pid)
		error("memory allocation failed.");
	send_str(server_pid, pid);
	free(pid);
}
