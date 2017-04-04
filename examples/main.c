/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:17:51 by thugo             #+#    #+#             */
/*   Updated: 2017/04/04 22:17:59 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"
#include "launchers.h"

int	main(void)
{
	t_unit_tests		*tests;

	tests = unit_init("Example of tests");
	unit_register_launcher(tests, "STRLEN", strlen_launcher);
	unit_register_launcher(tests, "PUTSTR", putstr_launcher);
	unit_register_launcher(tests, "EXE_IO", exe_io_launcher);
	if (!unit_launch_tests(tests))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
