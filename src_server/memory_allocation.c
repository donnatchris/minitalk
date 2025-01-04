/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:39:18 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 13:43:33 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

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

// Function to initialize the container by setting variables to 0 or NULL
// and freeing memories allocated inside the container
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
		receiver_error("allocation memory failed");
	i = 0;
	while (i < container->len)
	{
		container->msg[i] = '0';
		i++;
	}
	container->msg[container->len] = '\0';
}
