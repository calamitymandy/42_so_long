/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:46:25 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/11/21 17:00:59 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// C libraries

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

// Prototypes

int		ft_printf(const char *str, ...);

void	ft_putchar_len(char c, int *len);
void	ft_putstr(char	*str, int *len);

void	ft_putnbr_len(int num, int *len);
void	ft_putunsign(unsigned int num, int *len);
void	ft_puthexa(unsigned long long num, char *base, int *len);

#endif
