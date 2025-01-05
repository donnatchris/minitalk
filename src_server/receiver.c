/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 15:29:40 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to display an error message and reinitialize the receiver
void	receiver_error(char *str)
{
	ft_printf("RECEPTION ERROR: %s\n", str);
	initialize_receiver();
}

// Function to initialize the receiver
// by initializing the container and the signals
void	initialize_receiver(void)
{
	initialize_container();
	signal(SIGUSR1, wait_for_ping);
	signal(SIGUSR2, wait_for_ping);
}

// Function to receive a message bit by bit
// and send each complete caracter to the store_msg function
void	receive_msg(int signum)
{
	static char	c = 0;
	static int	i = 0;

	if (container->receive_initializer == 0)
	{
		c = 0;
		i = 0;
		container->receive_initializer = 1;
	}
	if (signum == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		store_msg(c);
		i = 0;
		c = 0;
	}
}

// Function to store the received message in a string
// until a '\0' character is received
void	store_msg(char c)
{
	static int	i = 0;

	if (container->store_initializer == 0)
	{
		i = 0;
		container->store_initializer = 1;
	}
	container->msg[i] = c;
	i++;
	if (c == '\0')
		end_reception();
	if (i == 500000)
		receiver_error("message too long");
}

// Function to end the transmission by answering the client,
// printing the received message in the terminal
// and reinitialize the receiver
void	end_reception(void)
{
	int		len;
	char	*client_pid;
	char	*msg;

	len = ft_strlen(container->msg);
	client_pid = ft_substr(container->msg, 0, 10);
	if (client_pid == NULL)
		receiver_error("allocation memory for PID failed");
	msg = ft_substr(container->msg, 10, len - 10);
	if (msg == NULL)
	{
		free(client_pid);
		receiver_error("allocation memory for message failed");
	}
	usleep(100);
	if (!is_number(client_pid) || kill(ft_atoi(client_pid), SIGUSR1) == -1)
	{
		free(msg);
		free(client_pid);
		receiver_error("Invalid PID");
	}
	print_msg(client_pid, msg);
	initialize_receiver();
}
