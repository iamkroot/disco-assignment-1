#include <stdio.h>

#define MAXNUM 100000
int less[MAXNUM], same[MAXNUM], more[MAXNUM], freq[MAXNUM];

int main(int argc, char const *argv[]) {
    for(int i=0; i<MAXNUM; i++)
        less[i]=same[i]=more[i]=freq[i]=0;
    int n, m=0, num_not_eq=0, unique=0, ans=0;
    scanf("%d\n", &n);
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
            for(int i=0; i<k; i++)
                same[a[i]]=same[b[i]]=1;
        }
        else if(comparator=='<'){
            num_not_eq++;
            for(int i=0; i<k; i++){
                freq[a[i]]--;
                freq[b[i]]++;
            }
        }
        else if(comparator=='>'){
            num_not_eq++;
            for(int i=0; i<k; i++){
                freq[a[i]]++;
                freq[b[i]]--;
            }
        }
    }
    for(int i=0; i<m; i++){
        freq[i] = freq[i]>0?freq[i]:-freq[i];
        if(freq[i]==num_not_eq&&!same[i]){
            ans=i;
            unique++;
        }
    }
    printf("%d\n", (unique==1)?ans:-1);
    return 0;
}
