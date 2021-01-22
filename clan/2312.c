#include <stdio.h>
int main()
{
	int num, prob_num, temp;
	int prime[100001] = { 0 };
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &prob_num);
		temp = prob_num;
		for (int j = 2; prob_num != 1; j++)
		{
			if (prob_num%j == 0)
			{
				prime[j]++;
				prob_num /= j;
				j--;
			}
		}
		for (int j = 2; j <= temp; j++)
		{
			if (prime[j] != 0)
			{
				printf("%d %d\n", j, prime[j]);
				prime[j] = 0;
			}
		}
	}
}