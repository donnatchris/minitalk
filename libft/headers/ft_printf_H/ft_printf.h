/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:03:50 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 05:05:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft_H/libft.h"
# include <stdarg.h>

# define FD				1

typedef enum e_type
{
	C,
	S,
	P,
	D,
	I,
	U,
	X_LOW,
	X_UPP,
	PC
}	t_type;

# define NULL_S			"(null)"
# define OX				"0x"
# define LEN_OX 		2
# define NULL_P			"(nil)"
# define BASE_10		"012345678910"
# define LEN_BASE_10	10
# define BASE_16_LOW	"0123456789abcdef"
# define BASE_16_UPP	"0123456789ABCDEF"
# define NULL_HEX   	"(nil)"
# define LEN_BASE_16	16

# define INT_MIN_S	"-2147483648"

typedef struct s_format
{
	int	hashtag;
	int	zero;
	int	hyphen;
	int	blank;
	int	plus;
	int	width;
	int	precision;
	int	specifier;
	int	printed;
}	t_format;

typedef void	(*t_dispatch)(t_format *format, va_list arg);

void		print_format_c(t_format *format, va_list arg);
void		print_format_s(t_format *format, va_list arg);
void		print_format_p(t_format *format, va_list arg);
void		print_format_d(t_format *format, va_list arg);
void		print_format_i(t_format *format, va_list arg);
void		print_format_u(t_format *format, va_list arg);
void		print_format_x_low(t_format *format, va_list arg);
void		print_format_x_upp(t_format *format, va_list arg);
void		print_format_pc(t_format *percent, va_list arg);

int			check_type(char c);
int			check_spec(const char *s);

int			fetch_type(const char *format);
t_format	*init_struct(void);
int			fill_type(const char *s, t_format *format);

int			ft_printf(const char *format, ...);

#endif

//END