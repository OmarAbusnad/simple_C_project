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
int max_value(stack *&check, int max)
{
	stack *temp=check;
	if(temp!=NULL)
	{
		if(max<temp->data)
		max=temp->data;
	return	max_value(temp->next,max);
	}
	return max;
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
	push( 5000);
	push( 8);push(7 );
	push(1000);
	push(100 );
	push(15 );
	push(1 );
    display(head);
	cout<<"\n ****************\n";
	cout<<"The maxsimm value in stack is :"<<max_value(head,0)<<endl;

}