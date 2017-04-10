# include <stdio.h>
# include <stdlib.h>

struct node {

  struct node *left,*right;
  char data;
};

void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *);
void constructHuffman(char *, int **, int , struct node **);
void buildMinHeap(char *, int **, int );
void collectFrequency(FILE *,int **,int );
int countDistinct(FILE *);
void pp(struct node *ptr,int pi,int ph[][260],int path[])
{
    if(ptr==NULL)
    {
      return;
    }
    if(ptr->left!=NULL)
    {
      path[pi]=0;
      pp(ptr->left,pi+1,ph,path);
    }
    if(ptr->right!=NULL)
    {
      path[pi]=1;
      pp(ptr->right,pi+1,ph,path);
    }
    if(ptr->right==NULL&&ptr->left==NULL)
    {
      int i;
      int fi=ptr->data;
      printf("%d  ",ptr->data);
      for(i=0;i<pi;i++)
      {
        ph[fi][i]=path[i];
        printf("%d ",path[i]);
      }
      ph[fi][i]=-1;
      printf("\n");
    }
}
int main()
{
  FILE *fip,*fop,*fdec;
  int **frequency,n,i;
  char *heap;
  struct node *huffman;
  fip = fopen("input","r");
 // fop = fopen("encode","w");
  n = countDistinct(fip);
  printf("%d\n",n);
  frequency = (int **)malloc(n*sizeof(int *));
  heap = (char *)malloc(n*sizeof(char));
  for(i=0;i<n;i++)
    frequency[i]=(int *)malloc(2*sizeof(int));
  rewind(fip);
  collectFrequency(fip,frequency,n);
  buildMinHeap(heap,frequency,n);
  constructHuffman(heap,frequency,n,&huffman);
  rewind(fip);
  fop = fopen("encode","w");
  encode(fip,fop,huffman);
  fclose(fop);
  fop = fopen("encode","r");
  fdec = fopen("decode","w");
  decode(fop,fdec,huffman);
  fclose(fip);
  fclose(fop);
  fclose(fdec);
  //fclose(fip);
  return 0;
}

int countDistinct(FILE *fp)
{
  int n=0;
  /* Count the total number of distinct characters in the file */
  char c;
  int *arr=(int *)calloc(300,sizeof(int));
  while((c=fgetc(fp))!=EOF)
  {
      arr[c]++;
  }
  int i;
  for(i=0;i<257;i++)
  {
    if(arr[i])
    {
      n++;
    }
  }
  return n;
}

