#include<stdio.h>
#include<limits.h>
#define V 9
int min_dist(int dist[V],int inclu[V]){
    int i,mini,min_index;
    mini = INT_MAX;
    for(i = 0 ;i<V;i++){
        if(inclu[i] == 0 && dist[i] <= mini){
            mini = dist[i];
            min_index = i;

        }
    }
    return min_index;

}
int dijkstra(int graph[V][V] , int src,int parent[],int dest){
    parent[src] = INT_MAX;

    int dist[V];
    int inclu[V];
    int i,j;
    for(i=0;i<V;i++){
        dist[i] = INT_MAX;
        inclu[i] = 0;
        if(i!=src)
            parent[i] = -1;
    }
    dist[src] = 0;

    for(i = 0;i< V;i++){

        int u = min_dist(dist,inclu);
        inclu[u] = 1;
        for(j =0 ;j<V;j++){
            if( inclu[j] == 0 && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]){
                dist[j] = graph[u][j] + dist[u];
                parent[j] = u;
            }


        }


    }


    return dist[dest];
}
 int print_path(int src,int dest,int parent[],int path[]){
         int i = dest;
         int j=0;
         //printf("A\n");
         while(parent[i] != INT_MAX){
            //printf("B\n");
            printf("%d <- ",i);
            path[j++] = i;
            i = parent[i];
            if(i == -1){
                printf("no path\n");
                return INT_MAX;
            }




         }
          //printf("C\n");


         //printf("%d <-",i);
         //path[j++] = i;
         printf("%d\n",src);
         path[j++] = src;


         return j;
 }
 void change_graph(int graph1[V][V],int graph[V][V],int x,int y){
    int i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
                graph1[i][j] = graph[i][j];
            if( i == x && j == y )
                graph1[i][j] = 0;
            else if( i == y && j == x )
                graph1[i][j] = 0;
        }
    }

 }
 copy_arr(int path1[V],int path2[V]){
    int i;
    for(i=0;i<V;i++){
        path2[i] = path1[i];
    }


 }
 int second_shortest(int graph[V][V],int src,int dest,int path[],int length,int path2[],int* length2){
        int i;
        int graph1[V][V];
        int min_cost = INT_MAX;
        int parent[V];
        int path1[V];
        for(i=0;i<length-1;i++){
            int x = path[i];
            int y = path[i+1];
            //printf("x = %d y = %d\n",x,y);
            change_graph(graph1,graph,x,y);
            int mini = dijkstra(graph1,src,parent,dest);
            int length = print_path(src,dest,parent,path1);

            if (mini<min_cost){
                min_cost = mini;
                copy_arr(path1,path2);
                *length2 = length;

            }
        }
        return min_cost;



 }
  void change_graph2(int graph1[V][V],int graph[V][V],int p,int q,int r,int s){
    int i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
                graph1[i][j] = graph[i][j];
            if( i == p && j == q )
                graph1[i][j] = 0;
            else if( i == q && j == p )
                graph1[i][j] = 0;
            else if( i == r && j == s )
                graph1[i][j] = 0;
            else if( i == s && j == r )
                graph1[i][j] = 0;
        }
    }

 }
 int third_shortest(int graph[V][V],int src,int dest,int path1[],int length1,int path2[],int length2){
        int i,j;
        int graph1[V][V];
        int min_cost = INT_MAX;
        int parent3[V];
        int path3[V];
        int p,q,r,s;
        for(i=0;i<length1-1;i++){
            for(j=0;j<length2-1;j++){
                p = path1[i];
                q = path1[i+1];
                r = path2[j];
                s = path2[j+1];
                printf("p = %d q = %d r = %d s = %d \n",p,q,r,s);
                change_graph2(graph1,graph,p,q,r,s);

                int mini = dijkstra(graph1,src,parent3,dest);

                int length = print_path(src,dest,parent3,path3);
                printf("%d\n",mini);
            if (mini<min_cost){
                min_cost = mini;
                //copy_arr(path1,path2);
                //*length2 = length;

                }
            }
        }
        return min_cost;

 }
int main(){

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int parent[V];


    int dest;
    scanf("%d",&dest);
    int k = dijkstra(graph, 0,parent,dest);
    printf("shortest %d\n",k);
    int path[V],path2[V];
    int length = print_path(0,dest,parent,path);
    printf("%d\n",length);
    int i;
    int length2;
    printf("second shortest %d\n",second_shortest(graph,0,dest,path,length,path2,&length2));
    printf("third shortest %d\n",third_shortest(graph,0,dest,path,length,path2,length2));

}


