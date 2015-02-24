/*
** philo.h for philo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 11:09:26 2015 Rémi DURAND
** Last update Tue Feb 24 10:18:44 2015 Rémi DURAND
*/

#ifndef _PHI_H_
# define _PHI_H_

# define EXEC_TIME 60
# define EAT_TIME 3
# define THINK_TIME 2
# define NEXT(x) (x == 6 ? 0 : (x + 1))

typedef struct		s_phil
{
  int			id_phil;
  char			*name;
  char			canRest;
}			t_phil;

int			init_all(t_phil phils[], pthread_t th_tab[]);
void			*phil_beg(void *arg);
void			algo(t_phil *cur_phil);
void			rest(t_phil *cur_phil);
void			try_think(t_phil *cur_phil);
void			think(t_phil *cur_phil, int id);
int			try_eat(t_phil *phil);
void			eat(int cur_id, int get_id);


extern pthread_mutex_t	g_mut_tab[7];

#endif /* !_PHI_H_ */
