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

int check_member(node* start, int data){
    node* cursor = start;
    while(cursor!=NULL){
        if(cursor->data==data)
            return 1;
        cursor=cursor->next;
    }
    return 0;
}

node* get_prime_factors(int n){
    // get all prime factors of an integer
    node* prime_factors = NULL;
    for(int i=2; i<=n; i++){
        if(n%i==0)
            append_to_list(&prime_factors, i);
        while(n%i==0)
            n/=i;
    }
    return prime_factors;
}

node* factors = NULL;

int get_edges(int n){
    if(n==1)
        return 0;
    int edges = 0;
    node* pfs = get_prime_factors(n);
    node* cursor = pfs;
    while(cursor){
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
    printf("%d\n", get_edges(n));
    return 0;
}
