/*
** algo.c for algo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Feb 23 13:00:51 2015 Rémi DURAND
** Last update Tue Feb 24 15:01:14 2015 Rémi DURAND
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

pthread_mutex_t		g_mut_tab[7];
int    			g_waitingList[8];

void		eat(int cur_id, int get_id)
{
  printf("Phil n° %d begin to eat\n", cur_id);
  sleep(EAT_TIME);
  printf("Phil n° %d finish to eat\n", cur_id);
  pthread_mutex_unlock(&g_mut_tab[cur_id]);
  pthread_mutex_unlock(&g_mut_tab[get_id]);
}

int		try_eat(t_phil *phil)
{
  int		id;
  int		ret1;
  int		ret2;

  ret1 = -1;
  ret2 = -1;
  id = phil->id_phil;
  if ((ret1 = pthread_mutex_trylock(&g_mut_tab[id])) == 0 &&
      (ret2 = pthread_mutex_trylock(&g_mut_tab[NEXT(id)])) == 0 &&
      id == g_waitingList[0])
      {
	removeFromList();
	phil->canRest = 1;
	return (NEXT(id));
      }
    else
      {
	if (ret1 == 0)
	  pthread_mutex_unlock(&g_mut_tab[id]);
	if (ret2 == 0)
	  pthread_mutex_unlock(&g_mut_tab[NEXT(id)]);
	return (-1);
      }
}

void		think(t_phil *cur_phil, int id)
{
  if (checkList(cur_phil->id_phil) == 0)
    addToList(cur_phil->id_phil);
  cur_phil->canRest = 0;
  printf("Philosopher n°%d, %s, thinks about dicks and stuff.\n",
	 id, cur_phil->name);
  sleep(THINK_TIME);
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
  cur_phil->canRest = 0;
  sleep(REST_TIME);
}
