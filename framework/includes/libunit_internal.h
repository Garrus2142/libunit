/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:02:07 by thugo             #+#    #+#             */
/*   Updated: 2017/04/04 21:00:44 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_INTERNAL_H
# define LIBUNIT_INTERNAL_H

void	print_header(char *name);
void	print_test(int status, char *name);
void	print_total(int valid, int total);

#endif
