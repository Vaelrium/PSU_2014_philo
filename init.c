/*
** init.c for init in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 14:52:35 2015 Rémi DURAND
** Last update Tue Feb 24 14:25:08 2015 Rémi DURAND
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

pthread_mutex_t	g_mut_tab[7];
int    	       	g_waitingList[8];

void		init_list()
{
  int		v;

  v = 0;
  while (v != 8)
    g_waitingList[v++] = (-1);
}

void		init_phil(t_phil phils[])
{
  int		v;

  v = 0;
  while (v != 7)
    {
      phils[v].id_phil = v;
      phils[v].canRest = 0;
      ++v;
    }
  phils[0].name = strdup("Socrate");
  phils[1].name = strdup("Platon");
  phils[2].name = strdup("Freud");
  phils[3].name = strdup("Descartes");
  phils[4].name = strdup("Debord");
  phils[5].name = strdup("Marx");
  phils[6].name = strdup("Spinoza");
}

int		init_thread(pthread_t th_tab[], t_phil phils[])
{
  int		v;

  v = 0;
  while (v != 7)
    {
      if (pthread_create(&th_tab[v], NULL, phil_beg, &phils[v]) != 0)
	return (-1);
      ++v;
    }
  return (0);
}

int		init_all(t_phil phils[], pthread_t th_tab[])
{
  int		v;

  v = 0;
  while (v == 7)
    {
      pthread_mutex_init(&g_mut_tab[v], NULL);
      ++v;
    }
  init_phil(phils);
  init_list();
  return (init_thread(th_tab, phils));
}
