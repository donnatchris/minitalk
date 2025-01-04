/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 12:31:57 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to store the received signals in a char
// void	receive_ascii(int signum)


// Function to initialize the reception of a signal
void	initialize_reception(int signum)
{
	ft_printf("initialize_reception\n");
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		calculate_len(c);
		i = 0;
		c = 0;
	}
}

// Function to store the first 6 characters of the received signals in an int
void	calculate_len(char c)
{
	ft_printf("calculate_len\n");
	static int		i = 0;
	static char		str[7];
	int				len;

	str[i] = c;
	if (i == 5)
	{
		str[6] = '\0';
		i = 0;
		len = ft_atoi(str);
		if (len == 0 || len > 999999)
			error("message len must be between 1 and 999999 caracters");
		message->len = len;
		i = 0;
		allocate_memory();
		signal(SIGUSR1, start_reception);
		signal(SIGUSR2, start_reception);
	}
	i++;
}

// Function to store the received signals in a string
void	start_reception(int signum)
{
	ft_printf("start_reception\n");
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		store_message(c);
		i = 0;
		c = 0;
	}
}

// Function to allocate memory for the string and initialize it
void	allocate_memory(void)
{
	ft_printf("allocate memory, len = %d\n", message->len);
	int		i;

	if (message->str)
		free(message->str);
	message->str = NULL;
	message->str = (char *) malloc(sizeof(char) * (message->len + 1));
	if	(!message->str)
		error("allocation memory failed");
	i = 0;
	while (i < message->len)
	{
		message->str[i] = '0';
		i++;
	}
	message->str[message->len] = '\0';
}

// Function to store the received signals in a string
void	store_message(char c)
{
	ft_printf("store_message, c vaut %c: \n", c);
	static int	i = 0;

	if (i == message->len)
	{
		i = 0;
		if (c != '\0')
			error("message is too long according to the len transmitted");
		end_reception();
	}
	else
	{
		message->str[i] = c;
		i++;
		ft_printf("dans store message, message: %s\n", message->str);
	}
}

// Function to end the transmission while receiving 8 SIGUSR1 signals
void	end_reception(void)
{
	ft_printf("end_reception\n");
	if (!message || !message->str)
		error("no message received");
	ft_printf("%s\n", message->str);
	initialize_program();
}