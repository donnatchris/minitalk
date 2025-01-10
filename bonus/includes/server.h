/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:19:30 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/10 00:24:39 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../../libft/headers/libft_H/libft.h"

// Structures
typedef struct s_msg
{
	char	*msg;
	char	*len_str;
	int		pid;
	int		len;
	int		chrono_on;
	int		time;
	int		check_msg_len;
	int		store_msg_len;
	int		receive_msg;
	int		store_msg;
	int		check_bit;
}			t_msg;

// Global variable
extern t_msg	*g_container;

// Functions
void	close_program(int signum);
void	initialize_container(void);
void	error(char *str);
void	initialize_len(void);
void	check_msg_len(int signum, siginfo_t *info, void *context);
void	confirm_bit_reception(void);
void	store_msg_len(char c);
void	initialize_msg(void);
void	receive_msg(int signum, siginfo_t *info, void *context);
void	store_msg(char c);
void	end_reception(void);
int		is_number(char *str);
void	confirm_message_reception(void);

#endif