void collectFrequency(FILE *fp,int **frequency,int n)
{
  /*
    You need to figure out how many times each character appears in the file. For this we will use hash table.

    create a proper hash function by looking at the file and use the frequency array as a hash table.
    For collision and it's resolution, we allow two cells at every position of the hash table.
    The first cell will contain the ascii code of the character and the second cell will contain the frequency of that character.
  */
    int i;
    char c;
    int *arr=(int *)calloc(300,sizeof(int));
    while((c=fgetc(fp))!=EOF)
    {
        arr[c]++;
    }
    int ct=0;
    for(i=0;i<257;i++)
    {
      if(arr[i])
      {
        frequency[ct][0]=i;
        frequency[ct][1]=arr[i];
        printf("%d %d %d\n",ct,frequency[ct][0],frequency[ct][1]);
        ct++;
      }
    }
}
void min_heapify(char *heap,int id,int hs,int **frequency,int n)
{
  int left,right,mn,fl,fr,fcid,x;
  left=2*id+1;
  right=2*id+2;
  int i;
  for(i=0;i<n;i++)
  {
    if(frequency[i][0]==heap[id])
    {
      fcid=frequency[i][1];
    }
    if(left<hs&&heap[left]==frequency[i][0])
    {
      fl=frequency[i][1];
    }
    if(right<hs&&heap[right]==frequency[i][0])
    {
      fr=frequency[i][1];
    }
  }
  if(left<hs&&fl<fcid)
  {
     mn=left;
     x=fl;
  }
  else
  {
    mn=id;
    x=fcid;
  }
  if(right<hs&&fr<x)
  {
     mn=right;
  }
  if(mn!=id)
  {
    char tmp=heap[mn];
    heap[mn]=heap[id];
    heap[id]=tmp;
    min_heapify(heap,mn,hs,frequency,n);
  }
}
void buildMinHeap(char *heap, int **frequency, int n)
{
  /* 
     This is exactly similar to the buil_max_heap that you have created in previous lab assignment with the following difference:
     In heap you store the characters, but unlike previous implementation the comaprison between different characters are not by their ASCII but by their frequency.
     You should use the same hash function to look for the frequency of the specific character
  */
     int i=0;
     printf("%d\n",n);
     for(i=0;i<n;i++)
     {
      //printf("%d ",i);
         heap[i]=frequency[i][0];
         //printf("%d %d\n",i,frequency[i][1]);
     }
     for(i=n/2-1;i>=0;i--)
     {
      //printf("%d\n",i);
      min_heapify(heap,i,n,frequency,n);
     }
}
int fck(char id1,char id2,int **frequency,int n)
{
  int i,f1,f2;
  for(i=0;i<n;i++)
  {
    if(frequency[i][0]==id1)
    {
       f1=frequency[i][1];
    }
    if(frequency[i][0]==id2)
    {
      f2=frequency[i][1];
    }
  }
  if(f1<f2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void insert(char *heap,char vl,int *hs,int **frequency,int n)
{
  int id,fp,fcid;
  id=*hs;
  heap[*hs]=vl;
  (*hs)++;
  while(id!=0&&fck(heap[id],heap[(id-1)/2],frequency,n))
  {
    char tmp=heap[id];
    heap[id]=heap[(id-1)/2];
    heap[(id-1)/2]=tmp;
    id=(id-1)/2;
  }
}
char ex_min(char *heap,int *hs,int **frequency,int n)
{
  int i;
  char mn=heap[0];
  (*hs)--;
  heap[0]=heap[*hs];
  min_heapify(heap,0,*hs,frequency,n);
  return mn;
}
void constructHuffman(char *heap, int **frequency, int n, struct node **huffman)
{
  /*
    Construct the huffman tree from the given heap.
    Note that you may need to change the heap while contruction (deletion, insertion). Please import the appropriate function written in previous classes.
    Also, note that, you may need to store frequency of new elements that are not there in the file and thus in the array fequency.
    For this you may change the content of the array frequency correctly and figure out a way to store the frequency of tree nodes in the array.
    Otherwise you may use your own data structure
  */
    int cs=0,i,hs=n;
    char mn1,mn2;
    int f1,f2,j;
    struct node *tmp;
    struct node *temp[260];
    //int flag[260];
    for(i=0;i<260;i++)
    {
      //flag[i]=0;
      temp[i]=NULL;
    }    
    for(i=0;i<n;i++)
    {
      tmp=(struct node *)malloc(sizeof(struct node));
      tmp->left=NULL;
      tmp->right=NULL;
      tmp->data=heap[i];
      temp[heap[i]]=tmp;
      //flag[heap[i]]=0;
    }
    int x;
   for(i=0;i<n-1;i++)
    {
        mn1=ex_min(heap,&hs,frequency,n);
        mn2=ex_min(heap,&hs,frequency,n);
        printf("%d %d\n",mn1,mn2);
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->left=temp[mn1];
        tmp->right=temp[mn2];
        for(j=0;j<n;j++)
        {
          if(frequency[j][0]==mn1)
          {
            f1=frequency[j][1];
            x=j;
          }
          if(frequency[j][0]==mn2)
          {
             f2=frequency[j][1];
          }
        }
        frequency[x][1]=f1+f2;
        tmp->data=mn1;
        temp[mn1]=tmp;
        //printf("\n");
        insert(heap,tmp->data,&hs,frequency,n);
    }
    *huffman=temp[ex_min(heap,&hs,frequency,n)];
}
void encode(FILE *fip,FILE *fop,struct node *huffman)
{
  /*
    Encode fip using huffman code and write properly to fop.
  */
          int ph[260][260];
      int path[260];
      int fi=0;
    pp(huffman,0,ph,path);
    char c;
    int i;
    while((c=fgetc(fip))!=EOF)
    {
        for(i=0;ph[c][i]!=-1;i++)
        {
          if(ph[c][i]==1)
          {
            fprintf(fop,"%c",'1');
          }
          else
          {
            fprintf(fop,"%c",'0');
          }
        }
    }

}

void decode(FILE *fip,FILE *fop,struct node *huffman)
{
  /*
    Decode fip using huffman code and write properly to fop.
  */
          int ph[260][260];
      int path[260];
      int fi=0;
    pp(huffman,0,ph,path);
      int i;
   char c;
   struct node *tmp=huffman;
   while((c=fgetc(fip))!=EOF)
   {
      if(tmp->right==NULL&&tmp->left==NULL)
      {
        fprintf(fop,"%c",tmp->data);
        tmp=huffman;
      }
      if(c=='1')
      {
         tmp=tmp->right;
      }
      else
      {
         tmp=tmp->left;
      }
   }
}
