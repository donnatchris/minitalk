/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 10:40:08 by christophed      ###   ########.fr       */
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
	static int	i = 0;
	static char		str[7];
	int			len;

	str[i] = c;
	if (i == 5)
	{
		str[6] = '\0';
		i = 0;
		len = ft_atoi(str);
		if (len == 0 || len > 999999)
			end_reception(); // need to handle errors
		i = 0;
		allocate_memory(len);
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
	static int	j = 0;
	int			len;

	len = ft_strlen(message);
	ft_printf("dans start reception len du message: %d\n", len);
	if (signum == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		store_message(c);
		i = 0;
		c = 0;
	}
	if (j == len)
	{
		end_reception();
	}
}

// Function to end the transmission while receiving 8 SIGUSR1 signals
void	end_reception(void)
{
	ft_printf("end_reception\n");
	if (message)
	{
		ft_printf("%s\n", message);
		free(message);
		message = NULL;
	}
}

// Function to allocate memory for the string and initialize it
void	allocate_memory(int len)
{
	ft_printf("allocate memory, len = %d\n", len);
	int		i;

	if (message)
		free(message);
	message = NULL;
	message = (char *) malloc(sizeof(char) * (len + 1));
	if	(!message)
		end_reception(); // need to handle errors
	i = 0;
	while (i < len)
	{
		message[i] = '0';
		i++;
	}
	message[len] = '\0';
	ft_printf("dans allocate memory, message: %s\n", message);
}

void	store_message(char c)
{
	ft_printf("store_message\n");
	static int	i = 0;
	int			len;

	len = ft_strlen(message);
	ft_printf("dans store message len du message: %d\n", len);
	message[i] = c;
	i++;
	ft_printf("dans store message, message: %s\n", message);
}