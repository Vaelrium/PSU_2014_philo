/*
** philo.c for philo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 10:57:04 2015 Rémi DURAND
** Last update Thu Feb 19 15:50:33 2015 Rémi DURAND
*/

#include <stdio.h>
#include <pthread.h>
#include "philo.h"

char		g_table[7] = {1, 1, 1, 1, 1, 1, 1};

void		*phil_beg(void *arg)
{
  t_phil	cur_phil;

  cur_phil = *((t_phil *)arg);
  printf("Philosopher n° %d, %s get a seat\n", cur_phil.id_phil, cur_phil.name);
  while (42)
    {
      ;
    }
  return (NULL);
}

int		main()
{
  t_phil	phils[7];
  pthread_t	th_tab[7];

  init_all(phils, th_tab);
  pthread_join(th_tab[6], NULL);
  return (0);
}
