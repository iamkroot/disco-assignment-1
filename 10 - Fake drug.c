#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void prepend(node** head, int v){
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

int checkmember(node* start, int v){
    while(start){
        if(v==start->data)
            return 1;
        start = start->next;
    }
    return 0;
}

// int remove(node** head, int v){
//     node* cursor = *head;
//     if(!cursor||(cursor->next==NULL&&cursor->data!=v)){
//         return 0;
//     }
//     if(cursor->data==v){
//         *head=cursor->next;
//         free(cursor);
//         return 1;
//     }
//     node* prev=cursor;
//     cursor=cursor->next;
//     while(cursor){
//         if(cursor->data==v){
//             prev->next=cursor->next;
//             free(cursor);
//             return 1;
//         }
//         prev=cursor;
//         cursor=cursor->next;
//     }
//     return 0;
// }
// node* less = NULL;
// node* more = NULL;
// node* same = NULL;
// node* adjlst[10000];
#define MAXNUM=10000;
int less[MAXNUM], same[MAXNUM], more[MAXNUM], roots[MAXNUM];

int main(int argc, char const *argv[]) {
    int n, m=0;
    scanf("%d\n", &n);
    for(int i=0; i<MAXNUM; i++){
        roots[i]=i;
        less[i]=same[i]=more[i]=0;
    }
    while(n--){
        int k;
        scanf("%d\n", &k);
        int a[k], b[k];
        for(int i=0; i<k; i++){
            scanf("%d ", &a[i]);
            if(a[i]>m)
                m=a[i];
        }
        for(int i=0; i<k; i++){
            scanf("%d ", &b[i]);
            if(b[i]>m)
                m=b[i];
        }
        char comparator;
        scanf("%c\n", &comparator);
        if(comparator=='='){
            for(int i=0; i<k; i++){
                same[a[i]]=same[b[i]]=1;
                less[a[i]]=less[b[i]]=more[a[i]]=more[b[i]]=0;
            }
        }
        else if(comparator=='<'){
            for(int i=0; i<k; i++){
                if(!same[a[i]])
                    less[a[i]]=1;
                if(!same[b[i]])
                    more[b[i]]=1;
                // if((less[a[i]]&&more[a[i]])||(less[b[i]]&&more[b[i]])){
                //     printf("-1f\n");
                //     return 0;
                // }
            }
        }
        else if(comparator=='>'){
            for(int i=0; i<k; i++){
                if(!same[a[i]])
                    more[a[i]]=1;
                if(!same[b[i]])
                    less[b[i]]=1;
                printf("%d %d\n", a[i], more[a[i]]);
                // if((less[a[i]]&&more[a[i]])||(less[b[i]]&&more[b[i]])){
                //     printf("-1k\n");
                //     return 0;
                // } 
            }
        }
    }
    for(int i=1; i<m+1; i++)
        printf("%d ", less[i]);
    printf("\n");
    for(int i=1; i<m+1; i++)
        printf("%d ", same[i]);
    printf("\n");
    for(int i=1; i<m+1; i++)
        printf("%d ", more[i]);
    printf("\n");
    int ans, n_less=0, n_more=0;
    for(int i=1; i<m+1; i++){
        if(less[i]+same[i]+more[i]>1){
            printf("-1a\n");
            return 0;
        }
        if(less[i]){
            ans=i;
            n_less++;
        }
        else if(more[i]){
            ans=i;
            n_more++;
        }
    }
    if(n_less+n_more>1||n_less+n_more<1){
        printf("-1ss\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}
