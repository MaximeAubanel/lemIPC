/*
** strtowordtab.c for new in /home/aubanel_m/tek2/PSU_2016_lemipc/new
**
** Made by aubanel_m
** Login   <aubanel_m@epitech.net>
**
** Started on  Fri Mar 31 23:06:22 2017 aubanel_m
** Last update Fri Mar 31 23:07:03 2017 Aubanel Maxime
*/

#include "LemiPC.h"

char	**get_nbwords(char *str, char divide)
{
  int	words;
  int	n;
  char	**array;

  words = 0;
  n = 0;
  while (str[n])
    {
      if (str[n] != divide && str[n] != '\t' && (str[n + 1] == divide
						 || str[n + 1] == 0
						 || str[n + 1] == '\t'))
	words = words + 1;
      n = n + 1;
    }
  if ((array = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  return (array);
}

char	*get_words(char *str, int n, int size, char divide)
{
  int	a;
  char	*arr;

  a = 0;
  if ((arr = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  if (size == 0)
    {
      arr = NULL;
      return (arr);
    }
  n = n - size;
  while (str[n] != divide && str[n] != '\t' && str[n] != 0)
    {
      arr[a] = str[n];
      a = a + 1;
      n = n + 1;
    }
  arr[a] = 0;
  return (arr);
}

char	*get_last(char *str, int n, int size)
{
  char	*arr;
  int	i;

  i = 0;
  if ((arr = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  if (size == 0)
    {
      arr = NULL;
      return (arr);
    }
  n = n - size;
  while (str[n])
    {
      arr[i] = str[n];
      n = n + 1;
      i = i + 1;
    }
  arr[i] = 0;
  return (arr);
}

char	**get_array(char **array, char divide, char *str)
{
  int	n;
  int	size;
  int	i;

  n = 0;
  size = 1;
  i = 0;
  while (str[n])
    {
      if ((str[n] == divide || str[n] == '\t') && str[n - 1] != divide
	  && str[n - 1] != '\t')
	{
	  array[i] = get_words(str, n, size, divide);
	  if (array[i][0] != 0)
	    i++;
	  size = 0;
	}
      if (str[n] != 0)
	n = n + 1;
      if (str[n] != divide && str[n] != '\t' && str[n] != 0)
	size = size + 1;
    }
  array[i] = get_last(str, n, size);
  (array[i] != NULL) ? (array[i + 1] = NULL) : (0);
  return (array);
}

char	**str_to_word_tab(char *str, char divide)
{
  char	**array;

  if (str == NULL)
    return (NULL);
  array = get_nbwords(str, divide);
  array = get_array(array, divide, str);
  return (array);
}
