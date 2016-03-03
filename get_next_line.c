/*
** get_next_line.c for get_next_line in /home/clemen_j/Work/CPE/CPE_2015_getnextline
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Jan  4 11:17:55 2016 Clémenceau Cedric
** Last update Sun Jan 17 21:59:46 2016 Clémenceau Cedric
*/

#include "get_next_line.h"

char	*my_realloc(char *ptr, int size)
{
  char	*dest;
  int	i;
  int	j;

  i = 0;
  if ((dest = malloc(i + size + 1)) == NULL)
    return (NULL);
  i = 0;
  while (ptr[i])
    dest[i] = ptr[i++];
  j = i;
  dest[i] = 0;
  free(ptr);
  return (dest);
}

int	check(char *buff)
{
  int	i;

  i = 0;
  while (buff[i])
    {
      if (buff[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

void	new_line(int *i, char *buff,int fd, t_info *data)
{
  while (buff[*i])
    data->str[(data->j)++] = buff[(*i)++];
  data->str[data->j] = 0;
  while (((*i)--) > 0)
    buff[(*i)] = 0;
  if (data->readed = read(fd, buff, READ_SIZE) <= 0)
    return ;
  buff[data->readed] = 0;
  data->str = my_realloc(data->str, READ_SIZE);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	i = 0;
  t_info	data;

  data.j = 0;
  data.readed = 0;
  if (fd == 0)
    i = 0;
  if ((data.str = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if (data.readed = read(fd, buff, READ_SIZE) < 0)
    return (NULL);
  while (check(buff) == 0)
    new_line(&i, buff, fd, &data);
  while (buff[i] && buff[i] != '\n')
    data.str[(data.j)++] = buff[i++];
  data.str[data.j] = 0;
  if (buff[i] == '\n' && buff[i++]);
  else
    return (NULL);
  return (data.str);
}
