// By Soumik Chatterjee
// To reverse a linked list
// ALl rights to reserved to Soumik Chatterjee

#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

node* getnode(int val)
{
	node *newnode;
	newnode=new node;
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}

node* insert(node* head, int val)
{
	if(head==NULL)
		head=getnode(val);
	else
    {
        node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        //node* temp;
        temp->next=getnode(val);


    }
    return head;
}
void display(node* head)
{
    cout<<"The linked list is :\n\n";
    while(head != NULL)
    {
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL\n";
}

node* reverse(node *head)
{
  node *prev,*cur,*next;
  prev=NULL;
  cur=head;
  while(cur!=NULL)
  {
      next=cur->next;
      cur->next=prev;
      prev=cur;
      cur=next;
  }
  head=prev;
  return head;
}
int main()
{
    node* head=NULL;
    cout<<"INSERTING INTO THE LINKED LIST \n\n(Elements will be added to the end of the list)\n\n";
    cout<<"Enter no of nodes to insert:";
    int n;
    cin>>n;
    for(int i = 0; i <n ;i++)
    {
        int x;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>x;
        head=insert(head, x);
    }
    cout<<endl;


    cout<<"Before reversing:\n"<<endl;
    display(head);
    cout<<"\n\nAfter reversing:\n"<<endl;
    head=reverse(head);
    display(head);
    return 0;
}
