/*
** philo.c for philo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 10:57:04 2015 Rémi DURAND
** Last update Tue Feb 24 14:55:57 2015 Rémi DURAND
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

int		g_endExec = 0;

void		*phil_beg(void *arg)
{
  t_phil	cur_phil;
  int		ret;

  cur_phil = *((t_phil *)arg);
  printf("Philosopher n° %d, %s gets a seat\n",
	 cur_phil.id_phil, cur_phil.name);
  addToList(cur_phil.id_phil);
  while (!g_endExec)
    {
      if ((ret = try_eat(&cur_phil)) != (-1))
	eat(cur_phil.id_phil, ret);
      if (cur_phil.canRest && !g_endExec)
	rest(&cur_phil);
      else if (!g_endExec && ret == (-1))
      try_think(&cur_phil);
    }
  printf("~ %s fucks off\n", cur_phil.name);
  pthread_exit(NULL);
  return (NULL);
}

void		wait_end(pthread_t th_tab[])
{
  int		v;

  v = 0;
  while (v != 7)
    pthread_join(th_tab[v++], NULL);
  printf("The table is now empty\n");
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
