/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:26:30 by thugo             #+#    #+#             */
/*   Updated: 2017/03/30 23:53:23 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

int		putstr_basic_test(int in, int out)
{
	char	buffer[255];
	int		size;

	(void)in;
	ft_putstr("coucou");
	size = read(out, buffer, 255);
	if (size != 6 || memcmp(buffer, "coucou", 6) != 0)
		return (-1);

	ft_putstr("salut\0encore");
	size = read(out, buffer, 255);
	if (size != 5 || memcmp(buffer, "salut", 5) != 0)
		return (-1);
	return (0);
}
