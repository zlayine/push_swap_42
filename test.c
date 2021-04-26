int med_val(int *arr, int len)
{
	int med;
	int i;
	int sum;

	sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	med = sum / 2;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < med && med <= arr[i + 1])
		{
			return arr[i];
		}
	}
	return (med);
}

#include <stdio.h>

int main()
{
	int arr[] = {1, 3, 2 };
	printf("med = %d\n", med_val(arr, 3));
}