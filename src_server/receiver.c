/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 13:11:34 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

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
		container->len = len;
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
	ft_printf("allocate memory, len = %d\n", container->len);
	int		i;

	if (container->msg)
		free(container->msg);
	container->msg = NULL;
	container->msg = (char *) malloc(sizeof(char) * (container->len + 1));
	if	(!container->msg)
		error("allocation memory failed");
	i = 0;
	while (i < container->len)
	{
		container->msg[i] = '0';
		i++;
	}
	container->msg[container->len] = '\0';
}

// Function to store the received signals in a string
void	store_message(char c)
{
	ft_printf("store_message, c vaut %c: \n", c);
	static int	i = 0;

	if (i == container->len)
	{
		i = 0;
		if (c != '\0')
			error("message is too long according to the len transmitted");
		end_reception();
	}
	else
	{
		container->msg[i] = c;
		i++;
		ft_printf("dans store message, message: %s\n", container->msg);
	}
}

// Function to end the transmission while receiving 8 SIGUSR1 signals
void	end_reception(void)
{
	ft_printf("end_reception\n");
	if (!container || !container->msg)
		error("no message received");
	ft_printf("%s\n", container->msg);
	initialize_receiver();
}