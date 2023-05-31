/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:05:53 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/11/21 17:08:19 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int num, int *len)
{
	if (num == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putchar_len('-', len);
		ft_putnbr_len(num * -1, len);
	}
	else
	{
		if (num > 9)
			ft_putnbr_len(num / 10, len);
		ft_putchar_len(num % 10 + 48, len);
	}
}

void	ft_putunsign(unsigned int num, int *len)
{
	if (num >= 10)
	{
		ft_putunsign(num / 10, len);
		ft_putunsign(num % 10, len);
	}
	else
		ft_putchar_len(num + 48, len);
}

void	ft_puthexa(unsigned long long num, char *base, int	*len)
{
	if (num >= 16)
	{
		ft_puthexa(num / 16, base, len);
		ft_puthexa(num % 16, base, len);
	}
	else
		ft_putchar_len(base[num], len);
}
