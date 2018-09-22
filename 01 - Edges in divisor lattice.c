#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

void append_to_list(node** startp, int data){
    // append new item to linked list
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    if(*startp == NULL){
        *startp=new_node;
        return;
    }
    node* cursor = *startp;
    while(cursor->next!= NULL)
        cursor=cursor->next;
    cursor->next=new_node;
}

node* get_prime_factors(int n){
    // get all prime factors of an integer
    node* prime_factors = NULL;
    short is_prime[n+1];
    for(int i=0;i<n+1;i++)
        is_prime[i] = 1;
    for(int p=2;p<=n;p++){
        if(is_prime[p]){
            if(n%p==0)
                append_to_list(&prime_factors, p);
            for(int i=p*2;i<=n;i+=p){
                is_prime[i] = 0;
            }
        }
    }
    return prime_factors;
}

node* factors = NULL;

int check_member(node* start, int data){
    node* cursor = start;
    while(cursor!=NULL){
        if(cursor->data==data)
            return 1;
        cursor=cursor->next;
    }
    return 0;
}

int get_edges(int n){
    if(n==1)
        return 0;
    int edges = 0;
    node* pfs = get_prime_factors(n);
    node* cursor = pfs;
    while(cursor!=NULL){
        int factor = n/(cursor->data);
        edges += 1;
        if (factor != 1 && !check_member(factors, factor)){
            append_to_list(&factors, factor);
            edges += get_edges(factor);
        }
        cursor = cursor->next;
    }
    return edges;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int e = get_edges(n);
    printf("%d", e);
    printf("\n");
    return 0;
}
