/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:26:51 by thugo             #+#    #+#             */
/*   Updated: 2017/03/29 18:23:23 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libunit.h"

static void	exec_test(t_unit_test *test)
{
	if (fork() == 0)
	{
		if (!test->f())
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}
	wait(&(test->status));
	if (WIFEXITED(test->status) && WEXITSTATUS(test->status) == EXIT_SUCCESS)
		ft_printf("\t> %s : [\033[32mOK\033[0m]\n", test->name);
	else if (WIFEXITED(test->status) && WEXITSTATUS(test->status) ==
			EXIT_FAILURE)
		ft_printf("\t> %s : [\033[31mKO\033[0m]\n", test->name);
	else if (WIFSIGNALED(test->status) && WTERMSIG(test->status) == SIGABRT)
		ft_printf("\t> %s : [\033[31mABRT\033[0m]\n", test->name);
	else if (WIFSIGNALED(test->status) && WTERMSIG(test->status) == SIGBUS)
		ft_printf("\t> %s : [\033[31mBUSE\033[0m]\n", test->name);
	else if (WIFSIGNALED(test->status) && WTERMSIG(test->status) == SIGSEGV)
		ft_printf("\t> %s : [\033[31mSEGV\033[0m]\n", test->name);
	else
		ft_printf("\t> %s : [\032[33mUNKN\033[0m]\n", test->name);
}

int			launch_tests(t_unit_tests *testlist, char *name)
{
	unsigned int	validtests;
	unsigned int	totaltests;
	t_list			*cur;

	if (!testlist || !name)
		return (-1);
	ft_printf("%s:\n", name);
	validtests = 0;
	totaltests = 0;
	cur = testlist->tests;
	while (cur)
	{
		exec_test((t_unit_test *)cur->content);
		if (WIFEXITED(((t_unit_test *)cur->content)->status) &&
			WEXITSTATUS(((t_unit_test *)cur->content)->status) == EXIT_SUCCESS)
			validtests++;
		cur = cur->next;
		totaltests++;
	}
	ft_printf("%s%u / %u\033[0m tests checked\n", validtests == totaltests ?
		"\033[32m" : "\033[31m", validtests, totaltests);
	return (validtests == totaltests ? 1 : -1);
}
