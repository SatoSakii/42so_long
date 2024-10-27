/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:35:17 by albernar          #+#    #+#             */
/*   Updated: 2024/10/09 21:35:44 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_fd(long long n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_writepointer(void *ptr, int is_rec, char *base);
size_t	ft_strlen(char *str);

#endif
