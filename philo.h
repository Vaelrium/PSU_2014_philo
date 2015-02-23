/*
** philo.h for philo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 11:09:26 2015 Rémi DURAND
** Last update Mon Feb 23 14:01:44 2015 Rémi DURAND
*/

#ifndef _PHI_H_
# define _PHI_H_

# define EXEC_TIME 20
# define EAT_TIME 3
# define THINK_TIME 2
# define NEXT(x) (x == 6 ? 0 : (x + 1))
# define PREV(x) (x == 0 ? 6 : (x - 1))

typedef struct		s_phil
{
  int			id_phil;
  char			*name;
  char			canRest;
}			t_phil;

int			init_all(t_phil phils[], pthread_t th_tab[]);
void			*phil_beg(void *arg);
void			algo(t_phil *cur_phil);

extern pthread_mutex_t	g_mut_tab[7];

#endif /* !_PHI_H_ */
