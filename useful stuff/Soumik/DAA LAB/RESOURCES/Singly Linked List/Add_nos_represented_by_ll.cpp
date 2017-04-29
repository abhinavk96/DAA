// Add_nos_represented_by_ll.cpp By Soumik Chatterjee
// Add two nos which are represented by linked lists.
// Example to add 365 and 248
// List 1: 5 -> 6 -> 3  represents   365
// List 2: 8 -> 4 -> 2  represents   248
//                                ---------
// Output: 3 -> 1 -> 6  represents   613
// ---------------------------------------
// Copyright 2016 @ Soumik Chatterjee

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

node* create_linked_list(int num)
{
    node* head;
    head = NULL;
    int rem;
    while (num != 0)
    {
        rem = num % 10;
        head = insert(head , rem);
        num = num / 10;
    }
    return head;
}

void display(node *head)
{
    while(head != NULL)
    {
        cout << head->data <<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;

}

node* add_lists(node* head1, node* head2)
{
    node* head;
    node* temp;
    node* prev;
    head = prev = NULL;
    int carry = 0, sum;
    while ( head1 || head2)
    {
        sum = carry + (head1? head1->data : 0) + (head2? head2->data : 0);
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        cout<<sum<<endl;
        temp = getnode(sum);
        if(head == NULL)
            head = temp;
        else
            prev->next = temp;
        prev = temp;

        if(head1)
            head1 = head1->next;
        if(head2)
            head2 = head2->next;
    }

    if(carry>0)
        temp->next = getnode(carry);
    return head;
}
int main()
{
    int t;
    cin>>t;
    while (t -- )
    {
        int x,y;
        cin>>x;
        cin>>y;
        node *head1, *head2;
        head1 = head2 = NULL;
        head1 = create_linked_list(x);
        head2 = create_linked_list(y);
//        cout<<endl<<endl;
//        display(head1);
//        cout<<endl<<endl;
//        display(head2);
//        cout<<endl;

        node *head = NULL;
        head = add_lists( head1, head2);
        display(head);

    }
}
