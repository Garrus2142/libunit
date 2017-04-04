/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:14:26 by thugo             #+#    #+#             */
/*   Updated: 2017/04/04 21:46:30 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"
#include "exe_io.h"

void	exe_io_launcher(t_unit_launcher *launcher)
{
	char	*cmd[] = {
		"exe",
		NULL
	};
	unit_register_exe(launcher, "Basic tests", cmd[0], cmd, exe_io_basic_test);
}
