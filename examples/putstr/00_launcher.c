/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:22:05 by thugo             #+#    #+#             */
/*   Updated: 2017/03/30 03:13:40 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putstr_tests.h"

void	putstr_launcher(t_unit_launcher *launcher)
{
	unit_register_fn_io(launcher, "Basic test", putstr_basic_test);
}
