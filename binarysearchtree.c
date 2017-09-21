/*Description:Implement Binary Search Tree
 learner:Muskan Akbar Shaikh
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *q)
{
	if(q!=NULL){
     traverse_inorder(q->left);
     printf("%d\t",q->data);
     traverse_inorder(q->right);
	}
}
   	
void insert(node **r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)	
	{	   	
	       ptr=(node*)malloc(sizeof(node));
            ptr->data=num;
	        ptr->left=NULL;
	        ptr->right=NULL;
		 *r=ptr;
	 }
	else{
		if(num>temp->data){
                 insert(&temp->right,num);
           }
         else{
			   insert(&temp->left,num);
			}
		}
   }
   
int search_bst(node *q,int num){
	if(q==NULL)
	{	   	
	    return 0;
	 }
	else{
		if(q->data==num)
		   return 1;
		else{
		     if(num>q->data)
		     {
				 search_bst(q->right,num);
		     }
		   else{
            search_bst(q->left,num);
		   }
	   }
   }
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	 if(temp==NULL)
	   return;

		while(temp!=NULL)
		{
			if(temp->data==num)
	    {
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
			if(num>temp->data)
			    temp=temp->right;
			 else
			    temp=temp->left;
		}
   }
   
void delete(node **q,int num){
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;x=NULL;xsucc=NULL;
	temp=*q;
	search_node(&x,temp,&parent,num,&f);
	if(f==0)
	{	   	
	    printf("\n The Element %d is not found",num);
	    return;
	 }
	 //x has no child
	 if(x->left==NULL && x->right==NULL)
	 {
		 if(x->data >parent->data)
		    parent->right=NULL;
		 else
		    parent->left=NULL;
		 
	 }
	 //x has left child
	else if(x->left!=NULL && x->right==NULL)
	{
		if(x->data >parent->data)
		    parent->right=x->left;
		 else
		    parent->left=x->left;
	}
	//x has right child
	else if(x->right!=NULL && x->right==NULL)
	{
		if(x->data >parent->data)
		    parent->right=x->right;
		 else
		    parent->left=x->right;
		 
	}
	//x has both child
	else if(x->left!=NULL && x->right!=NULL)
    {
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		if(xsucc->data >parent->data)
		    parent->right=NULL;
		 else
		    parent->left=NULL;
		  x->data=xsucc->data;
		  x=xsucc;
	}
	 free(x);
}

int main()
{
	node *root;
	root=NULL;
   	insert(&root,20);
   	insert(&root,15);
    insert(&root,13);
    insert(&root,17);
    insert(&root,16);
    insert(&root,19);
    insert(&root,18);
    insert(&root,25);
    insert(&root,26);
    traverse_inorder(root);
    if(search_bst(root,7)==1)
         printf("\n the %d is present",7);
       else
       printf("\n not found");
       delete(&root,17);
       traverse_inorder(root);
       
    return 0;
 }
	
		
            
