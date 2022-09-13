
int b_e(char *line ,int index)
{
    int i;
    i = index;
    while(i)
    {
        if(line[i] != ' ')
            return i;
        i--;
    }
    return index;
}
int a_e(char *line ,int index)
{
    int i;
    i = index;
    while(line[i])
    {
        if(line[i] != ' ')
            return i;
        i++;
    }
    return index;
}
void scape_s_d_quot(char *line , int *k)
{
    int i;
    char c;

    i = *k;
    if(line[i] == '\"' || line[i] == '\'')
        {
            c = line[i];
            i++;
            while ( line[i] != c && line[i] != '\0')
                i++;
        }
    *k = i; 
}
void scape_paren_quot_dec(char *line, int *k)
{
   int i ;
   int j ;
   char c;

   i = *k;
   j = 0;
    if(line[i] == '\"' || line[i] == '\'')
        {
            c = line[i--];
            while ( line[i] != c && i != 0)
                i--;
        }
      else if(line[i] == ')')
      {
         while(1)
         {
            if(line[i] == ')')
               j++;
            if(line[i] == '(')
               j--;
            if(line[i] == '(' && j == 0)
               break;
            i--;
         }
      }
      *k = i;
}
void scape_paren_quot_in(char *line, int *k)
{
   int i ;
   int j ;
   char c;

   i = *k;
   j = 0;
    if(line[i] == '\"' || line[i] == '\'')
        {
            c = line[i++];
            while ( line[i] != c && i != 0)
                i++;
        }
      else if(line[i] == '(')
      {
         while(1)
         {
            if(line[i] == '(')
               j++;
            if(line[i] == ')')
               j--;
            if(line[i] == ')' && j == 0)
               break;
            i++;
         }
      }
      *k = i;
}
