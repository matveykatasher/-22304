# include <stdio.h>
# include <stdbool.h>
# include <math.h>	

bool isPrime(int n)
{
	if (n == 1 || n == 0)
		return false;
	
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	} 
	return true;
	
}

int main()
{
	int N;
	printf("enter N\n");
	scanf("%d", &N);
		for (int i = 1; i <= N; i++) 
		{
			if (isPrime(i))
			{
				printf("%d ", i);
			}
		}
	int L;
	scanf("%d",&L);
	return 0;
}


