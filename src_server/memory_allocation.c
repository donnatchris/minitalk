/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:39:18 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 17:37:18 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to allocate memory for the t_msg variable
void	allocate_container_memory(void)
{
	container = (t_msg *) malloc(sizeof(t_msg));
	if (!container)
	{
		ft_printf("ERROR: allocation memory for container failed");
		exit(1);
	}
}

// Function to initialize the container variables
void	initialize_container(void)
{
	if (container)
	{
		if (container->msg)
		{
			free(container->msg);
			container->msg = NULL;
		}
		container->msg = (char *) ft_calloc(500001, sizeof(char));
		if (!container->msg)
		{
			ft_free_container();
			ft_printf("ERROR: allocation memory for container failed");
			exit(1);
		}
		container->receive_initializer = 0;
		container->store_initializer = 0;
		container->signal_received = 0;
		container->time = 0;
	}
}

// Function to free the memory allocated for the container and its variables
void	ft_free_container(void)
{
	if (container)
	{
		if (container->msg)
			free(container->msg);
		free(container);
	}
}
