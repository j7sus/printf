/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:23:48 by jecontre          #+#    #+#             */
/*   Updated: 2023/02/06 15:16:01 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*i = (*i + 1);
	return (*i);
}

int	type_s(char *c, int *i)
{
	int	j;

	j = 0;
	if (!c)
		c = "(null)";
	while (c[j] != '\0')
	{
		if (type_c(c[j], i) == -1)
			return (-1);
		j++;
	}
	return (*i);
}
