
// By Soumik Chatterjee
// To merge two sorted linked lists
// This is a recursive solution which has inherent space space complexity of O(m+n) due to recursive stack. Hence not useful at production level.
// ALl rights to reserved to Soumik Chatterjee.

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

node* merge(node* head1, node* head2)
{
    node* result;
    if( head1 == NULL)
        return head2;
    if( head2 == NULL)
        return head1;
    if( head1->data <= head2->data)
    {
        result = head1;
        result->next = merge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;

}


int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    cout<<"INSERTING INTO THE LINKED LIST \n\n( Elements will be added to the end of the list )\n\n";
    cout<<"Enter no of nodes to insert in LINKED LIST 1:";
    int n1;
    cin>>n1;
    cout<<"\nEnter the elements is ascending order\n\n";
    for(int i = 0; i < n1 ;i++)
    {
        int x;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>x;
        head1 = insert(head1, x);
    }

    cout<<"\n\nEnter no of nodes to insert in LINKED LIST 2:";
    int n2;
    cin>>n2;
    cout<<"\nEnter the elements is ascending order\n\n";
    for(int i = 0; i < n2 ;i++)
    {
        int x;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>x;
        head2 = insert(head2, x);
    }

    node* head3;
    head3=merge(head1, head2);
    cout<<"The merged linked list is:\n\n";
    display(head3);
}
