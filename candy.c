/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:43:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/09/28 22:08:49 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void print_vector(int *kids, int *doces, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("Nota: %d - Doces: %d \n", kids[i], doces[i]);
	}
}

void	candy(int kids[], int sizekids)
{
	int i;
	int doces[sizekids];
	
	i = 0;
	for (int j = 0; j < sizekids; j++)
		doces[j] = 1;
	while(i < sizekids)
	{
		if(kids[i] > kids[i + 1] && doces[i] <= doces[i + 1])
		{
			doces[i] = doces [i + 1] + 1;
		}
		else if (kids[i] < kids[i + 1] && doces[i + 1] <= doces[i])
		{
			doces[i + 1] = doces[i] + 1;
		}
		i++;
	}
	
	print_vector(kids, doces, sizekids);

}

int	main(void)
{
	int a[] = {7, 8, 5, 3, 2, 1, 1};
	candy(a, sizeof(a) / sizeof(a[0]));
	return (0);
}
