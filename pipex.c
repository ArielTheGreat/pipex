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

void check_existance_files(char *str, char *str2)
{
    int first_file_fd;
    int second_file_fd;

    first_file_fd = open(str, O_RDONLY);
    if (first_file_fd == -1)
    {
        ft_putstr_fd(str,1);
        ft_putstr_fd(": open: No such file or directory\n",1);
    }
    close(first_file_fd);
    second_file_fd = open(str2, O_RDONLY);
    if (second_file_fd == -1)
    {
        ft_putstr_fd(str2,1);
        ft_putstr_fd(": open: No such file or directory\n",1);
    }
    close(second_file_fd);
}

int main(int argc, char **argv)
{
    if (argc == 5)
    {
        check_existance_files(argv[1], argv[4]);
    }else
    {
        ft_putstr_fd("Unexpected amount of arguments were given",1);
    }
    return (0);
}
