#include "../minishell.h"

int check_parent(char *line)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(line[i])
    {
        scape_s_d_quot(line,&i);
        if(line[i] == '(')
            j+=1;
        else if(line[i] == ')' && j > 0)
            j-=1;
        else if( line[i] == ')' && j == 0)
                return(1);
        i++;
    }
    if(j != 0)
        return(1);
    return(0);
}

int check_dq_q(char *line)
{
    int i;
    int j;
    char c;

    i = 0;
    j = 0;
    while(line[i])
    {
        if(line[i] == '\"' || line[i] == '\'')
        {
            c = line[i];
            i++;
            while (line[i] != c)
            {
                 if(line[i] == '\0')
                    return(1);
                i++;
            }
        }
        i++;
    }
    return(0);
}

int chech_first_last(char *s)
{
    if(ft_strchr("&|",s[a_e(s ,0)]) == 1 
        || ft_strchr("&|><",s[b_e(s ,ft_strlen(s) - 1)]) == 1)
        return(1);
    return (0);
}

int subShell(char *line)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(line[i])
    {
        if(line[i] == '(')
        {
            if(line[i+1] == ')')
                return(1);
            j = i;
            while(j != 0)
            {
                if(line[j] == '<')
                    return (1);
                j--;
            }
        }
        i++;
    }
    return (0);
}

int syntaxe1_eror(char *line)
{
    if(check_dq_q(line) == 1 ) 
        return(1);
    if( check_parent(line) ) 
        return(1);
    if( chech_first_last(line) == 1) 
        return(1);
    if( subShell(line) == 1) 
        return(1);
    return (0);
}