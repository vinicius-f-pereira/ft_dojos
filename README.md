# ft_dojos
Dojos 42

This is a challenge from 42SP's school.

Based on leetcode challenge, we need to solve the following problem:

```
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```

A part of the logic used to solve this challenge:
```
Array of kid's grade: 7 8 5 3 2 1 1
Candeies:             1 1 1 1 1 1 1
1st comparation:      1 2
2nd comparation:      1 3 1
3rd comparation:      1 3 2 1
4th comparation:      1 3 2 2 1
5th comparation:      1 3 2 2 2 1
6th comparation:      1 3 2 2 2 1 1 <- final result from left to right


Array of kid's grade: 7 8 5 3 2 1 1
Candeies:             1 3 2 2 2 1 1
1st comparation:      1 3 2 2 2 1 1
2nd comparation:      1 3 2 3 2 1 1
3rd comparation:      1 3 4 3 2 1 1
4th comparation:      1 5 4 3 2 1 1 
5th comparation:      1 5 4 3 2 1 1
6th comparation:      1 5 4 3 2 1 1 <- Final result right to left

total candies -> 17
```

Link to leetcode challeng: [Leet Code Candie Challenge](https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150)
