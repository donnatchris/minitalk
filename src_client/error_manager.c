/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:49:48 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 20:06:45 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

// Function to display an error message and exit the program
void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
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
