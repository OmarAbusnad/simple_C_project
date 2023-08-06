#include <iostream.h>

struct node
{
	int data;
	node *left;
	node *right;
};
void insert(node *&root,int d)
{
    
		if(root==NULL)
		{
		  root=new node;
       	root->data=d;
    	root->right=NULL;
		root->left=NULL;
		}
	else
	{
		if(d<root->data)
		insert(root->left,d);
		else
		insert(root->right,d);
	}
}
void in_order(node *show)
{
	if(show!=NULL)
	{
	in_order(show->right);
	cout<<show->data<<"  ";
	in_order(show->left);
	}
}

void pre_order(node *show)
{
	if(show!=NULL)
	{
	cout<<show->data<<"  ";
	pre_order(show->right);
	pre_order(show->left);
	
	}
}

void post_order(node *show)
{
	if(show!=NULL)
	{
		post_order(show->right);
	post_order(show->left);
	
	cout<<show->data<<"  ";
	}
}

void fath_node(node *root,int d)
{
	if(d==root->data)
	cout<<"IT is the root \n";
	else if(d>root->data)
	{
		if(d==root->right->data)
		cout<<"The parent of node is : "<<root->data;
		else
		fath_node(root->right,d);
	}
		else if(d<root->data)
	{
		if(d==root->left->data)
		cout<<"The parent of node is : "<<root->data;
		else
		fath_node(root->left,d);
	}
	else
	cout<<"IT is error value \n";
}
void broth_node(node *root,int d)
{
	if(d==root->data)
	cout<<"IT is the root \n";
	else if(d>root->data)
	{
		if(d==root->right->data)
		{
			if(root->left!=NULL)
		    cout<<"The brother of node is : "<<root->left->data;
		    else
		    cout<<"It hasn't a brither\n";
		}
		else
		broth_node(root->right,d);
	}
		else if(d<root->data)
	{
		if(d==root->left->data)
		{
			if(root->right!=NULL)
			cout<<"The brother of node is : "<<root->right->data;
			else
			cout<<"It hasn't a brither\n";
		}
		else
		broth_node(root->left,d);
	}
	else
	cout<<"IT is error value \n";
}

int main(int argc, char *argv[])
{
	int item;
	node *root=NULL;
	for(int i=0; i<9; i++)
	{
		cin>>item;
		insert(root,item);
	}
	
	in_order(root);
	cout<<"\n **********************\n  ";
	pre_order(root);
	cout<<"\n **********************\n  ";
	post_order(root);
	
/*	int x;	
cout<<"\n **********************\n  ";
cout<<"Enter nember : ";
cin>>x;
cout<<"\n **********************\n  ";
fath_node(root,x);
cout<<"\n **********************\n  ";
broth_node(root,x)	;*/
cout<<endl;
}
