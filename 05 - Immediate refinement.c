#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
}node;

#define STARTMARKER -999
#define PARTITIONMARKER -1000

node* create_node(int d){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = d;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void append_to_list(node** head, int d){
    node* new_node = create_node(d);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    node* cursor = *head;
    while(cursor->next){
        cursor = cursor->next;
    }
    cursor->next = new_node;
    new_node->prev = cursor;
}

void display(node* start){
    while(start!=NULL){
        if(start->data==STARTMARKER)
            printf("{{");
        else if (start->data==PARTITIONMARKER)
            printf("\b\b}{");
        else
            printf("%d, ", start->data);
        start=start->next;
    }
    printf("\b}\n");
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d\n", &n);
    node* start = NULL;
    append_to_list(&start, STARTMARKER);
    for(int i=0; i<n; i++){
        int k;
        scanf("%d\n", &k);
        for(int j=0; j<k; j++){
            int a;
            scanf("%d ", &a);
            append_to_list(&start, a);
        }
        append_to_list(&start, PARTITIONMARKER);
    }
    printf("Original: ");display(start);
    printf("Possible refinements:\n");
    node* cursor = start;
    while(cursor){
        node* new_cur = cursor->next;
        while(new_cur&&new_cur->data!=PARTITIONMARKER){
            node* prev = new_cur->prev;
            node* next = new_cur->next;
            if(next&&prev&&(prev->data==STARTMARKER||prev->data==PARTITIONMARKER)&&(next->data==STARTMARKER||next->data==PARTITIONMARKER)){
                new_cur = new_cur->next;
                break;
            }
            prev->next = next;
            node* temp = cursor->next;
            cursor->next=new_cur;
            node* empty = create_node(PARTITIONMARKER);
            new_cur->next = empty;
            empty->next=temp;
            if(prev&&prev->prev&&(prev->prev->data==STARTMARKER||prev->prev->data==PARTITIONMARKER)&&next&&(next->data==STARTMARKER||next->data==PARTITIONMARKER)){
            }
            else{
                display(start);
            }
            cursor->next = temp;
            prev->next=new_cur;
            new_cur->next=next;
            new_cur=new_cur->next;

        }
        cursor=new_cur;
    }
    return 0;
}