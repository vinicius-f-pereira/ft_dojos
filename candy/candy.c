/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:43:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/09/29 15:43:17 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	candy(int kids[], int sizekids);
static void	print_vector(int *kids, int *candies, int size);
static void	manage_candies(int kids[], int sizekids, int candies[]);
static void	equality(int kids[], int sizekids, int candies[]);

int	main(void)
{
	/* dojo example */ //total 17 candies
	int a[] = {7, 8, 5, 3, 2, 1, 1};
	printf("Total Candies: %d\n\n", candy(a, sizeof(a) / sizeof(a[0])));

	/* leetcode example */ //total 5 candies
	int b[] = {1, 0, 2};
	printf("Total Candies: %d\n\n", candy(b, sizeof(b) / sizeof(b[0])));

	/* leetcode example */ //total 4 candies
	int c[] = {1, 2, 2};
	printf("Total Candies: %d\n", candy(c, sizeof(c) / sizeof(c[0])));
	return (0);
}

/**
 * @brief Function that randle with ratings and candies
 * @param int Kids[] Array of ratings of each kid
 * @param int sizekids Lenght of the array
 * @return Sum of candies at the end of distribution of candies
 */
static int	candy(int kids[], int sizekids)
{
	int	i;
	int	candies[sizekids];
	int	candysum;

	candysum = 0;
	i = 0;
	for (int j = 0; j < sizekids; j++)
		candies[j] = 1;
	manage_candies(kids, sizekids, candies);
	equality(kids, sizekids, candies);
	print_vector(kids, candies, sizekids);
	for(int i = 0; i < sizekids; i++)
		candysum += candies[i];
	return (candysum);
}

/**
 * @brief This function just print side by side final value of the ratings and candies
 * @param int *kids Array of ratings of each kid
 * @param int size Lenght of the array
 * @param int *candies Array of candies of each kid
 * @return Sum of candies at the end of distribution of candies
 */
static void print_vector(int *kids, int *candies, int size)
{
	for(int i = 0; i < size; i++)
		printf("Nota: %d - Doces: %d \n", kids[i], candies[i]);
}

/**
 * @brief This function divide candies proportionally
 * among the children based on your grades (from right to left)
 * @param int *kids Array of grade of each kid
 * @param int sizekids Lenght of the array of kids
 * @param int *candies Array of candies of each kid
 * @return Void
 */
static void	manage_candies(int kids[], int sizekids, int candies[])
{
	int	i = 0;
	while(i < sizekids - 2)
	{
		if(kids[i] > kids[i + 1] && candies[i] <= candies[i + 1])
		{
			candies[i] = candies [i + 1] + 1;
		}
		else if (kids[i] < kids[i + 1] && candies[i + 1] <= candies[i])
		{
			candies[i + 1] = candies[i] + 1;
		}
		i++;
	}
}

/**
 * @brief This function divide candies proportionally
 * among the children based on your grades (from left to right)
 * @param int *kids Array of grade of each kid
 * @param int sizekids Lenght of the array of kids
 * @param int *candies Array of candies of each kid
 * @return Void
 */
static void	equality(int kids[], int sizekids, int candies[])
{
	int	i = sizekids - 2;
	while(i  >= 0)
	{
		if(kids[i] > kids[i + 1] && candies[i] <= candies[i + 1])
		{
			candies[i] = candies [i + 1] + 1;
		}
		else if (kids[i] < kids[i + 1] && candies[i + 1] <= candies[i])
		{
			candies[i + 1] = candies[i] + 1;
		}
		i--;
	}
}
