/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:36:25 by jecontre          #+#    #+#             */
/*   Updated: 2023/02/06 16:00:16 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_types(va_list args, char const type, int *count)
{
	if (type == '%')
		*count = type_c('%', count);
	if (type == 'c')
		*count = type_c(va_arg(args, int), count);
	if (type == 's')
		*count = type_s(va_arg(args, char *), count);
	if (type == 'd' || type == 'i')
		*count = type_di(va_arg(args, int), count);
	if (type == 'u')
		*count = type_u_xlow_xup(va_arg(args, unsigned int), count, 0, 10);
	if (type == 'x')
		*count = type_u_xlow_xup(va_arg(args, unsigned int), count, 1, 16);
	if (type == 'X')
		*count = type_u_xlow_xup(va_arg(args, unsigned int), count, 2, 16);
	if (type == 'p')
		*count = type_p(va_arg(args, unsigned long int), count);
	return (*count);
}

int	ft_checking(va_list args, char const *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_types(args, str[i + 1], count) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (type_c(str[i], count) == -1)
				return (-1);
		}
		i++;
	}
	return (*count);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	if (ft_checking(args, str, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}
