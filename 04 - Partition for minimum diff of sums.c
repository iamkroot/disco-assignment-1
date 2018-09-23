#include <stdio.h>
#include <stdlib.h>

int n, m;
int sums[1000];

int partition_min(int l, int num_parts, int prev_sum){
    if(num_parts==1){
        return sums[m-1] - prev_sum;
    }
    int min_sum=1e9;
    for(int i=l; i<=m-num_parts; i++){
        int s = sums[i] - prev_sum; // sum of current partition (from l to i)
        int r = partition_min(i+1, num_parts-1, sums[i]);
        int v = s>r?s:r; // v is max(sum of current part, highest sum in proceeding parts)
        if(v<min_sum){
            min_sum=v;
        }
    }
    return min_sum;
}

int main(int argc, char const *argv[]) {
    
    scanf("%d %d\n", &n, &m);
    int s=0;
    for(int i=0;i<m;i++){
        int a;
        scanf("%d ", &a);
        s+=a;
        sums[i]=s;
    }
    int a = partition_min(0, n, 0);
    printf("%d\n", a);
    return 0;
}
