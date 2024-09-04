/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:16 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/07/29 16:31:32 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_words(char const *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			in_substring = 0;
		}
		else if (in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	get_word_length(char const *s, char c)
{
	int	length;

	length = 0;
	while (*s != c && *s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

static void	free_memory(char **split, int words_allocated)
{
	int	i;

	i = 0;
	while (i < words_allocated)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*get_next_word(char **s, char c)
{
	char	*word;
	int		word_len;

	while (**s == c && **s != '\0')
		(*s)++;
	word_len = get_word_length(*s, c);
	word = malloc(sizeof(*word) * (word_len + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, *s, word_len + 1);
	*s += word_len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*tmp_s;
	int		nb_words;
	int		index;

	if (s == NULL)
		return (NULL);
	nb_words = get_nb_words(s, c);
	split = malloc(sizeof(*split) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	index = 0;
	tmp_s = (char *)s;
	while (index < nb_words)
	{
		split[index] = get_next_word(&tmp_s, c);
		if (split[index] == NULL)
		{
			free_memory(split, index);
			return (NULL);
		}
		index++;
	}
	split[index] = NULL;
	return (split);
}

//static int	get_nb_words(char const *s, char c)
//{
//	int	count;
//	int	in_substring;
//
//	count = 0;
//	in_substring = 0;
//	while (*s != '\0')
//	{
//		if (*s == c)
//		{
//			in_substring = 0;
//		}
//		else if (in_substring == 0)
//		{
//			in_substring = 1;
//			count++;
//		}
//		s++;
//	}
//	return (count);
//}
//
//static int	get_word_length(char const *s, char c)
//{
//	int	length;
//
//	length = 0;
//	while (*s != c && *s != '\0')
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}
//
//static void	free_memory(char **split, int words_allocated)
//{
//	int	i;
//
//	i = 0;
//	while (i < words_allocated)
//	{
//		free(split[i]);
//		i++;
//	}
//	free(split);
//}
//
//static char	*get_next_word(char **s, char c)
//{
//	char	*word;
//	int		word_len;
//
//	while (**s == c && **s != '\0')
//		(*s)++;
//	word_len = get_word_length(*s, c);
//	word = malloc(sizeof(*word) * (word_len + 1));
//	if (word == NULL)
//		return (NULL);
//	ft_strlcpy(word, *s, word_len + 1);
//	*s += word_len;
//	return (word);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	char	**split;
//	int		nb_words;
//	int		index;
//
//	if (s == NULL)
//		return (NULL);
//	nb_words = get_nb_words(s, c);
//	split = malloc(sizeof(*split) * (nb_words + 1));
//	if (split == NULL)
//		return (NULL);
//	index = 0;
//	while (index < nb_words)
//	{
//		split[index] = get_next_word(&s, c);
//		if (split[index] == NULL)
//		{
//			free_memory(split, index);
//			return (NULL);
//		}
//		index++;
//	}
//	split[index] = NULL;
//	return (split);
//}

//static int	get_nb_words(char const *s, char c)
//{
//	int	count;
//	int	in_substring;
//
//	count = 0;
//	in_substring = 0;
//	while (*s != '\0')
//	{
//		if (*s == c)
//		{
//			in_substring = 0;
//		}
//		else if (in_substring == 0)
//		{
//			in_substring = 1;
//			count++;
//		}
//		s++;
//	}
//	return (count);
//}
//
//static int	get_word_length(char const *s, char c)
//{
//	int	length;
//
//	length = 0;
//	while (*s != c && *s != '\0')
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}
//
//static void	free_memory(char **split, int words_allocated)
//{
//	int	i;
//
//	i = 0;
//	while (i < words_allocated)
//	{
//		free(split[i]);
//		i++;
//	}
//	free(split);
//}
//
//static char	*get_next_word(char **s, char c)
//{
//	char	*word;
//	int		word_len;
//
//	while (**s == c && **s != '\0')
//		(*s)++;
//	word_len = get_word_length(*s, c);
//	word = malloc(sizeof(*word) * (word_len + 1));
//	if (word == NULL)
//		return (NULL);
//	ft_strlcpy(word, *s, word_len + 1);
//	*s += word_len;
//	return (word);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	char	**split;
//	int		nb_words;
//	int		index;
//
//	if (s == NULL)
//		return (NULL);
//	nb_words = get_nb_words(s, c);
//	split = malloc(sizeof(*split) * (nb_words + 1));
//	if (split == NULL)
//		return (NULL);
//	index = 0;
//	while (index < nb_words)
//	{
//		split[index] = get_next_word(&s, c);
//		if (split[index] == NULL)
//		{
//			free_memory(split, index);
//			return (NULL);
//		}
//		index++;
//	}
//	split[index] = NULL;
//	return (split);
//}

//static int	get_nb_words(char const *s, char c)
//{
//	int	count;
//	int	in_substring;
//
//	count = 0;
//	in_substring = 0;
//	while (*s != '\0')
//	{
//		if (*s == c)
//			in_substring = 0;
//		else if (in_substring == 0)
//		{
//			in_substring = 1;
//			count++;
//		}
//		s++;
//	}
//	return (count);
//}
//
//static int	get_word_length(char const *s, char c)
//{
//	int	length;
//
//	length = 0;
//	while (*s != c && *s != '\0')
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}
//
//static void	free_memory(char **split, int words_allocated)
//{
//	int	i;
//
//	i = 0;
//	while (i < words_allocated)
//	{
//		free(split[i]);
//		i++;
//	}
//	free(split);
//}
//
//static char	*allocate_and_copy(const char *s, char c)
//{
//	int		len;
//	char	*word;
//
//	len = get_word_length(s, c);
//	word = malloc(sizeof(*word) * (len + 1));
//	if (word == NULL)
//		return (NULL);
//	ft_strlcpy(word, s, len + 1);
//	return (word);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	char	**split;
//	int		nb_words;
//	int		index;
//
//	nb_words = get_nb_words(s, c);
//	index = 0;
//	if(s==NULL)
//		return (NULL);
//	split = malloc(sizeof(*split) * (nb_words + 1));
//	if (split == NULL)
//		return (NULL);
//	while (nb_words--)
//	{
//		while (*s == c)
//			s++;
//		split[index] = allocate_and_copy(s, c);
//		if (split[index] == NULL)
//		{
//			free_memory(split, index);
//			return (NULL);
//		}
//		s += get_word_length(s, c);
//		index++;
//	}
//	split[index] = NULL;
//	return (split);
//}

//static int	get_nb_words(char const *s, char c)
//{
//	int	count;
//	int	in_substring;
//
//	count = 0;
//	in_substring = 0;
//	while (*s != '\0')
//	{
//		if (*s == c)
//			in_substring = 0;
//		else if (in_substring == 0)
//		{
//			in_substring = 1;
//			count++;
//		}
//		s++;
//	}
//	return (count);
//}
//
//static int	get_word_length(char const *s, char c)
//{
//	int	length;
//
//	length = 0;
//	while (*s != c && *s != '\0')
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}
//
//static void	free_memory(char **split, int words_allocated)
//{
//	int	i;
//
//	i = 0;
//	while (i < words_allocated)
//	{
//		free(split[i]);
//		i++;
//	}
//	free(split);
//}
//
//static const char	*skip_delimiter(const char *s, char c)
//{
//	while (*s == c && *s != '\0')
//		s++;
//	return (s);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	char	**split;
//	int		nb_words;
//	int		index;
//	int		word_length;
//
//	if (s == NULL)
//		return (NULL);
//	nb_words = get_nb_words(s, c);
//	split = (char **)malloc(sizeof(*split) * (nb_words + 1));
//	if (split == NULL)
//		return (NULL);
//	index = 0;
//	while (nb_words--)
//	{
//		s = skip_delimiter(s, c);
//		word_length = get_word_length(s, c);
//		split[index] = malloc(sizeof(**split) * (word_length + 1));
//		if (split[index] == NULL)
//		{
//			free_memory(split, index);
//			return (NULL);
//		}
//		ft_strlcpy(split[index++], s, word_length + 1);
//		s += word_length;
//	}
//	split[index] = NULL;
//	return (split);
//}
//
//static int	get_nb_words(char const *s, char c)
//{
//	int	count;
//	int	in_substring;
//
//	count = 0;
//	in_substring = 0;
//	while (*s != '\0')
//	{
//		if (*s == c)
//		{
//			in_substring = 0;
//		}
//		else if (in_substring == 0)
//		{
//			in_substring = 1;
//			count++;
//		}
//		s++;
//	}
//	return (count);
//}
//
//static int	get_word_length(char const *s, char c)
//{
//	int	length;
//
//	length = 0;
//	while (*s != c && *s != '\0')
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}
//
//static void	free_memory(char **split, int words_allocated)
//{
//	int	i;
//
//	i = 0;
//	while (i < words_allocated)
//	{
//		free(split[i]);
//		i++;
//	}
//	free(split);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	char	**split;
//	int		nb_words;
//	int		index;
//
//	if (s == NULL)
//		return (NULL);
//	nb_words = get_nb_words(s, c);
//	split = (char **)malloc(sizeof(*split) * (nb_words + 1));
//	if (split == NULL)
//		return (NULL);
//	index = 0;
//	while (nb_words--)
//	{
//		while (*s == c && *s != '\0')
//			s++;
//		split[index] = malloc(sizeof(**split) * (get_word_length(s, c) + 1));
//		if (split[index] == NULL)
//		{
//			free_memory(split, index);
//			return (NULL);
//		}
//		ft_strlcpy(split[index], s, get_word_length(s, c) + 1);
//		s = s + get_word_length(s, c);
//		index++;
//	}
//	split[index] = NULL;
//	return (split);
//}

//static int	get_nb_words(char const *s, char c)
//{
//	int	count;
//	int	in_substring;
//
//	count = 0;
//	in_substring = 0;
//	while (*s != '\0')
//	{
//		if (*s == c)
//		{
//			in_substring = 0;
//		}
//		else if (in_substring == 0)
//		{
//			in_substring = 1;
//			count++;
//		}
//		s++;
//	}
//	return (count);
//}
//
//static int	get_word_length(char const *s, char c)
//{
//	int	length;
//
//	length = 0;
//	while (*s != c && *s != '\0')
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	char	**split;
//	int		nb_words;
//	int		index;
//
//	if (s == NULL)
//		return (NULL);
//	nb_words = get_nb_words(s, c);
//	split = (char **)malloc(sizeof(*split) * (nb_words + 1));
//	if (split == NULL)
//		return (NULL);
//	index = 0;
//	while (nb_words--)
//	{
//		while (*s == c && *s != '\0')
//			s++;
//		split[index] = malloc(sizeof(**split) * (get_word_length(s, c) + 1));
//		if (split[index] == NULL)
//			return (NULL);
//		ft_strlcpy(split[index], s, get_word_length(s, c) + 1);
//		s = s + get_word_length(s, c);
//		index++;
//	}
//	split[index] = NULL;
//	return (split);
//}
//
// static int	count_strings(const char *str, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		while (*str == c)
// 			str++;
// 		if (*str != '\0')
// 			count++;
// 		while (*str && *str != c)
// 			str++;
// 	}
// 	return (count);
// }

// static char	*get_word_and_advance_ptr(const char **str, char c)
// {
// 	char		*word;
// 	int			i;
// 	const char	*tmp;

// 	tmp = *str;
// 	i = 0;
// 	while (tmp[i] && tmp[i] != c)
// 		i++;
// 	word = malloc(sizeof(char) * (i + 1));
// 	if (!word)
// 		return (NULL);
// 	i = 0;
// 	while (*tmp && *tmp != c)
// 	{
// 		word[i++] = *tmp++;
// 	}
// 	word[i] = '\0';
// 	*str = tmp;
// 	return (word);
// }

// static void	skip_char(char const **str, char c)
// {
// 	while (**str == c)
// 		(*str)++;
// }

// static void	free_memory(char **split, int i)
// {
// 	while (i >= 0)
// 		free(split[i--]);
// 	free(split);
// }

// char	**ft_split(char const *str, char charset)
// {
// 	char	**split;
// 	int		i;
// 	char	*word;

// 	if (!str)
// 		return (NULL);
// 	split = malloc(sizeof(char *) * (count_strings(str, charset) + 1));
// 	if (split == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (1)
// 	{
// 		skip_char(&str, charset);
// 		word = get_word_and_advance_ptr(&str, charset);
// 		if (word == NULL)
// 		{
// 			if (*str == '\0')
// 			{
// 				split[i] = NULL;
// 				break ;
// 			}
// 			free_memory(split, i);
// 			return (NULL);
// 		}
// 		split[i++] = word;
// 	}
// 	return (split);
// }

// static int	count_strings(const char *str, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		while (*str == c)
// 			str++;
// 		if (*str != '\0')
// 			count++;
// 		while (*str && *str != c)
// 			str++;
// 	}
// 	return (count);
// }

// static char	*get_word_and_advance_ptr(const char **str, char c)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	while ((*str)[i] && (*str)[i] != c)
// 		i++;
// 	word = malloc(sizeof(char) * (i + 1));
// 	if (!word)
// 		return (NULL);
// 	i = 0;
// 	while (**str && **str != c)
// 	{
// 		word[i++] = *(*str)++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// static void	skip_char(char const **str, char c)
// {
// 	while (**str == c)
// 		(*str)++;
// }

// static void	free_memory(char **split, int i)
// {
// 	while (i >= 0)
// 		free(split[i--]);
// 	free(split);
// }

// char	**ft_split(char const *str, char charset)
// {
// 	char	**split;
// 	int		i;
// 	char	*word;

// 	if (!str)
// 		return (NULL);
// 	split = malloc(sizeof(char *) * (count_strings(str, charset) + 1));
// 	if (!split)
// 		return (NULL);
// 	i = 0;
// 	while (*str)
// 	{
// 		skip_char(&str, charset);
// 		if (*str != '\0')
// 		{
// 			word = get_word_and_advance_ptr(&str, charset);
// 			if (!word)
// 			{
// 				free_memory(split, i);
// 				return (NULL);
// 			}
// 			split[i] = word;
// 			i++;
// 		}
// 		skip_char(&str, charset);
// 	}
// 	split[i] = NULL;
// 	return (split);
// }

// static int	count_strings(const char *str, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		while (*str == c)
// 			str++;
// 		if (*str != '\0')
// 			count++;
// 		while (*str && *str != c)
// 			str++;
// 	}
// 	return (count);
// }

// static char	*get_word_and_advance_ptr(const char **str, char c)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	while ((*str)[i] && (*str)[i] != c)
// 		i++;
// 	word = malloc(sizeof(char) * (i + 1));
// 	if (!word)
// 		return (NULL);
// 	i = 0;
// 	while (**str && **str != c)
// 	{
// 		word[i++] = *(*str)++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char const *str, char charset)
// {
// 	char	**split;
// 	int		i;

// 	if (!str || !(split = malloc(sizeof(char *) * (count_strings(str, charset)
// 					+ 1))))
// 		return (NULL);
// 	i = 0;
// 	while (*str)
// 	{
// 		while (*str == charset)
// 			str++;
// 		if (*str != '\0')
// 		{
// 			if (!(split[i] = get_word_and_advance_ptr(&str, charset)))
// 			{
// 				while (i >= 0)
// 					free(split[i--]);
// 				free(split);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 		while (*str && *str != charset)
// 			str++;
// 	}
// 	split[i] = NULL;
// 	return (split);
// }

// static int	is_separator(char c, char set)
// {
// 	if (c == set)
// 		return (1);
// 	return (0);
// }

// static int	count_strings(const char *str, char c)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	while (*str != '\0')
// 	{
// 		while (*str && is_separator(*str, c))
// 			str++;
// 		if (*str != '\0')
// 			count++;
// 		while (*str && !is_separator(*str, c))
// 			str++;
// 	}
// 	return (count);
// }

// static int	get_word_lenghth(const char *str, char charset)
// {
// 	int	len_count;

// 	len_count = 0;
// 	while (*str != '\0' && !is_separator(*str, charset))
// 	{
// 		len_count++;
// 		str++;
// 	}
// 	return (len_count);
// }

// static char	*get_word(const char *str, char charset)
// {
// 	char	*new_str;
// 	int		word_len;
// 	int		i;

// 	word_len = get_word_lenghth(str, charset);
// 	new_str = (char *)malloc(sizeof(char) * word_len + 1);
// 	if (new_str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < word_len)
// 	{
// 		*new_str = *str;
// 		new_str++;
// 		str++;
// 		i++;
// 	}
// 	*new_str = '\0';
// 	return (new_str - word_len);
// }

// static void	free_memory(char **all_strings, int i)
// {
// 	int	t;

// 	t = 0;
// 	while (t < i)
// 		free(all_strings[t++]);
// 	free(all_strings);
// }

// static char	**initialize_split(char const *str, char charset)
// {
// 	char	**all_strings;

// 	if (str == NULL)
// 		return (NULL);
// 	all_strings = (char **)malloc(sizeof(char *) * (count_strings(str, charset)
// 				+ 1));
// 	if (all_strings == NULL)
// 		return (NULL);
// 	return (all_strings);
// }

// static char	**process_word(char const *str, char charset,
//char **all_strings,
// 		int i)
// {
// 	char	*word;

// 	word = get_word(str, charset);
// 	if (word == NULL)
// 	{
// 		free_memory(all_strings, i);
// 		return (NULL);
// 	}
// 	all_strings[i] = word;
// 	return (all_strings);
// }

// char	**ft_split(char const *str, char charset)
// {
// 	char	**all_strings;
// 	int		i;

// 	i = 0;
// 	all_strings = initialize_split(str, charset);
// 	if (all_strings == NULL)
// 		return (NULL);
// 	while (*str)
// 	{
// 		while (is_separator(*str, charset))
// 			str++;
// 		if (*str != '\0')
// 		{
// 			all_strings = process_word(str, charset, all_strings, i);
// 			if (all_strings == NULL)
// 				return (NULL);
// 			i++;
// 		}
// 		while (*str != '\0' && !is_separator(*str, charset))
// 			str++;
// 	}
// 	all_strings[i] = NULL;
// 	return (all_strings);
// }

// static void	split_processes(char **all_strings, char const *str,
//char charset)
// {
// 	int		i;
// 	int		t;
// 	char	*word;

// 	i = 0;
// 	while (*str)
// 	{
// 		while (is_separator(*str, charset))
// 			str++;
// 		if (*str != '\0')
// 		{
// 			word = get_word(str, charset);
// 			if (word == NULL)
// 			{
// 				t = 0;
// 				while (t < i)
// 					free(all_strings[t++]);
// 				free(all_strings);
// 				return (NULL);
// 			}
// 			*(all_strings + i) = word;
// 			i++;
// 		}
// 		while (*str != '\0' && !is_separator(*str, charset))
// 			str++;
// 	}
// 	all_strings[i] = NULL;
// }

// char	**ft_split(char const *str, char charset)
// {
// 	char	**all_strings;
// 	int		i;
// 	char	*word;
// 	int		t;

// 	if (str == NULL)
// 		return (NULL);
// 	all_strings = (char **)malloc(sizeof(char *) * count_strings(str,
//	charset)
// 			+ 1);
// 	if (all_strings == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (*str)
// 	{
// 		while (is_separator(*str, charset))
// 			str++;
// 		if (*str != '\0')
// 		{
// 			word = get_word(str, charset);
// 			if (word == NULL)
// 			{
// 				t = 0;
// 				while (t < i)
// 					free(all_strings[t++]);
// 				free(all_strings);
// 				return (NULL);
// 			}
// 			*(all_strings + i) = word;
// 			i++;
// 		}
// 		while (*str != '\0' && !is_separator(*str, charset))
// 			str++;
// 	}
// 	all_strings[i] = NULL;
// 	return (all_strings);
// }

//char	**ft_split(char const *str, char charset)
//{
//	char	**all_strings;
//	int		i;
//
//	i = 0;
//	if (str == NULL)
//		return (NULL);
//	all_strings = (char **)malloc(sizeof(char *) * count_strings(str,
//	charset)
//			+ 1);
//	if (all_strings == NULL)
//		return (NULL);
//	;
//	i = 0;
//	while (*str)
//	{
//		while (is_separator(*str, charset))
//			str++;
//		if (*str != '\0' && !(all_strings[i] = get_word(str, charset, &i)))
//		{
//			free_memory(all_strings, i);
//			return (NULL);
//		}
//		while (*str != '\0' && !is_separator(*str, charset))
//			str++;
//	}
//	all_strings[i] = NULL;
//	return (all_strings);

//#include <stdio.h>
//
//int	main(void)
//{
//	char	*str;
//	char	del;
//	char	**split_word;
//
//	str = ",,,abc,efg,hijk";
//	del = ',';
//	split_word = ft_split(str, del);
//	printf("1:%s\n", split_word[0]);
//	printf("2:%s\n", split_word[1]);
//	printf("3:%s\n", split_word[2]);
//}
