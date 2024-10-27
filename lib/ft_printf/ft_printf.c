/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:34:56 by albernar          #+#    #+#             */
/*   Updated: 2024/10/09 21:37:15 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_hex(unsigned int n, char *base)
{
	int	result;

	result = 0;
	if (n > 15)
		result += ft_convert_hex(n / 16, base);
	result += ft_putchar_fd(base[n % 16], 1);
	return (result);
}

static size_t	ft_searchparams(char param, va_list args)
{
	if (param == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (param == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (param == 'p')
		return (ft_writepointer(va_arg(args, void *), 0, "0123456789abcdef"));
	else if (param == 'd' || param == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (param == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1));
	else if (param == 'x')
		return (ft_convert_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (param == 'X')
		return (ft_convert_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (param == '%')
		return (ft_putchar_fd('%', 1));
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(param, 1);
		return (1 + ft_strlen(&param));
	}
	return (0);
}

static int	ft_isvalidparams(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	len = 0;
	while (*s)
	{
		if (*s == '%' && ft_isvalidparams(*(s + 1)))
		{
			len += ft_searchparams(*(s + 1), args);
			s++;
		}
		else
		{
			len += 1;
			write(1, &(*s), 1);
		}
		s++;
	}
	va_end(args);
	return (len);
}
