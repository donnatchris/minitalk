/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:06:13 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 21:04:42 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"


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
		usleep(100);
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

// Function to send an integer (from 1 to 999999) to the server using only 0 and 1
void	send_len(int server_pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	if (i < 6)
	{
		while (i < 6)
		{
			send_char(server_pid, 0);
			i++;
		}
	}
}

// Function to send the len of the string to the server
void	initialize_transmission(int server_pid, char *str)
{
	int	len;

	len = (int) ft_strlen(str);
	if (len < 1)
		error("The string is empty.");
	if (len > 999999)
		error("The string is too long.");
	send_len(server_pid, ft_itoa(len));
}

// Function to end the transmission by sending 8 SIGUSR1 signals
void	end_transmission(int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(server_pid, SIGUSR1);
		usleep(100);
		i++;
	}
}
