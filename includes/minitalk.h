/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:42:46 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 14:47:30 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
void	allocate_string_memory();
void	store_message(char c);
void	receiver_error(char *str);
void	initialize_container(void);
void	initialize_receiver(void);
void	allocate_container_memory(void);
void	close_program(int signum);

// Functions
int		get_pid(char *str);
void	error(char *str);
int		is_number(char *str);
void	send_char(int server_pid, char c);
void	send_str(int server_pid, char *str);
void	send_int(int server_pid, int len);
void	end_transmission(int server_pid);
void	initialize_transmission(int server_pid, char *str);
void	send_message(int server_pid, char *str);



#endif
