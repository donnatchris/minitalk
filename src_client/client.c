/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:49:48 by christophed       #+#    #+#             */
/*   Updated: 2025/01/07 15:01:20 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// Function to display an error message and exit the program
void	error(char *str)
{
	ft_printf("\x1b[31mERROR:\x1b[0m %s\n", str);
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
	ft_printf("%d\n", pid);
	return (pid);
}

// Function confirm that the server has answered
void	confirmation(int signum)
{
	(void) signum;
	ft_printf("\x1b[32mMessage sent. \x1b[0m");
	ft_printf("\x1b[32mServer has confirmed by sending a signal.\x1b[0m\n");
	exit(0);
}
