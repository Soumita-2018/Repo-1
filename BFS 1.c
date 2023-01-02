#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX],front=-1,rear=-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main(){
create_graph();
BF_Traversal();
}
void BF_Traversal(){
int v;
state[v]=initial;
for(v=0;v<n;v++){
    printf("Enter the start vertex of BFS: ");
    scanf("%d",&v);
    BFS(v);
}
}

void BFS(int v){
int i;
insert_queue(v);
state[v]=waiting;
while(!isEmpty_queue){
    v=delete_queue;
    printf("%d",v);
    state[v]=visited;
}
for(i=0;i<n;i++){
    while(adj[v][i]==1 && state[i]==initial){
        insert_queue(i);
        state[i]=waiting;
    }
}
printf("\n");
}
 void insert_queue(int vertex){
 if(rear == MAX-1){
    printf("OVERFLOW");
    return;
 }
 else{
    if(front == -1){
        front =0;
        rear = rear +1;
        queue[rear]=vertex;
    }
 }
 }
 int isEmpty_queue(){
 if(front == -1 || front>rear){
    return 1;
 }
 return 0;
 }
 int delete_queue(){
int delete_item;
 if(front == -1 || front>rear){
    printf("UNDERFLOW");
    return -1;
 }
 else{
    delete_item = queue[front];
    front = front +1;
    return delete_item;
 }
 }
void create_graph(){
 int origin,destin,count,n,max_edge;
 printf("Enter the number of vertices: ");
 scanf("%d",&count);
 max_edge = n*(n-1);
 for(count = 0;count<max_edge;count++){
    printf("Enter %d vertices(-1 -1 to quit)",count);
    scanf("%d%d",&origin,&destin);

   if(origin == -1 || destin == -1)
        break;
   if(origin>=n && destin >= n || origin<0 && destin<0){
    printf("Invalid Choice");
    count--;
   }
 else{
    adj[origin][destin]=1;

 }
 }
 }
