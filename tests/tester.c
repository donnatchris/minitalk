/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:31:17 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 16:41:45 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/includes/libft.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Invalid input, 2 arguments are required (one PID and a string).");
		return (1);
	}
	ft_printf("Function testing when transmission is too long.\n");
	kill(ft_atoi(av[1]), SIGUSR1);
	return (0);
}
