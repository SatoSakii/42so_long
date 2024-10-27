/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:39:56 by albernar          #+#    #+#             */
/*   Updated: 2024/10/10 02:39:57 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_writepointer(void *ptr, int is_rec, char *base)
{
	size_t	tmp_ptr;
	size_t	result;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	result = 0;
	if (!is_rec)
	{
		ft_putstr_fd("0x", 1);
		result += 2;
	}
	tmp_ptr = (size_t)ptr;
	if (tmp_ptr > 15)
		result += ft_writepointer((void *)(tmp_ptr / 16), 1, base);
	result += 1;
	ft_putchar_fd(base[tmp_ptr % 16], 1);
	return (result);
}

int	ft_putnbr_fd(long long n, int fd)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		res += ft_putchar_fd('-', fd);
		res += ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			res += ft_putnbr_fd(n / 10, fd);
		res += ft_putchar_fd(n % 10 + '0', fd);
	}
	return (res);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
