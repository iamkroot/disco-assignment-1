#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node* next;
}node;
int n, m, count=0;

void append(node** head, int v){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    node* t = *head;
    *head = newnode;
    newnode->next=t;
}

int checkmember(node** head, int v){
    node* cursor = *head;
    while(cursor){
        if(v==cursor->data)
            return 1;
        cursor = cursor->next;
    }
    return 0;
}

int alltoposorts(node* adjlst[], int visited[], int indegree[]){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(indegree[i]==0&&!visited[i]){
            node* start = adjlst[i];
            while(start){
                indegree[start->data]--;
                start=start->next;
            }
            visited[i]=1;
            alltoposorts(adjlst, visited, indegree);
            visited[i]=0;
            start = adjlst[i];
            while(start){
                indegree[start->data]++;
                start=start->next;
            }
            flag=1;
        }
    }
    if(!flag){
        count++;
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d %d\n", &n, &m);
    node* adjlst[n];
    int indegree[n], visited[n];
    for(int i=0; i<n; i++){
        indegree[i] = visited[i] = 0;
        adjlst[i] = NULL;
    }
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d\n", &a, &b);
        if(checkmember(&(adjlst[b]), a)){
            printf("-1\n");
            return 0;
        }
        append(&(adjlst[a]), b);
        indegree[b]++;
    }
    alltoposorts(adjlst, visited, indegree);
    printf("%d\n", count);
    return 0;
}
