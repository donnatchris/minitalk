/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 12:29:54 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg	*message;

int	main(void)
{
	ft_printf("SERVER PID: %d\n", getpid());
	allocate_structure_memory();
	initialize_program();
	while (1)
	{
		;
	}
	return (0);
}

// Function to allocate memory for the t_msg variable
void	allocate_structure_memory(void)
{
	ft_printf("allocate_structure_memory\n");
	if (!message)
	{
		message = (t_msg *) malloc(sizeof(t_msg));
		if (!message)
			error("allocation memory failed");
	}
}

// Function to initialize the message variable
void	initialize_message(void)
{
	ft_printf("initialize_message\n");
	if (message)
	{
		if (message->str)
		{
			free(message->str);
		}
		message->len = 0;
		message->transmitter = 0;
	}
}

// Function to initialize program
void	initialize_program(void)
{
	ft_printf("initialize_program\n");
	initialize_message();
	signal(SIGUSR1, initialize_reception);
	signal(SIGUSR2, initialize_reception);
}