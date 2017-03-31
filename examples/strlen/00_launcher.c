/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:56:28 by thugo             #+#    #+#             */
/*   Updated: 2017/03/29 23:35:45 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen_tests.h"

void	strlen_launcher(t_unit_launcher *launcher)
{
	unit_register_fn(launcher, "Basic test", strlen_basic_test);
	unit_register_fn(launcher, "Null test", strlen_null_test);
}
