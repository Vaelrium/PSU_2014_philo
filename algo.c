/*
** algo.c for algo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Feb 23 13:00:51 2015 Rémi DURAND
** Last update Tue Feb 24 10:13:40 2015 Rémi DURAND
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

pthread_mutex_t		g_mut_tab[7];

void		wait_n_time(int nbSec)
{
  sleep(nbSec);
}

void		eat(int cur_id, int get_id)
{
  printf("Phil n° %d begin to eat\n", cur_id);
  wait_n_time(EAT_TIME);
  printf("Phil n° %d finish to eat\n", cur_id);
  pthread_mutex_unlock(&g_mut_tab[cur_id]);
  pthread_mutex_unlock(&g_mut_tab[get_id]);
}

int		try_eat(t_phil *phil)
{
  int		id;

  id = phil->id_phil;
  if (pthread_mutex_trylock(&g_mut_tab[id]) == 0 &&
      pthread_mutex_trylock(&g_mut_tab[NEXT(id)]) == 0)
    {
      phil->canRest = 1;
      return (NEXT(id));
    }
  else
    {
      pthread_mutex_unlock(&g_mut_tab[id]);
      pthread_mutex_unlock(&g_mut_tab[NEXT(id)]);
      return (-1);
    }
}

void		think(t_phil *cur_phil, int id)
{
  printf("Philosopher n°%d, %s, thinks about dicks and stuff.\n", 
	 id, cur_phil->name);
  wait_n_time(THINK_TIME);
  printf("Philosopher n°%d, %s, is done thinking about dongs.\n", 
	 id, cur_phil->name);
  pthread_mutex_unlock(&g_mut_tab[id]);
}

void		try_think(t_phil *cur_phil)
{
  int		id;
  
  id = cur_phil->id_phil;
  if (pthread_mutex_trylock(&g_mut_tab[id]) == 0)
    think(cur_phil, id);
  else if (pthread_mutex_trylock(&g_mut_tab[NEXT(id)]) == 0)
    think(cur_phil, NEXT(id));
}

void		rest(t_phil *cur_phil)
{
  printf("%s burps and rest\n", cur_phil->name);
}
/*
void		algo(t_phil *cur_phil)
{
  int		ret;

  if ((ret = try_eat(cur_phil)) != (-1))
    eat(cur_phil->id_phil, ret);
  if (cur_phil->canRest)
    rest(cur_phil);
  try_think(cur_phil);
}
*/
