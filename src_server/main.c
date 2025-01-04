/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 13:27:08 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg	*container;

int	main(void)
{
	allocate_container_memory();
	initialize_receiver();
	signal(SIGINT, close_program);
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		;
	}
	return (0);
}

// Function to allocate memory for the t_msg variable
void	allocate_container_memory(void)
{
	ft_printf("allocate_container_memory\n");
	if (!container)
	{
		container = (t_msg *) malloc(sizeof(t_msg));
		if (!container)
		{
			ft_printf("ERROR: allocation memory for container failed");
			exit(1);
		}
	}
}

// Function to initialize the message variable
void	initialize_container(void)
{
	ft_printf("initialize_message\n");
	if (container)
	{
		if (container->msg)
		{
			free(container->msg);
			container->msg = NULL;
		}
		container->len = 0;
		container->transmitter = 0;
	}
}

// Function to initialize program
void	initialize_receiver(void)
{
	ft_printf("initialize_program\n");
	initialize_container();
	signal(SIGUSR1, initialize_reception);
	signal(SIGUSR2, initialize_reception);
}