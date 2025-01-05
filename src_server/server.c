/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:36:15 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 21:24:21 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to check if a string is a number
int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Function to close the program gracefully when receiving SIGINT
void	close_program(int signum)
{
	ft_printf("\nCaught signal %d (SIGINT). Freeing memory before closing gracefully.\n", signum);
	if (container)
	{
		if (container->msg)
			free(container->msg);
		free(container);
	}
	exit(0);
}

void	print_msg(char *client_pid, char *msg)
{
	ft_printf("Message received from client PID number %s :\n", client_pid);
	free(client_pid);
	ft_printf(YELLOW "%s" RESET "\n", msg);
	free(msg);
}

// Function to wait for a signal
void	wait_for_ping(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		container->signal_received = 1;
		ft_printf("Signal received, waiting for message...\n");
		signal(SIGUSR1, receive_msg);
		signal(SIGUSR2, receive_msg);
	}
}