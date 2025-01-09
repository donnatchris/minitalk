/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:40:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:24:29 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}						t_list_gnl;

int			search_newline(t_list_gnl *store);
t_list_gnl	*ft_lstlast_gnl(t_list_gnl *store);
char		*fetch_queue(t_list_gnl *store);
void		cpylst_to_str(t_list_gnl *store, char *queue);
int			lstlen_till_newline(t_list_gnl *store);
void		cutting_in(t_list_gnl **store);
void		free_store(t_list_gnl **store, t_list_gnl *clean, char *product);
void		stock_replenishment(t_list_gnl **store, char *product, int fd);
int			inventory(t_list_gnl **store, int fd);
char		*get_next_line(int fd);

#endif

//END
