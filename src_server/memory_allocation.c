/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:39:18 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 18:22:50 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to allocate memory for the t_msg variable
void	allocate_container_memory(void)
{
	ft_printf("allocate_container_memory\n");
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
	ft_printf("initialize_container\n");
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
			ft_free_container(container);
			ft_printf("ERROR: allocation memory for container failed");
			exit(1);
		}
		container->receive_initializer = 0;
		container->store_initializer = 0;
	}
	ft_printf("receive_initializer = %d \n", container->receive_initializer );
	ft_printf("store_initializer = %d \n", container->store_initializer );
}

// Function to free the memory allocated for the container and its variables
void	ft_free_container(t_msg *container)
{
	ft_printf("ft_free_container\n");
	if (container)
	{
		if (container->msg)
			free(container->msg);
		free(container);
	}
}
