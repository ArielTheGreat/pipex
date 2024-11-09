/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:15 by frocha            #+#    #+#             */
/*   Updated: 2024/11/08 16:29:17 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int fd_in, int *fd)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
    {
        perror("Error duplicating input file descriptor in first child");
        exit(EXIT_FAILURE);
    }
	if (dup2(fd[1], STDOUT_FILENO) == -1)
    {
        perror("Error duplicating pipe write end in first child");
        exit(EXIT_FAILURE);
    }
}

void	second_child(int fd_out, int *fd)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
    {
        perror("Error duplicating pipe read in second child");
        exit(EXIT_FAILURE);
    }
	if (dup2(fd_out, STDOUT_FILENO) == -1)
    {
        perror("Error duplicating output file in second child");
        exit(EXIT_FAILURE);
    }
}

void	close_fd(int fd_in, int fd_out, int *fd)
{
	close(fd_in);
	close(fd_out);
	close(fd[0]);
	close(fd[1]);
}

void	execute_command_and_fail(char *argv, char **envp)
{
	execute_command(argv, envp);
	perror("Error executing second command");
	exit(EXIT_FAILURE);
}
