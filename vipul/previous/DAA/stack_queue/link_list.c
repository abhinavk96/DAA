#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *link;
};
void traversing(struct node* start){
	struct node*p;
	p=start;
        while(p!=NULL){ 
       		printf("%d->",p->data);
        	p=p->link; 
        }
        //printf("NULL\n");
  //      return start;

	
}

struct node* add_1st_element(struct node*start,int item)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->link=NULL;
	p->data=item;
	start=p;
	p=start;
	return start;
}

struct node* add_at_end(struct node* start,int item)
{
	struct node*p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	p=start;
	while(p->link!=NULL){
	p=p->link;
	}
	temp->link=NULL;
	p->link=temp;
	temp->data=item;
	return start;
}

struct node* insert_at_k(struct node* start,int item,int k){
	struct node*p,*temp;
	int pos=1;
	temp=(struct node*)malloc(sizeof(struct node));
	p=start;
	while(p!=NULL){
		if(pos==k-1){
			break;
		}
		p=p->link;
		pos++;
	}
	temp->link=p->link;
	temp->data=item;
	p->link=temp;
        return start;
}

struct node* insert_at_k1(struct node* start,int item,int k){
        struct node*p,*temp;
        int pos=1;
        temp=(struct node*)malloc(sizeof(struct node));
        p=start;
        while(p->link!=NULL){
                if(pos==k){
                        break;
                }
                p=p->link;
                pos++;
        }
        temp->link=p->link;
        temp->data=item;
        p->link=temp;
        return start;
}

struct node* insert_at_1k(struct node* start,int item,int k){
        struct node*p,*temp;
        int pos=1;
        temp=(struct node*)malloc(sizeof(struct node));
        p=start->link;
        while(p!=NULL){
                if(pos==k-2){
                        break;
                }
                p=p->link;
                pos++;
        }
        temp->link=p->link;
        temp->data=item;
        p->link=temp;
        return start;
}

struct node* delete_kth(struct node* start,int k){
        struct node*p,*temp;
        int pos=1;
        p=start;
        while(p!=NULL){
                if(pos==k){
                        break;
                }
                p=p->link;
                pos++;
        }
        temp=p->link->link;
	p->link=temp;
        return start;
}

struct node* insert_at_begining(struct node *start,int item){
	struct node*p,*temp;
        int pos=1;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->link=start;
	temp->data=item;
	start=temp;
        return start;
}

struct node* insert_aft_val(struct node* start,int item,int val){
        struct node*p,*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        p=start->link;
	temp->data=item;
        while(p!=NULL){
                if(p->data==val){
                        break;
                }
                p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
        return start;
}

struct node* insert_befo_val(struct node* start,int item,int val){
        struct node*p,*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        p=start->link;
        temp->data=item;
        while(p->link!=NULL){
                if(p->link->data==val){
                        break;
                }
                p=p->link;
             //   pos++;
        }
        temp->link=p->link;
        p->link=temp;
        return start;
}
struct node* reverse(struct node *start)
{
	struct node *prev,*p,*next;
	prev=NULL;
	p=start;
	while(p!=NULL)
	{
		next=p->link;
		p->link=prev;
		prev=p;
		p=next;
	}
	start=prev;
	return start;
}

int main(){
	int choice,cnt,item,k,val;
	struct node *start=NULL;
	read:
	printf("enter your choice\n");
	printf("0--insert at the begining.\n");
	printf("1--insert first element in an empty list.\n");
	printf("2--insert at the end.\n");
	printf("3--insert at the kth position\n");
	printf("4--insert at the (k+1)th position\n");
	printf("5--insert at the (k-1)th position\n");
	printf("6--deleting kth elenment\n");
	printf("7--insert after given value\n");
	printf("8--insert before given value\n");
    printf("9--reversing the list\n");
	
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter the data item\n");
			scanf("%d",&item);
			start=add_1st_element(start,item);
			traversing(start);
			break;
		case 2:
			printf("Enter the data item\n");
                        scanf("%d",&item);
                        start=add_at_end(start,item);
			traversing(start);
                        break;
		case 3:
			printf("enter the value of k and data item \n");
			scanf("%d%d",&k,&item);
			start=insert_at_k(start,item,k);
			traversing(start);

                        break;
		case 4:
			printf("enter the value of k and data item \n");
                        scanf("%d%d",&k,&item);
                        start=insert_at_k1(start,item,k);
			traversing(start);
                        break;
		case 5:
			printf("enter the value of k and data item \n");
                        scanf("%d%d",&k,&item);
                        start=insert_at_1k(start,item,k);
			traversing(start);
                        break;
		case 6:
			printf("enter the value of kth position to be deleted \n");
                        scanf("%d",&k);
                        start=delete_kth(start,k);
			traversing(start);
                        break;
		 case 0:
                        printf("enter the value of data item\n");
                        scanf("%d",&item);
                        start=insert_at_begining(start,item);
			traversing(start);
                        break;
		 case 7:
                        printf("enter the data item and val \n");
                        scanf("%d%d",&item,&val);
                        start=insert_aft_val(start,item,val);
			traversing(start);
                        break;
		case 8:
                        printf("enter the data item and val \n");
                        scanf("%d%d",&item,&val);
                        start=insert_befo_val(start,item,val);
			traversing(start);
                        break; 
        case 9:
        	       start=reverse(start);
        	       traversing(start);
        	       break;
	}
	
	printf("do u want to continue press--> 1");
	scanf("%d",&cnt);
	if(cnt==1)
		goto read;
	else
		return 0;


}
