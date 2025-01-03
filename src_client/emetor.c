/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emetor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:06:13 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 19:57:15 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// Function to send a signal to the server using only 0 and 1
// The signal is sent bit by bit
// If the bit is 1, the signal is SIGUSR2
// If the bit is 0, the signal is SIGUSR1
void	send_ascii(int server_pid, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & 1 << j)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			say("Signal sent");
			usleep(100);
			j++;
		}
		i++;
	}
}

// Function to end the transmission by sending 8 SIGUSR1 signals
void	end_transmission(int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(server_pid, SIGUSR1);
		say("Signal sent");
		usleep(100);
		i++;
	}
}