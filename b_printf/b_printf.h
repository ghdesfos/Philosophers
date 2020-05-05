/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:22:31 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/10/31 15:03:03 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		format_handler_sub(va_list ap, char conv);
int		format_handler(va_list ap, char conv);
int		b_printf(const char *restrict format, ...);

int		b_printf_ft_putchar(char c);
int		b_printf_ft_putstr(char *str);
int		b_printf_ft_putnbr(int n);
char	*b_printf_ft_b_base(long n, int base);

#endif
