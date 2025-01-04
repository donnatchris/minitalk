/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 15:06:33 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// Function to initialize program
void	initialize_receiver(void)
{
	ft_printf("initialize_receiver\n");
	initialize_container();
	signal(SIGUSR1, initialize_reception);
	signal(SIGUSR2, initialize_reception);
}

// Function to display an error message and reinitialize the receiver
void	receiver_error(char *str)
{
	ft_printf("RECEPTION ERROR: %s\n", str);
	initialize_receiver();
}

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
	static char		str[11];
	int				len;

	str[i] = c;
	if (i == 9)
	{
		str[10] = '\0';
		i = 0;
		len = ft_atoi(str);
		if (len == 0 || len > 999999)
			receiver_error("message len must be between 1 and 999999 caracters");
		container->len = len;
		i = 0;
		allocate_string_memory();
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

// Function to store the received signals in a string
void	store_message(char c)
{
	ft_printf("store_message, c vaut %c: \n", c);
	static int	i = 0;

	container->msg[i] = c;
	i++;
	ft_printf("dans store message, message: %s\n", container->msg);
	if (i == container->len)
	{
		i = 0;
		end_reception();
	}
}

// Function to end the transmission while receiving 8 SIGUSR1 signals
void	end_reception(void)
{
	ft_printf("end_reception\n");
	if (!container || !container->msg)
		receiver_error("no message received");
	ft_printf("%s\n", container->msg);
	initialize_receiver();
}
