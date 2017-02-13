
// By Soumik Chatterjee
// To merge two sorted linked lists
// This is an iterative solution which has a space complexity of 0(1) due to absence of recursion and extra nodes. Useful at production level.
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
    //If both lists are empty
    if(!head1 && !head2)
    {
        cout<<"List is empty "<<endl;
        return 0;
    }
    // If either of the list is empty
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    else
    {
        node* head; //Act as the head of the final sorted merged list
        node* previous; //Will traverse both the lists to merge.
        head = previous = NULL;

        while ( head1 && head2)
        {
            if(!head)
            {
                if( head1->data <= head2->data)
                {
                    head = head1;
                    previous = head1;
                    head1 = head1->next;
                }
                else
                {
                    head = head2;
                    previous = head2;
                    head2 = head2->next;
                }
            }
            else
            {
                if( head1->data <= head2->data)
                {
                    if(previous->next != head1) //Connection is not already present. So connection is made.
                        previous->next = head1;
                    head1 = head1 -> next;

                }
                else
                {
                    if(previous->next != head2)  //Connection is not already present. So connection is made.
                        previous->next = head2;
                    head2 = head2->next;
                }
                previous = previous->next;
            }

        }
        if(!head1)
            previous->next = head2;
        if(!head2)
            previous->next = head1;

        return head;
    }
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
    cout<<"\n\nAfter Merging:\n\n";
    display(head3);
}
