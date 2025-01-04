/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:50:53 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 13:29:05 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to display an error message and exit the program
void	error(char *str)
{
	ft_printf("error\n");
	ft_printf("ERROR: %s\n", str);
	initialize_receiver();
}

// Function to check if a string is a number
int	is_number(char *str)
{
	ft_printf("is_number\n");
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Function to close the program gracefully when receiving SIGINT
void	close_program(int signum)
{
	ft_printf("\nCaught signal %d (SIGINT). Freeing memory before closing gracefully.\n", signum);
	if (container)
	{
		if (container->msg)
			free(container->msg);
		free(container);
	}
	exit(0);
}
