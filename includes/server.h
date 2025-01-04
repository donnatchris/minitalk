/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:21:33 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 15:26:29 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/includes/libft.h"

// Structures
typedef struct s_msg
{
	char		*msg;
	int			len;
	int			transmitter;
}				t_msg;

// Variables
extern t_msg	*container;

// Functions
void	initialize_reception(int signum);
void	calculate_len(char c);
void	start_reception(int signum);
void	end_reception(void);
void	allocate_memory();
void	store_message(char c);
void	receiver_error(char *str);
void	initialize_container(void);
void	initialize_receiver(void);
void	allocate_container_memory(void);
void	close_program(int signum);


#endif
