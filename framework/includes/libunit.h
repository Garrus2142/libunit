/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:06:47 by thugo             #+#    #+#             */
/*   Updated: 2017/03/29 18:41:40 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"

typedef struct	s_unit_test
{
	char	*name;
	int		(*f)(void);
	int		status;
}				t_unit_test;

typedef struct	s_unit_tests
{
	char			*name;
	t_list			*tests;
}				t_unit_tests;

void			register_test(t_unit_tests *testlist, char *name,
					int (*f)(void));
int				launch_tests(t_unit_tests *testlist, char *name);

#endif
