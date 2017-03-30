/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 23:46:36 by thugo             #+#    #+#             */
/*   Updated: 2017/03/30 03:50:37 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_TYPES_H
# define LIBUNIT_TYPES_H

# define FTYPE_FN 		1
# define FTYPE_FN_IO	2

typedef struct	s_ml_list
{
	void				*content;
	struct s_ml_list	*next;
}				t_ml_list;

typedef struct	s_unit_tests
{
	char			*name;
	t_ml_list		*launchers;
}				t_unit_tests;

typedef struct	s_unit_launcher
{
	char			*name;
	t_ml_list		*tests;
}				t_unit_launcher;

typedef union	u_unit_fntypes
{
	int				(*fn)(void);
	int				(*fn_io)(int, int);
}				t_unit_fntypes;

typedef struct	s_unit_test
{
	char			*name;
	int				ftype;
	t_unit_fntypes	f;
}				t_unit_test;

#endif
