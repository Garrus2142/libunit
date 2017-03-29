/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:51:43 by thugo             #+#    #+#             */
/*   Updated: 2017/03/29 18:02:10 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"

void	register_test(t_unit_tests *testlist, char *name, int (*f)(void))
{
	t_list		*new;
	t_unit_test	test;

	if (!testlist || !name || !f)
		return ;
	if (!(test.name = ft_strdup(name)))
		exit(EXIT_FAILURE);
	test.f = f;
	if (!(new = ft_lstnew(&test, sizeof(t_unit_test))))
		exit(EXIT_FAILURE);
	ft_lstinsert(&(testlist->tests), new);
}
