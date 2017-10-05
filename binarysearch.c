/*Description:Implemention of  Binary Search
 learner:Muskan Akbar Shaikh
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100


int binary_search(int a[],int n,int x)
{
	int mid=n/2;
	int high=n-1,low=0;
	while(high>=low)
	{
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			low=mid+1;
		else
			high=mid-1;
		mid=(low+high)/2;
	}
	return -1;
}

int main()
{
	int x,i,res,n;
	int a[MAX_SIZE];
	printf("Enter the no of elements");
	scanf("%d",&n);
	printf("Enter the elements in ascending order\n");
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	printf("Enter the elements to be search");
	scanf("%d",&x);
	res=binary_search(a,n,x);
	if(res==-1)
	 printf("number is not found");
	else
	 printf("number is located on %d",res);
	 
	 return 0;
 }
	
	
/*output
 * 
Enter the no of elements5
Enter the elements in ascending order
7
8
9
10
11
Enter the elements to be search9
number is located on 2

------------------
(program exited with code: 0)
Press return to continue
*/
