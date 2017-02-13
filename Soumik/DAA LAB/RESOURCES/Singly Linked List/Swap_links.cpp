// By Soumik Chatterjee
// To swap two nodes in a linked list by changing only the links (indices are taken as input)
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
        node* temp;
        temp=getnode(val);
        temp->next=head;
        head=temp;

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

node* swap(node *head, int i, int j)
{
   /*                     *
   *                      *
   * Some text goes here  *
   *                      *
   *                      *
   *                      */

   if(i==j || (i<=0 || j<=0))  //If the indices are same or negative index entered
    return head;
   else
   {
       int loop_i=1,loop_j=1;
       node *curi,*previ,*curj,*prevj;
       curi=head;previ=NULL;
       while(curi && loop_i < i)  //reaching the fist node
       {
           previ = curi;
           curi = curi->next;
           loop_i++;
       }
       curj=head; prevj=NULL;
       while(curj && loop_j < j)  //reaching the second node
       {
           prevj = curj;
           curj = curj->next;
           loop_j++;
       }
       if(curi==NULL || curj==NULL)  //If either of the indices are out of bounds
        return head;

        //interchange the links as required

        if(previ != NULL)
            previ->next = curj;
        else
            head=curj;

        if(prevj != NULL)
            prevj->next=curi;
        else
            head=curi;

        //Now swap the next nodes
        node* temp= curj->next;
        curj->next=curi->next;
        curi->next=temp;


   }
   return head;
}


int main()
{
    node* head=NULL;
    cout<<"INSERTING INTO THE LINKED LIST \n\n(Elements will be added to the beginning of the list)\n\n";
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


    cout<<"Before Swapping"<<endl;
    display(head);

    int i,j;
    cout<<"Enter the two indices to swap:(1 indexing)\n";
    cin>>i>>j;
    head=swap(head,i,j);

    cout<<"After Swapping"<<endl;
    display(head);

    return 0;
}
