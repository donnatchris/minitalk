/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 21:02:38 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to store the received signals in a char
// void	receive_ascii(int signum)


// Function to handle the reception of a signal
void	receive_ascii(int signum)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c)
			ft_printf("%c", c);
		else
			end_transmission();
		i = 0;
		c = 0;
	}
}

// Function to end the transmission while receiving 8 SIGUSR1 signals
void	end_transmission(void)
{
	ft_printf("\n");
}