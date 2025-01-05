/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:39:18 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 22:32:22 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to allocate memory for the t_msg variable
void	allocate_container_memory(void)
{
	g_container = (t_msg *) malloc(sizeof(t_msg));
	if (!g_container)
	{
		ft_printf("ERROR: allocation memory for container failed");
		exit(1);
	}
}

// Function to initialize the g_container variables
void	initialize_container(void)
{
	if (g_container)
	{
		if (g_container->msg)
		{
			free(g_container->msg);
			g_container->msg = NULL;
		}
		g_container->msg = (char *) ft_calloc(500001, sizeof(char));
		if (!g_container->msg)
		{
			ft_free_container();
			ft_printf("ERROR: allocation memory for container->msg failed");
			exit(1);
		}
		g_container->receive_initializer = 0;
		g_container->store_initializer = 0;
		g_container->signal_received = 0;
		g_container->time = 0;
	}
}

// Function to free the memory allocated for the g_container and its variables
void	ft_free_container(void)
{
	if (g_container)
	{
		if (g_container->msg)
			free(g_container->msg);
		free(g_container);
	}
}
