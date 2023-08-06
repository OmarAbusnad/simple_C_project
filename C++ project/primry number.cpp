#include<iostream>
#include<string>
using namespace std;

struct stack
{
	int data;
	stack *next;
	stack *post;
};
stack *head=NULL;
void push(int d)
{
if(head==NULL)
{
	head=new stack;
	head->data=d;
	head->next=NULL;
	head->post=NULL;
	return ;
}
	head->post=new stack;
	head->post->next=head;
	head=head->post;
	head->data=d;
	head->post=NULL;

	
	
}
int pop()
{
	if(head==NULL){
	cout<<"is empty\n";
	return INT_MAX;
	}	
	stack *old=head;
	head=head->next;
	int n=old->data;
	delete old;
	return n;	
}
void delete_prim_nim(stack *&old)
{
	if(old->post==NULL)
	{
		head=head->next;
		head->post=NULL;
		delete old;
		return ;
	}
	stack *temp=old->post,*temp2=old->next;
	delete old;
	temp->next=temp2;
	temp2->post=temp;

}

void check_prim_nim(stack *&check)
{
	bool x=true;
	stack *temp=check,*temp2;
	if(temp!=NULL)
	{
			for(int i=2; i<temp->data; i++)
		{
			if(temp->data%i==0)
	      	x=false;
		}
	  	 temp2=temp->next;
		if(x==true)
		{
			delete_prim_nim(temp);
		}
			check_prim_nim(temp2);
cout<<endl;
	}
	

}
void display(stack *&head)
{
	if(head!=NULL)
	{
		stack *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
int main()
{
push( 10);
	push( 5);
	push( 8);push(7 );
	push(100 );
	push(151 );
	display(head);
	check_prim_nim(head);
	cout<<"\n ****************\n ";
	display(head);
/*	int x[]={20,25,33,11,7};
	for(int i=0; i<5; i++)
	{
		for(int j=2; j<x[i]; j++)
		{
			if(x[i]%j!=0)
			{
				cout<<x[i]<<endl;
				break;
			}
		}
	}
*/	
}