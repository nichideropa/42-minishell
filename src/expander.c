#include "../inc/minishell.h"

extern t_minishell	g_msh;

size_t		next_exp(char *token, size_t pos);
static char	*get_varname(char *token);
static char	*expand_varname(char *varname);

char	*expander(char *token, bool unquote)
{
	char	*expanded;
	size_t	i;

	expanded = NULL;
	i = 0;
	while (token != NULL && i < (size_t)ft_strlen(token))
	{
		expanded = ft_strjoin_free(expanded,
				ft_substr(token, i, next_exp(token, i) - i));
		i = next_exp(token, i);
		expanded = ft_strjoin_free(expanded,
				expand_varname(get_varname(&token[next_exp(token, i)])));
		i += ft_strlen_free(get_varname(&token[next_exp(token, i)]));
	}
	ft_free((void **)&token);
	if (unquote)
		return (quote_remover(expanded));
	return (expanded);
}

static char	*get_varname(char *token)
{
	size_t	i;
	size_t	j;

	i = 1;
	if (token == NULL || token[0] != '$')
		return (NULL);
	if (token[1] == '?')
		return (ft_strdup("$?"));
	else if (ft_isdigit(token[1]))
		return (ft_substr(token, 0, 2));
	else if (token[1] == '\'' || token[1] == '"')
		return (ft_substr(token, 0, ft_strchr_int(token + 2, token[1]) + 1));
	j = 0;
	while ((valid_exp_char(token[i], true) && j == 0)
		|| valid_exp_char(token[i], false))
	{
		i++;
		j++;
	}
	return (ft_substr(token, i - j - 1, i));
}

static char	*expand_varname(char *varname)
{
	char	*value;

	if (varname == NULL || varname[0] == '\0')
		return (NULL);
	else if (ft_strcmp(varname, "$?") == 0)
		value = ft_itoa(g_msh.exit_code);
	else if (ft_strlen(varname) == 2 && ft_isdigit(varname[1]))
		return (NULL);
	else if (varname[1] == '\'' || varname[1] == '\"')
		value = ft_strdup(&varname[1]);
	else
		value = get_var((const char *)&varname[1]);
	value = ft_strjoin_free(ft_strdup(NULL), value);
	value = ft_strjoin_free(value, ft_strdup(NULL));
	ft_free((void **)&varname);
	return (value);
}
