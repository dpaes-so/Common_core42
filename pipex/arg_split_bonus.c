/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:01:18 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/03/03 19:08:11 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/libft/libft.h"

static int	countwords(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i]) 
	{
		while (s[i] == ' ' && s[i])
			i++;
        if(s[i] == '\'')
        {
            i++;
			count++;
            while (s[i] != '\'' && s[i])
			    i++;
            if(s[i] == '\'')
                i++;
        }
		else if(s[i])
			count++;
		while (s[i] != ' ' && s[i])
			i++;
	}
	return (count);
}

static void quote_handle(int *len,char **s,char const **str)
{
    (*s)++;
    *str = (*s);
    while(**s != '\'')
    {
        (*s)++;
	    (*len)++;
    }
    if (**s == '\'')
        (*s)++; 
}
static char	*wordalloc(char const **s, char c)
{
	char		*word;
	char const	*str;
	int			len;

	len = 0;
	while (**s && **s == c)
		(*s)++;
    str = (*s);
	while (**s && **s != c)
	{
        if(**s && **s == '\'')
            quote_handle(&len,(char **)s,&str);
        else
        {
            (*s)++;
            len++;
        }
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	return (ft_strlcpy(word, str, len + 1),word);
}

char	**ft_arg_split(char const *s, char c)
{
	char	**result;
	int		stringnum;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	stringnum = countwords(s);
	result = malloc(sizeof(char *) * (stringnum + 1));
	ft_printf("str = %d",stringnum);
	result[stringnum] = 0;
	if (!result)
		return (NULL);
	while (i < stringnum)
	{
		result[i] = wordalloc(&s, c);
		if (!result[i])
		{
			while (i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
int	main(void)
{
	const char *str = "cut -d ''\' -f 1";
	char delimiter = ' ';
	char **result = ft_arg_split(str, delimiter);

	if (result)
	{
        int i = 0;
		while(result[i] != NULL)
		{
            int j = 0;
            while(result[i][j])
            {
			    printf("Substring %d: %c\n", i + 1, result[i][j]);
                j++;
            }
            ft_printf("j = %d\n",j);
            i++;
		}
		for (int i = 0; result[i] != NULL; i++)
		{
			free(result[i]); // Free each allocated substring
		}
		free(result); // Finally, free the array of pointers
	}
	else
	{
		printf("Memory allocation failed. (main)\n");
	}
	return (0);
}