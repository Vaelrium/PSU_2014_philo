/*
** philo.c for philo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 10:57:04 2015 Rémi DURAND
** Last update Mon Feb 23 15:00:23 2015 Rémi DURAND
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

int			g_endExec = 0;

void		*phil_beg(void *arg)
{
  t_phil	cur_phil;

  cur_phil = *((t_phil *)arg);
  printf("Philosopher n° %d, %s gets a seat\n",
	 cur_phil.id_phil, cur_phil.name);
  while (!g_endExec)
    {
      algo(&cur_phil);
    }
  printf("Philosopher n° %d, %s gets back to his Cogitum\n",
	 cur_phil.id_phil, cur_phil.name);
  pthread_exit(NULL);
  return (NULL);
}

void		wait_end(pthread_t th_tab[])
{
  int		v;

  v = 0;
  while (v != 7)
    pthread_join(th_tab[v++], NULL);
}

int		main()
{
  t_phil	phils[7];
  pthread_t	th_tab[7];

  init_all(phils, th_tab);
  sleep(EXEC_TIME);
  g_endExec = 1;
  wait_end(th_tab);
  return (0);
}
