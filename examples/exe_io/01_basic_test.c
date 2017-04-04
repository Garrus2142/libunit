/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:30:49 by thugo             #+#    #+#             */
/*   Updated: 2017/04/04 21:17:56 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	exe_io_basic_test(int in, int out)
{
	char	buffer[255];
	int		ret;

	dprintf(in, "coucou\n");
	if ((ret = read(out, buffer, 255)) != 15)
		return (-1);
	if (memcmp(buffer, "in->out>coucou\n", 15))
		return (-1);
	dprintf(in, "exit\n");
	return (0);
}
