#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500
void choicesort(int array[], int size);
void insertionsort(int v[], int size_v);
int binarysearch(int a, int mass[], int n);
int main(void){
int a[MAX];
int i=0;
int b[MAX];
int c[MAX];
while(i != MAX)
 {
 a[i] = rand()%100;
b[i]=a[i];
c[i]=a[i];
 i++;
 }
struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC, &start);

choicesort(b, MAX);

clock_gettime(CLOCK_MONOTONIC, &end);
 printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec));


 clock_gettime(CLOCK_MONOTONIC, &start);
insertionsort(c, MAX);
clock_gettime(CLOCK_MONOTONIC, &end);
 printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec));


int as=rand()%100;
as=rand()%100;
as=rand()%100;
as=rand()%100;
int k, k1;

 clock_gettime(CLOCK_MONOTONIC, &start);
 k = binarysearch(as, b, MAX);
    if (k != -1)
    {
        printf("The index of the element is %d\n", k);
    }
    else
        printf("The element isn't found!\n");

         clock_gettime(CLOCK_MONOTONIC, &end);
 printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec));

 clock_gettime(CLOCK_MONOTONIC, &start);
  k1 = binarysearch(as, c, MAX);
    if (k1 != -1)
    {
        printf("The index of the element is %d\n", k1);
    }
    else
        printf("The element isn't found!\n");
        clock_gettime(CLOCK_MONOTONIC, &end);
 printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec));

return 0;
}
void choicesort(int array[], int size){
int i = 0;
    while(i < size)
{
    int min_i = i;
	int j = i + 1;
	while( j < size)
    {
		if (array[j] < array[min_i])
        {
			min_i = j;
		}
		j++;
	}
	int temp = array[i];
	array[i] = array[min_i];
	array[min_i] = temp;
i++;
}

}
void insertionsort(int v[], int size_v)
{
	if(size_v <= 1)
		return;

	int i, j, key;

	for(i = 1; i < size_v; i++)
	{
		j = i;
		key = v[i];
		while(j > 0 && v[j - 1] > key)
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = key;
	}
}
int binarysearch(int a, int mass[], int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
            high = middle - 1;
        else if (a > mass[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}
