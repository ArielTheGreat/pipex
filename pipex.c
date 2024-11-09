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
	pid_t	pid1;
	int		status1;

	handle_number_of_arguments(argc);
	handle_pipe_creation(fd);
	if (create_child(&pid1) == 0)
	{
		first_child(argv[1], fd);
		execute_command(argv[2], envp);
		perror("Error executing second command");
	    exit(EXIT_FAILURE);
	}
	waitpid(pid1, &status1, 0);
	second_child(argv[4], fd);
	execute_command(argv, envp);
    return (127);
}
