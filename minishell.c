/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:33:42 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/13 23:44:19 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    char  *line;
    t_env *envr; 
    int fd[2];

    (void)argc;
    (void)argv;
    envr = make_env(env);
    
    fd[0] = dup(0);
    
    while(1)
    {
        dup2(fd[0], 0);
        
        line = readline("Minishell> ");// free leaks
        if(*line)
        {
            add_history(line);
            scape_t_d_s_qout(line);
            if(syntaxe1_eror(line) == 1 || syntaxe2_eror(line) == 1 ) 
                ft_putstr_fd("Minishell : Syntaxe_error",2);
            else
            {
                line = expend_herdog(line);
                disperse_cmd(line,envr);
            }
            free(line); 
        }
    }

    close(fd[0]);
    
}
