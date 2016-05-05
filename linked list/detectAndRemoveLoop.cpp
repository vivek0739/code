#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
int countLoopNode(Node *head,Node *loopNode)
{
	Node *ptr=loopNode;
	int k=1;
	while(ptr->next!=loopNode)
	{
		ptr=ptr->next;
		k++;
	}
	return k;
}
void RemoveLoop(Node *head,Node *loopNode)
{
	int k=countLoopNode(head,loopNode);
	Node *first,*second;
	first=head;
	second=head;
	for(int i=0;i<k-1;i++)
	{
		first=first->next;
	}
	while(first->next!=second)
	{
		first=first->next;
		second=second->next;

	}
	first->next=NULL;
}

void detectAndRemoveLoop(Node *head)
{
	if(head == NULL )
		return ;
	Node *first,*second;
	first=head;
	second=head;
	while(first->next!=NULL)
	{
		first=first->next;
		second=second->next;
		if(first->next!=NULL)
			first=first->next;
		if(first==second)
		{
			RemoveLoop(head,second);
			break;
		}

	}
	
}

void push( Node **head,int data)
{
	
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	if(*head==NULL)
	{
		*head=newNode;
		newNode->next=NULL;

	}
	else
	{
		newNode->next=(*head);
		*head=newNode;
	}

}
void printLL(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
		
}
int main()
{
	Node *head;
	push(&head,5);
	
	push(&head,6);
	push(&head,15);
	push(&head,16);
	push(&head,35);
	push(&head,36);

	head->next->next->next->next->next->next=head->next->next->next;
	detectAndRemoveLoop(head);
	printLL(head);
	return 0;

}