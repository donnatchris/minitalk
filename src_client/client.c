/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:15:19 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 20:06:12 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// Function to check if a string is a positive number and return it
int	get_pid(char *str)
{
	int		pid;

	if (!is_number(str))
		error("Invalid PID, only numbers are allowed.");
	pid = ft_atoi(str);
	if (pid < 1)
		error("Invalid PID, only positive numbers are allowed.");
	if (kill(pid, 0) == -1)
		error("Invalid PID, the process does not exist.");
	
	return (pid);
}
