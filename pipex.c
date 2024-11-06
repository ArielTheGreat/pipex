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

int check_existance_files(char *str)
{
    int first_file_fd;

    first_file_fd = open(str, O_RDONLY);
    if (first_file_fd == -1)
    {
        ft_putstr_fd(str,2);
        ft_putstr_fd(": open: No such file or directory\n",1);
        close(first_file_fd);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int fd[2];

    if (argc == 5)
    {
        if (pipe(fd) == -1)
        {
            perror("Error creating the pipe");
            exit(EXIT_FAILURE);
        }
        if (check_existance_files(argv[1]) == 1)
        {
            exit(EXIT_FAILURE);
        }
    }else
    {
        ft_putstr_fd("Unexpected amount of arguments were given",1);
    }
    return (0);
}
