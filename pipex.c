/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:01:33 by frocha            #+#    #+#             */
/*   Updated: 2024/11/02 11:01:34 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_pipe_creation(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("Error creating the pipe");
		exit(EXIT_FAILURE);
	}
}

void	handle_number_of_arguments(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: Incorrect number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	wait_children(int *return_value, int status1)
{
	int status2;

	status2 = 0;
	if ((status1 == 256 && status2 == 256) || status2 == 256)
		*return_value = 127;
	else
		*return_value = 0;
}

pid_t	create_child(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}
	return (*pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		fd_infile;
	int		fd_outfile;
	pid_t	pid1;
	int		status1;

	handle_number_of_arguments(argc);
	handle_infile_opening(argv[1], &fd_infile);
	handle_outfile_opening(argv[4], &fd_outfile);
	handle_pipe_creation(fd);
	if (create_child(&pid1) == 0)
	{
		first_child(fd_infile, fd);
		close_fd(fd_infile, fd_outfile, fd);
		execute_command_and_fail(argv[2], envp);
	}
	waitpid(pid1, &status1, 0);
	second_child(fd_outfile, fd);
	close_fd(fd_infile, fd_outfile, fd);
	execute_command_and_fail(argv[3], envp);
	wait_children(&fd_infile, status1);
	return (fd_infile);
}
