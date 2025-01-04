/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:49:48 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 18:00:15 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// Function to display an error message and exit the program
void	error(char *str)
{
	ft_printf("ERROR: %s\n", str);
	exit(1);
}

// Function to check if a string is a number
int	is_number(char *str)
{
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

// Function to check if a string is a positive number and return it
int	check_pid(char *str)
{
	int		pid;

	if (!is_number(str))
		error("Invalid PID, only numbers are allowed.");
	pid = ft_atoi(str);
	if (pid < 0)
		error("Invalid PID, only positive numbers are allowed.");
	if (kill(pid, 0) == -1)
		error("Invalid PID, the process does not exist.");
	return (pid);
}
