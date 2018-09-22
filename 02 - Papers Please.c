#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

int comp_matrix[26][26], inputted[26];

int main(int argc, char const *argv[]) {
    for(int i=0; i<26; i++){
        inputted[i]=0;
        for(int j=0; j<26; j++){
            comp_matrix[i][j]=0;
        }
    }
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<n;i++){
        char c1, c2;
        scanf("%c %c\n", &c1, &c2);
        int ind1=c1-'a', ind2=c2-'a';
        if(comp_matrix[ind2][ind1]){
            printf("-1");
            return 0;
        }
        comp_matrix[ind1][ind2] = 1;
        inputted[ind1]=1;
        inputted[ind2]=1;
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            printf("%d ", comp_matrix[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(i!=j &&comp_matrix[i][j]){
                if(comp_matrix[j][i]){
                    printf("-1");
                    return 0;
                }
                for(int k=0;k<26;k++){
                    if(comp_matrix[j][k]){
                        comp_matrix[i][k]=1;
                    }
                }
            }
        }
    }
    printf("\n");
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            printf("%d ", comp_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<26; i++){
        if(!inputted[i])
            continue;
        for(int j=0; j<26; j++){
            if(i==j||!inputted[j])
                continue;
            if(!(comp_matrix[i][j]+comp_matrix[j][i]))
                comp_matrix[i<j?i:j][i<j?j:i]=1;
        }
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            printf("%d ", comp_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int max=0;
    for(int i=0; i<26; i++){
        int row_sum=0;
        for(int j=0; j<26; j++){
            row_sum+=comp_matrix[i][j];
        }
        if(row_sum>max){
            max=row_sum;
        }
    }
    for(int s=max;s>=0;s--){
        for(int i=0; i<26; i++){
            if(!inputted[i])
                continue;
            int row_sum=0;
            for(int j=0; j<26; j++){
                row_sum+=comp_matrix[i][j];
            }
            if(row_sum==s){
                printf("%c ", i+'a');
            }
        }
    }
    return 0;
}
