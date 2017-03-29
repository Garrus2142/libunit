/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 00:29:11 by thugo             #+#    #+#             */
/*   Updated: 2017/03/30 00:45:19 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

# include "libunit_types.h"

t_ml_list	*ml_lstnew(void const *content, size_t size);
void		ml_lstpush(t_ml_list **alst, t_ml_list *new);

#endif
