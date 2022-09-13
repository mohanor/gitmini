/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:16:11 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/13 23:38:15 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
char *befor_first_pipe(char *line, int *k)
{
   int i;
   char *c;
   int f;

   f = *k;
   i = *k;
   while(line[i])
   {
      scape_paren_quot_in(line,&i);
      if(line[i] == '|' && line[i+1] != '|' )
      {
         c = ft_substr(line,f,i - f);
         line[i] = ' '; 
         *k = i;
         return(c);
      }
      i++;
   }
   if(line[i] == '\0')
      i = -1;
   *k = i;
   return(ft_substr(line,f,i - f));
}

void pipe_cmd(char *line,t_env *envr)
{
   int len;
   char *first_cmd_pipe;
   int fd[2];
   int tmp_fd;
   int pid;

   tmp_fd = 0;
   int i = 0;
   t_pid *childs;

   childs = NULL;
   len = 0;
   while(len != -1)
   {
      first_cmd_pipe = befor_first_pipe(line, &len);
      if (len != -1)
         pipe(fd);
      pid = fork();
      if(pid == 0)
      {
         if (len != -1)
         {
		      dup2(fd[1], 1);
            close(fd[1]);
            close(fd[0]);            
         }
         red_cmd(first_cmd_pipe, envr);
         exit(1);
      }
      else
         ft_lstadd_back_pid(&childs, ft_lstnew_pid(pid));
      if (len != -1)
      {
         dup2(fd[0], 0);
         close(fd[0]);
         close(fd[1]);
      }
      else
         close(0);
      i++;
   }
   

   t_pid *tmp_childs;
   tmp_childs = childs;
   while (tmp_childs)
   {
      waitpid(tmp_childs->pid,&status,0);
      if (tmp_childs->pid == pid)
         break ;
      tmp_childs = tmp_childs->next;
   }
}

