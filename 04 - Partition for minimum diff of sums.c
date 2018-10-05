#include <stdio.h>

int main(int argc, char const *argv[]){
    int n, m, lo=0, hi=0;
    scanf("%d %d\n", &n, &m);
    int a[m];
    for(int i=0; i<m; i++){
        scanf("%d\n", &a[i]);
        if(lo<a[i])
            lo=a[i];
        hi+=a[i];
    }
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int teams=0, current_power=0;
        for(int i=0; i<m; i++){
            if(current_power+a[i]<=mid)
                current_power+=a[i];
            else{
                teams++;
                current_power=a[i];
            }
        } 
        if(teams<n)
            hi=mid;
        else
            lo=mid+1;
    }
    printf("%d\n", lo);
    return 0;
}