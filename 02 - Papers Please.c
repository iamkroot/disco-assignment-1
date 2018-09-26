#include <stdio.h>
#include <stdlib.h>
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
        comp_matrix[ind2][ind1] = -1;
        inputted[ind1]=1;
        inputted[ind2]=1;
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(i!=j &&comp_matrix[i][j]==1){
                if(comp_matrix[j][i]==1){
                    printf("-1");
                    return 0;
                }
                for(int k=0;k<26;k++){
                    if(comp_matrix[j][k]==1){
                        comp_matrix[i][k]=1;
                    }
                }
            }
        }
    }
    for(int i=0; i<26; i++){
        if(!inputted[i])
            continue;
        for(int j=i+1; j<26; j++){
            if(!inputted[j])
                continue;
            for(int k=25; k>=j; k--){
                if(comp_matrix[j][k]==1)
                    comp_matrix[i][k]=1;
                if(comp_matrix[j][k]==-1)
                    break;
                if(comp_matrix[i][k]==-1){
                    comp_matrix[j][i]=1;
                }
            }
        }
    }
    int max=0, row_sums[26];
    for(int i=0; i<26; i++){
        int row_sum=0;
        for(int j=0; j<26; j++){
            if(comp_matrix[i][j]==1)
                row_sum+=comp_matrix[i][j];
        }
        row_sums[i]=row_sum;
        if(row_sum>max)
            max=row_sum;
    }
    for(int s=max;s>=0;s--){
        for(int i=0; i<26; i++){
            if(!inputted[i])
                continue;
            if(row_sums[i]==s){
                printf("%c ", i+'a');
            }
        }
    }
    return 0;
}
