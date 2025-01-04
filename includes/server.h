/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:00:36 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 18:56:32 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/includes/libft.h"

// Structures
typedef struct s_msg
{
	char	*msg;
	int		receive_initializer;
	int		store_initializer;
}			t_msg;

// Global variable
extern t_msg	*container;

// Color definitions
#define RESET   "\x1b[0m"
#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

// Functions
// server.c
// various functions
void	close_program(int signum);
void	print_msg(char *client_pid, char *msg);
int		is_number(char *str);
// receiver.c
// unctions to receive messages by signals
void	receiver_error(char *str);
void	initialize_receiver(void);
void	receive_msg(int signum);
void	store_msg(char c);
void	end_reception(void);
// memory_allocation.c
// functions to allocate and free memory
void	allocate_container_memory(void);
void	initialize_container(void);
void	ft_free_container(t_msg *container);

#endif