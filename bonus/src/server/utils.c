/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:52:22 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 11:05:08 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

// Function to close the program gracefully when receiving SIGINT
void	close_program(int signum)
{
	(void) signum;
	initialize_container();
	if (g_container)
	{
		if (g_container->len_str)
			free(g_container->len_str);
		if (g_container->msg)
			free(g_container->msg);
		free(g_container);
	}
	exit (0);
}

// Function to display an error message and reinitialize the receiver
void	error(char *str)
{
	ft_printf("\x1b[31mERROR:\x1b[0m %s\n", str);
	if (!ft_strncmp(str, "memory allocation failed", ft_strlen(str)))
	{
		initialize_container();
		if (g_container)
		{
			if (g_container->len_str)
				free(g_container->len_str);
			if (g_container->msg)
				free(g_container->msg);
			free(g_container);
		}
		exit(0);
	}
	if (g_container->msg)
		free(g_container->msg);
	initialize_container();
	initialize_len();
}

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

// Function to confirm the reception of each bit to the client
void	confirm_bit_reception(void)
{
	usleep(300);
	kill(g_container->pid, SIGUSR2);
}

// Function to confirm the reception of the entire message
void	confirm_message_reception(void)
{
	usleep(200);
	kill(g_container->pid, SIGUSR1);
}
