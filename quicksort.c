/*Description:Implemention of Quick Sort
 learner:Muskan Akbar Shaikh
 */
 
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int  split(int arr[],int lower,int upper)
{
	int temp;
	int pivot=lower;
	int a=pivot+1;
	int b=upper;
	
	while(b>=a)
	{
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if(b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[b];
	arr[b]=arr[pivot];
	arr[pivot]=temp;
	return b;
}




void quick_sort(int arr[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
	i=split(arr,lower,upper);
	quick_sort(arr,lower,i-1);
	quick_sort(arr,i+1,upper);
	}

}

int main()
{
	int i,n;
	int arr[MAX_SIZE];
	printf("Enter the no of elements");
	scanf("%d",&n);
	printf("Enter the elements \n");
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	printf("sorted array is\n");
	for(i=0;i<n;i++)
	{
	printf("%d\n",arr[i]);
	}
	return 0;
}
/*output
 * Enter the no of elements5
Enter the elements 
3
6
34
7
5
sorted array is
3
5
6
7
34


------------------
(program exited with code: 0)
Press return to continue
*/

