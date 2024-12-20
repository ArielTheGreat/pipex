/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:54:19 by frocha            #+#    #+#             */
/*   Updated: 2024/11/08 15:54:22 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	free_string_array(char **array);
char	*get_command_file_path(char *command, char **envp);
void	handle_infile_opening(char *str, int *fd_infile);
void	handle_outfile_opening(char *str, int *fd_outfile);
void	execute_command(char *str, char **envp);
void	second_child(char *outfile_path, int *fd);
void	first_child(char *infile_path, int *fd);

#endif