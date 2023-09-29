/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:43:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/09/29 02:34:16 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void print_vector(int *kids, int *doces, int size)
{
	for(int i = 0; i < size; i++)
		printf("Nota: %d - Doces: %d \n", kids[i], doces[i]);
}

void	manage_candies(int kids[], int sizekids, int doces[])
{
	int	i = 0;
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
}

void	equality(int kids[], int sizekids, int doces[])
{
	int	i = sizekids - 2;
	while(i  >= 0)
	{
		if(kids[i] > kids[i + 1] && doces[i] <= doces[i + 1])
		{
			doces[i] = doces [i + 1] + 1;
		}
		else if (kids[i] < kids[i + 1] && doces[i + 1] <= doces[i])
		{
			doces[i + 1] = doces[i] + 1;
		}
		i--;
	}
}

int	candy(int kids[], int sizekids)
{
	int	i;
	int	doces[sizekids];
	int	candysum;

	candysum = 0;
	i = 0;
	for (int j = 0; j < sizekids; j++)
		doces[j] = 1;
	manage_candies(kids, sizekids, doces);
	equality(kids, sizekids, doces);
	print_vector(kids, doces, sizekids);
	for(int i = 0; i < sizekids; i++)
		candysum += doces[i];
	return (candysum);
}

int	main(void)
{
	int a[] = {7, 8, 5, 3, 2, 1, 1};
	printf("Total Candies: %d\n", candy(a, sizeof(a) / sizeof(a[0])));

	int b[] = {1, 0, 2};
	printf("\nTotal Candies: %d\n", candy(b, sizeof(b) / sizeof(b[0])));

	int c[] = {1, 2, 2};
	printf("\nTotal Candies: %d\n", candy(c, sizeof(c) / sizeof(c[0])));
	return (0);
}


//7 8 5 3 2 1 1
//1 1 1 1 1 1 1
//1 2
//1 3 1
//1 3 2 1
//1 3 2 2 1
//1 3 2 2 2 1
//1 3 2 2 2 1 1 <- final result from left to right

//1 3 2 2 2 1 1
//1 3 2 2 2 1 1
//1 3 2 3 2 1 1
//1 3 4 3 2 1 1
//1 5 4 3 2 1 1
//1 5 4 3 2 1 1 <- Final result right to left

