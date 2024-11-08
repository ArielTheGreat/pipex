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

void handle_pipe_creation(int *fd)
{
    if (pipe(fd) == -1)
    {
        perror("Error creating the pipe");
        exit(EXIT_FAILURE);
    }
}

void handle_number_of_arguments(int argc)
{
    if (argc != 5)
    {
        perror("Unexpected amount of arguments were given\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int fd_infile;
    int fd_outfile;
    pid_t pid1, pid2;

    handle_number_of_arguments(argc);
    handle_infile_opening(argv[1], &fd_infile);
    handle_outfile_opening(argv[4], &fd_outfile);
    handle_pipe_creation(fd);
    if ((pid1 = fork()) == 0)
    {
        first_child(fd_infile, fd);
        close_fd(fd_infile, fd_outfile, fd);
        execute_command_and_fail(argv[2], envp);
    }
    if ((pid2 = fork()) == 0)
    {
        second_child(fd_outfile, fd);
        close_fd(fd_infile, fd_outfile, fd);
        execute_command_and_fail(argv[3], envp);
    }
    close_fd(fd_infile, fd_outfile, fd);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}
