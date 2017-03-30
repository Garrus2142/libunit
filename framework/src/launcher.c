/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:26:51 by thugo             #+#    #+#             */
/*   Updated: 2017/03/30 03:53:39 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libunit.h"
#include "minilib.h"

static void	print_header(char *name)
{
	printf("\e[1m/*****************************\\\e\n");
	printf("|***********LIBUNIT***********|\n");
	printf("\\*****************************/\e\n");
	printf("%s\n\n\e[0m", name);
}

static void	print_test(int status, char *name)
{
	char	status_str[50];

	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		strcpy(status_str, "\e[32mOK\e[0m");
	else if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		strcpy(status_str, "\e[31mKO\e[0m");
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)
		strcpy(status_str, "\e[31mABRT\e[0m");
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGBUS)
		strcpy(status_str, "\e[31mBUSE\e[0m");
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		strcpy(status_str, "\e[31mSEGV\e[0m");
	else
		strcpy(status_str, "\e[33mUNKN\e[0m");
	printf(">\t%s : [%s]\n", name, status_str);
}

static void	print_total(int valid, int total)
{
	printf("\e[%sm%i / %i\e[0m tests checked.\n", valid == total ? "32" : "31",
		valid, total);
}

static int	exec_fn(int (*f)(void))
{
	int	status;

	if (fork() == 0)
	{
		if (!f())
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}
	wait(&status);
	return (status);
}

static int	exec_fn_io(int (*f)(int, int))
{
	int		status;
	int		pipe_in[2];
	int		pipe_out[2];

	if (fork() == 0)
	{
		if (pipe(pipe_in) || pipe(pipe_out))
		{
			perror("libunit");
			exit(EXIT_FAILURE);
		}
		dup2(pipe_in[0], STDIN_FILENO);
		dup2(pipe_out[1], STDOUT_FILENO);
		close(pipe_in[0]);
		close(pipe_out[1]);
		if (!f(pipe_in[1], pipe_out[0]))
		{
			close(pipe_in[1]);
			close(pipe_out[0]);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(pipe_in[1]);
			close(pipe_out[0]);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	return (status);
}

static int	exec_test(t_unit_test *test)
{
	int		status;

	if (test->ftype == FTYPE_FN)
		status = exec_fn(test->f.fn);
	else if (test->ftype == FTYPE_FN_IO)
		status = exec_fn_io(test->f.fn_io);
	else
		return (-1);
	print_test(status, test->name);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		return (0);
	return (-1);
}

void		free_tests(t_unit_tests *tests)
{
	t_ml_list	*curlauncher;
	t_ml_list	*nextlauncher;
	t_ml_list	*curtest;
	t_ml_list	*nexttest;

	curlauncher = tests->launchers;
	while (curlauncher)
	{
		curtest = ((t_unit_launcher *)curlauncher->content)->tests;
		while (curtest)
		{
			nexttest = curtest->next;
			free(((t_unit_test *)curtest->content)->name);
			free(curtest->content);
			free(curtest);
			curtest = nexttest;
		}
		nextlauncher = curlauncher->next;
		free(((t_unit_launcher *)curlauncher->content)->name);
		free(curlauncher->content);
		free(curlauncher);
		curlauncher = nextlauncher;
	}
	free(tests->name);
	free(tests);
}

/*
**	Execute et affiche tout les tests.
**	Return:
**		0: Tout les tests passent.
**		-1: 1 ou plusieurs test echouent.
*/

int			unit_launch_tests(t_unit_tests *tests)
{
	t_ml_list		*curlauncher;
	t_ml_list		*curtest;
	t_unit_test		*test;
	unsigned int	validtests;
	unsigned int	totaltests;

	validtests = 0;
	totaltests = 0;
	print_header(tests->name);
	curlauncher = tests->launchers;
	while (curlauncher)
	{
		printf("\e[1m%s:\e[0m\n", ((t_unit_launcher *)curlauncher->content)
			->name);
		curtest = ((t_unit_launcher *)curlauncher->content)->tests;
		while (curtest)
		{
			test = (t_unit_test *)curtest->content;
			if (!exec_test(test))
				++validtests;
			++totaltests;
			curtest = curtest->next;
		}
		curlauncher = curlauncher->next;
	}
	print_total(validtests, totaltests);
	free_tests(tests);
	return (validtests == totaltests ? 0 : -1);
}
