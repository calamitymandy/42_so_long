/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:50:39 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/11/22 15:48:43 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(va_list args, const char str, int *len)
{
	if (str == 'c')
		ft_putchar_len(va_arg(args, int), len);
	else if (str == '%')
		ft_putchar_len('%', len);
	else if (str == 'd' || str == 'i')
		ft_putnbr_len(va_arg(args, int), len);
	else if (str == 'u')
		ft_putunsign(va_arg(args, unsigned int), len);
	else if (str == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (str == 'x')
		ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (str == 'X')
		ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEFG", len);
	else if (str == 'p')
	{
		ft_putstr("0x", len);
		ft_puthexa(va_arg(args, unsigned long long), "0123456789abcdef", len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_check_type(args, str[i + 1], &len);
			i++;
		}
		else
		{
			ft_putchar_len(str[i], &len);
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	char	test_c = 'x';
	char	test_percent = 'x';
	int		test_di = -2147483648;
	int		test_u = 214748364;
	char	test_s[] = "va chier des bulles";
	int		test_x = 2245845;
	int		test_X = 22978695;
	int		test_p = 22978695;
	
	ft_printf("%c\n", test_c);
	ft_printf("%%\n", test_percent);
	ft_printf("%d\n", test_di);
	ft_printf("%u\n", test_u);
	ft_printf("%s\n", test_s);
	ft_printf("%x\n", test_x);
	ft_printf("%X\n", test_X);
	ft_printf("%p\n", test_p);
	ft_printf("ceci est un test");
	
}*/