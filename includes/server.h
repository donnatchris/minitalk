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
	char		*str;
	int			len;
	int			transmitter;
}				t_msg;

// Variables
extern t_msg	*message;

// Functions
void	initialize_reception(int signum);
void	calculate_len(char c);
void	start_reception(int signum);
void	end_reception(void);
void	allocate_memory();
void	store_message(char c);
void	error(char *str);
void	initialize_message(void);
void	initialize_program(void);
void	allocate_structure_memory(void);


#endif
