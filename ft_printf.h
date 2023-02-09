/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:25:01 by jecontre          #+#    #+#             */
/*   Updated: 2023/02/09 16:27:12 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Creacion y definicion de la libreria //
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Declaracion de las librerias externas //
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

// Enumeracion o elemento Enum //
enum BASES {
	BASE_10 = 0;
	BASE_16_LOW = 1;
	BASE_16_HIGH = 2;
};

typedef enum BASES t_base;

// Funciones //
int	type_c(char c, int *i);
int	type_s(char *c, int *i);
int	type_di(int n, int *i);
int	type_u_xlow_xup(unsigned int n, int *i, t_base opt);
int	putptr(unsigned long n, int *i);
int	type_p(unsigned long n, int *i);
int	ft_printf(char const *str, ...);
#endif
