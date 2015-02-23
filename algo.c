/*
** algo.c for algo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Feb 23 13:00:51 2015 Rémi DURAND
** Last update Mon Feb 23 14:32:20 2015 Ambroise Coutarel
*/

#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

char			g_table[7] = {1, 1, 1, 1, 1, 1, 1};
pthread_mutex_t		g_mut_tab[7];

void		wait_n_time(int nbSec)
{
  int		toWait;

  toWait = time(0) + nbSec;
  while (time(0) < toWait)
    ;
}

void		eat(int cur_id, int get_id)
{
  g_table[cur_id] += 1;
  pthread_mutex_lock(&g_mut_tab[cur_id]);
  printf("Phil n° %d begin to eat\n", cur_id);
  wait_n_time(EAT_TIME);
  printf("Phil n° %d finish to eat\n", cur_id);
  pthread_mutex_unlock(&g_mut_tab[cur_id]);
  g_table[get_id] += 1;
  g_table[cur_id] -= 1;
}

void		try_eat(t_phil *phil)
{
  int		id;

  id = phil->id_phil;
  if (g_table[id] == 1 && pthread_mutex_trylock(&g_mut_tab[NEXT(id)]) == 0 &&
      g_table[NEXT(id)] == 1)
    {
      pthread_mutex_unlock(&g_mut_tab[NEXT(id)]);
      g_table[NEXT(id)] -= 1;
      eat(id, NEXT(id));
      phil->canRest = 1;
    }
  else if (g_table[id] == 1 && pthread_mutex_trylock(&g_mut_tab[PREV(id)]) == 0 &&
      g_table[PREV(id)] == 1)
    {
      pthread_mutex_unlock(&g_mut_tab[PREV(id)]);
      g_table[PREV(id)] -= 1;
      eat(id, PREV(id));
      phil->canRest = 1;
    }
}

void		think(t_phil *cur_phil, int id)
{
  pthread_mutex_lock(&g_mut_tab[id]);
  printf("Philosopĥer n°%d, %s, thinks about dicks and stuff.\n", 
	 id, cur_phil->name);
  wait_n_time(THINK_TIME);
  printf("Philosopĥer n°%d, %s, is done thinking about dongs.\n", 
	 id, cur_phil->name);
  pthread_mutex_unlock(&g_mut_tab[id]);
}

void		try_think(t_phil *cur_phil)
{
 int		id;

  id = cur_phil->id_phil;
  if (g_table[id] == 1)
    think(cur_phil, id);
  else if (pthread_mutex_trylock(&g_mut_tab[NEXT(id)]) == 0 &&
	   g_table[NEXT(id)] == 1)
    {
      pthread_mutex_unlock(&g_mut_tab[NEXT(id)]);
      g_table[NEXT(id)] -= 1;
      think(cur_phil, id);
      g_table[NEXT(id)] += 1;
    }
  else if (pthread_mutex_trylock(&g_mut_tab[PREV(id)]) == 0 &&
	   g_table[PREV(id)] == 1)
    {
      pthread_mutex_unlock(&g_mut_tab[PREV(id)]);
      g_table[PREV(id)] -= 1;
      think(cur_phil, id);
      g_table[PREV(id)] += 1;
    }
}

void		rest(t_phil *cur_phil)
{
  printf("%s burps and rest\n", cur_phil->name);
}

void		algo(t_phil *cur_phil)
{
  try_eat(cur_phil);
  if (cur_phil->canRest)
    rest(cur_phil);
  try_think(cur_phil);
}
