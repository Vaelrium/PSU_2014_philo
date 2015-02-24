/*
** waitingOrder.c for philosphezzjz in /home/ganesha/projets/philos/PSU_2014_philo
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Tue Feb 24 12:51:36 2015 Ambroise Coutarel
** Last update Tue Feb 24 15:04:32 2015 Rémi DURAND
*/

#include <pthread.h>
#include "philo.h"

int	g_waitingList[8];

int	checkList(int id)
{
  int	i;

  i = 0;
  while (g_waitingList[i] != (-1))
    {
      if (id == g_waitingList[i])
	return (-1);
      i++;
    }
  return (0);
}

void	addToList(int id)
{
  int	i;

  i = 0;
  while (g_waitingList[i] != (-1))
    i++;
  if (i >= 7)
    return ;
  g_waitingList[i] = id;
}

void	removeFromList()
{
  int	i;
  
  i = 0;
  while (g_waitingList[i] != (-1))
    {
      g_waitingList[i] = g_waitingList[i + 1];
      i++;
    }
  if (i >= 7)
    return ;
  g_waitingList[i] = -1;
}
