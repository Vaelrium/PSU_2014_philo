/*
** philo.h for philo in /home/durand_u/github/PSU_2014_philo
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Feb 19 11:09:26 2015 Rémi DURAND
** Last update Thu Feb 19 15:29:24 2015 Rémi DURAND
*/

#ifndef _PHI_H_
# define _PHI_H_

# define EAT 0
# define THINK 1
# define REST 2
# define INIT 3

typedef struct		s_phil
{
  char			state;
  char			id_phil;
  char			*name;
}			t_phil;

int			init_all(t_phil phils[], pthread_t th_tab[]);
void			*phil_beg(void *arg);

#endif /* !_PHI_H_ */
