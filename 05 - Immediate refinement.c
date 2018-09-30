#include <stdio.h>
#include <math.h>

void disparr(int n, int arr[]){
    if(n==0)
        return;
    printf("{");
    for(int i=0; i<n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b}, ");
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d\n", &n);
    int a[n][10000];
    for(int i=0; i<n; i++){
        scanf("%d\n", &a[i][0]);
        for(int j=1; j<=a[i][0]; j++)
            scanf("%d ", &a[i][j]);
    }
    for(int i=0; i<n; i++){
        printf("{");
        for(int j=1, max_subsets=pow(2, a[i][0]-1); j<max_subsets; j++){
            int ss[a[i][0]], l=0, nss[a[i][0]], nl=0;
            for(int k=1; k<=a[i][0]; k++){
                if(j&1<<(k-1)){
                    ss[l]=a[i][k];
                    l++;
                }
                else{
                    nss[nl]=a[i][k];
                    nl++;
                }
            }
            for(int j=0; j<i; j++)
                disparr(a[j][0], a[j]+1);
            disparr(l, ss);
            disparr(nl, nss);
            for(int j=i+1; j<n; j++)
                disparr(a[j][0], a[j]+1);
            printf("\b\b}\n");
        }
    }
    return 0;
}