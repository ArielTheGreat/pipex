/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:53:11 by frocha            #+#    #+#             */
/*   Updated: 2024/11/08 15:53:13 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*get_command_file_path(char *command, char **envp)
{
	char	**path_directories;
	char	*full_path;
	int		env_index;
	char	*partial_path;

	env_index = 0;
	while (envp[env_index] && ft_strnstr(envp[env_index], "PATH", 4) == 0)
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
	return (NULL);
}

void	handle_infile_opening(char *str, int *fd_infile)
{
	*fd_infile = open(str, O_RDONLY);
	if (*fd_infile == -1)
	{
		perror("Error opening infile");
		exit(EXIT_FAILURE);
	}
}

void	handle_outfile_opening(char *str, int *fd_outfile)
{
	*fd_outfile = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_outfile == -1)
	{
		perror("Error opening outfile");
		exit(EXIT_FAILURE);
	}
}

void	execute_command(char *str, char **envp)
{
	char	**command;
	char	*command_file_path;

	command = ft_split(str, ' ');
	command_file_path = get_command_file_path(command[0], envp);
	if (command_file_path == NULL)
	{
		perror("Command not found");
		free_string_array(command);
		exit(127);
	}
	execve(command_file_path, command, envp);
	perror("Error executing command");
	free_string_array(command);
	free(command_file_path);
	exit(EXIT_FAILURE);
}
