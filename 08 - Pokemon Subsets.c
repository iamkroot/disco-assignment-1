#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d\n", &n);
    int s[n];
    for(int i=0; i<n; i++)
        scanf("%d ", &s[i]);
    int k;
    scanf("%d\n", &k);
    int u[k];
    for(int i=0; i<k; i++)
        scanf("%d ", &u[i]);
    int l;
    scanf("%d\n", &l);
    int t[l];
    for(int i=0; i<l; i++)
        scanf("%d ", &t[i]);
    int notfound[l-k], x=0;
    for(int i=0; i<l; i++){
        int in = 0;
        for(int j=0; j<k; j++){
            if(t[i]==u[j]){
                in = 1;
                break;
            }
        }
        if(!in){
            notfound[x]=t[i];
            x++;
        }
    }
    for(int i=0, num_subsets=pow(2, l); i<num_subsets; i++){
        int subset[l], len=0, req_elements=0;
        for(int j=0; j<l; j++){
            if(i&1<<j){
                subset[len] = t[j];
                for(int y=0; y<x; y++){
                    if(t[j]==notfound[y]){
                        req_elements++;
                        break;
                    }
                }
                len++;
            }
        }
        if(len+k<l){
            continue;
        }
        if(req_elements==x){
            for(int k=0; k<len; k++){
                printf("%d ", subset[k]);
            }
            printf("\n");
            
        }
    }
    return 0;
}