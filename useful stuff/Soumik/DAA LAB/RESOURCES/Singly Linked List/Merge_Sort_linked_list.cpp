// Merge_Sort_linked_list.cpp By Soumik Chatterjee
// Implement Merge Sort for Linked Lists.
// Copyright 2016 @ Soumik Chatterjee.

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
    //cout<<"The linked list is :\n\n";
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
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

void Split( node* source, node** front1, node** front2)
{
    node* slow;
    node* fast;
    if( source == NULL || source->next == NULL)
    {
        *front1 = source;
        *front2 = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if( fast )
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *front1 = source;
        *front2 = slow->next;
        slow->next = NULL;
    }
}

void merge_sort(node** head_ref)
{
    node *head = *head_ref;
    node *a, *b;
    a = b = NULL;

    if( head == NULL || head->next == NULL)
        return;
    Split( head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);
    *head_ref = merge(a,b);
}

int main()
{
    // Take input of test cases.
    // Then input no of nos to sort and then the no.s.
    // Print the sorted nos in separate lines.
    int t;
    cin>>t;
    while( t-- )
    {
        int n;
        cin>>n;
        node* head = NULL;
        while (n--)
        {
            int x;
            cin>>x;
            head = insert(head, x);
        }
        merge_sort( &head );
        display(head);
        //del(head);
    }
}
