/*Description:Implemention of  hashing
 learner:Muskan Akbar Shaikh
 */


#include<stdio.h>
#include<math.h>
#define MAX_SIZE 20

int hash(int k)
{
	return k%MAX_SIZE;
}

int linear_prob(int h){
	return ++h%MAX_SIZE;
}

int quadratic_prob(int h,int i){
	return (int)(h+pow(i,2))%MAX_SIZE;
}

int double_hashing(int h,int i)
{
	return (h+i*linear_prob(h))%MAX_SIZE;
}

void display(int a[])

{
	int i;
	printf("\n Elements of array are\n");
	for(i=0;i<MAX_SIZE;i++)
	{
		printf("%d\t",a[i]);
	}
}

int main(){
	int a[MAX_SIZE],i,h,e,count;
	for(i=0;i<MAX_SIZE;i++)
		a[i]=-1;
	do{
		count=0;
		printf("\nEnter the number to be stored");
		scanf("%d",&e);
		h=hash(e);
		if(a[h]==-1){
			a[h]=e;
			display(a);
		}
		else
			{
				while(count<MAX_SIZE){
					count++;
					int c;
					printf("collision occured at %d\n",h);
					printf("\nEnter your choice\n");
					printf("\n 1.linear probe\n 2.quadratic probe \n 3.double hashing\n");
					scanf("%d",&c);
					switch(c)
					{		
						case 1:
						       h=linear_prob(h);
						       break;
						case 2:
						       h=quadratic_prob(h,count);
						       break;		
				        case 3:
				              h=double_hashing(h,count);
				              break;
				         default:
				                 printf("\n invalid choice\n");
				                 count--;
				                 break;
							}
				          if(a[h]==-1)
				          {
					      a[h]=e;
					      display(a);
					      break;
				          }
			     }
			 }
			  if(count==MAX_SIZE)
			  {
				  printf("\nArray is full");
				  return 0;
			  }
		  }while(1);
	  }
			
