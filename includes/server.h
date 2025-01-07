/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:00:36 by christophed       #+#    #+#             */
/*   Updated: 2025/01/07 14:50:31 by chdonnat         ###   ########.fr       */
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
	char	*len_str;
	int		pid;
	int		len;
}			t_msg;

// Global variable
extern t_msg	*g_container;

// Functions
void	close_program(int signum);
void	initialize_container(void);
void	error(char *str);
void	initialize_len(void);
void    check_msg_len(int signum, siginfo_t *info, void *context);
void	confirm_bit_reception(void);
void    store_msg_len(char c);
void    initialize_msg(void);
void    receive_msg(int signum, siginfo_t *info, void *context);
void    store_msg(char c);
void	end_reception(void);
int		is_number(char *str);


#endif