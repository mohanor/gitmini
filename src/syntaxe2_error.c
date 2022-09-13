#include "../minishell.h"

int check_pipe(char *s)
{
    int i;
    
    i = 0;
    while(s[i])
    {
        scape_s_d_quot(s,&i);
        if ((s[i] == '&' && s[i+1] == '&')
            || (s[i] == '|' && s[i+1] == '|'))
            i+=2;
        else if(s[i] == '|')
        {
            if(ft_strchr("&><|(",s[b_e(s,i-1)]) == 1 
            || ft_strchr("&|)",s[a_e(s,i+1)]) == 1)
                return (1);
        }
        i++;
    }
    return(0);
}
int check_And_Or(char *s)
{
    int i;
    
    i = 0;
    while(s[i])
    {
        scape_s_d_quot(s,&i);
        if ((s[i] == '&' && s[i+1] == '&') 
                || (s[i] == '|' && s[i+1] == '|'))
        {
            if((ft_strchr("&<>|(",s[b_e(s,i-1)]) == 1  && ft_strchr("&<>(|",s[b_e(s,i-1)-1]) == 1)
            || (ft_strchr("&<>)|",s[a_e(s,i+2)]) == 1 && ft_strchr("&<>)|",s[a_e(s,i+2)+1]) == 1) 
            || (ft_strchr("&<>(|",s[b_e(s,i-1)]) == 1 || ft_strchr("&<>)|",s[a_e(s,i+2)]) == 1))
                    
                return (1);
            i+=2;
        }
        i++;
    }
    return(0);
}
int check_d_redirections(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        scape_s_d_quot(s,&i);
        if ((s[i] == '>' && s[i+1] == '>') 
                || (s[i] == '<' && s[i+1] == '<'))
        {
            if((ft_strchr("&<>(",s[b_e(s,i-1)]) == 1  && ft_strchr("&<>(",s[b_e(s,i-1)-1]) == 1)
            || (ft_strchr("&<>)",s[a_e(s,i+2)]) == 1 && ft_strchr("&<>)",s[a_e(s,i+2)+1]) == 1) 
            || (ft_strchr("&<>(",s[b_e(s,i-1)]) == 1 || ft_strchr("&<>)",s[a_e(s,i+2)]) == 1))
                    
                return (1);
            i+=2;
        }
        i++;
    }
    return (0);
}
int check_s_redirections(char *s)
{
    int i;
    
    i = 0;
    while(s[i])
    {
        scape_s_d_quot(s,&i);
        if ((s[i] == '>' && s[i+1] == '>')
            || (s[i] == '<' && s[i+1] == '<'))
            i+=2;
        else if(s[i] == '<' || s[i] == '>')
        {
            if(ft_strchr("&<>(",s[b_e(s,i-1)]) == 1 
            || ft_strchr("&<>)",s[a_e(s,i+1)]) == 1)
                return (1);
        }
        i++;
    }
    return(0);
}

int syntaxe2_eror(char *line)
{  
    if( check_And_Or(line)==1) 
        return(1);
    if(check_pipe(line)==1 ) 
        return(1);
    if( check_d_redirections(line) == 1) 
        return(1);
    if( check_s_redirections(line) == 1) 
        return(1);
    return (0);
}