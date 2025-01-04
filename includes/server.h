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

// Variables
extern char	*message;

// Functions
void	initialize_reception(int signum);
void	calculate_len(char c);
void	start_reception(int signum);
void	end_reception(void);
void	allocate_memory(int len);
void	store_message(char c);

#endif
