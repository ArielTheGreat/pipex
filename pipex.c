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

char *get_command_file_path(char *command, char **envp)
{
    char	**path_directories;
	char	*full_path;
	int		env_index;
	char	*partial_path;

	env_index = 0;
	while (ft_strnstr(envp[env_index], "PATH", 4) == 0)
		env_index++;
	path_directories = ft_split(envp[env_index] + 5, ':');
	env_index = 0;
	while (path_directories[env_index])
	{
		partial_path = ft_strjoin(path_directories[env_index], "/");
		full_path = ft_strjoin(partial_path, command);
		free(partial_path);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		env_index++;
	}
	env_index = -1;
	while (path_directories[++env_index])
		free(path_directories[env_index]);
	free(path_directories);
	return (0);
}

void execute_command(char *str, char **envp)
{
    char **command;
    char *command_file_path;

    command = ft_split(str, ' ');
    command_file_path = get_command_file_path(command[0], envp);
    execve(command_file_path, command, envp);
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int fd_infile, fd_outfile;
    pid_t pid1, pid2;

    handle_number_of_arguments(argc);
    handle_infile_opening(argv[1], &fd_infile);
    handle_outfile_opening(argv[4], &fd_outfile);
    handle_pipe_creation(fd);
    if ((pid1 = fork()) == 0)
    {
        dup2(fd_infile, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        execute_command(argv[2],envp);
    }

    if ((pid2 = fork()) == 0)
    {
        execute_command(argv[3],envp);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}
