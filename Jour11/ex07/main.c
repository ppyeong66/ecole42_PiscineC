/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:40:48 by ajouanna          #+#    #+#             */
/*   Updated: 2016/09/14 13:34:50 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_list.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != 0)
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char			chardigit;
	unsigned int	unb;

	unb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		unb = -nb;
	}
	if (unb < 10)
	{
		chardigit = '0' + unb;
		ft_putchar(chardigit);
	}
	else
	{
		ft_putnbr(unb / 10);
		ft_putnbr(unb % 10);
	}
}

void	print_list(t_list *list)
{
	ft_putstr("print_list : Nbre d elements dans la list = ");
	ft_putnbr(ft_list_size(list));
	ft_putchar('\n');
	while (list)
	{
		ft_putstr(list->data);
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_list *list;
	t_list *listat;

	ft_putstr("main : appel a ft_list_push_param\n");
	list = ft_list_push_params(argc, argv);
	print_list(list);
	ft_putchar('\n');
	ft_putstr("main : appel a ft_list_at\n");
	listat = ft_list_at(list, 3);
	print_list(listat);
	ft_putchar('\n');
	ft_putstr("main : appel a ft_list_clear\n");
	ft_list_clear(&list);
	if (list != NULL)
		ft_putstr("main : pointeur mal desalloue\n");
	return (0);
}
