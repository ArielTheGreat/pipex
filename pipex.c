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

#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>

void handle_infile_opening(char *str, int *fd_infile)
{
    *fd_infile = open(str, O_RDONLY);
    if (*fd_infile == -1)
    {
        perror("Error opening infile");
        exit(EXIT_FAILURE);
    }
}

void handle_outfile_opening(char *str, int *fd_outfile)
{
    *fd_outfile = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*fd_outfile == -1)
    {
        perror("Error opening outfile");
        exit(EXIT_FAILURE);
    }
}

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

int main(int argc, char **argv)
{
    int fd[2];
    int fd_infile, fd_outfile;

    handle_number_of_arguments(argc);
    handle_infile_opening(argv[1], &fd_infile);
    handle_outfile_opening(argv[4], &fd_outfile);
    handle_pipe_creation(fd);
    return (0);
}
