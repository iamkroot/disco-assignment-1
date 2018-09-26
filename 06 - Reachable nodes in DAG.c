#include <stdio.h>

int main(int argc, char const *argv[]) {
	int n, m;
	scanf("%d %d\n", &n, &m);
	int reachable[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
				reachable[i][j] = 1;
			else
				reachable[i][j] = 0;
		}
	}
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d\n", &a, &b);
		reachable[a][b]=1;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(reachable[i][j]){
				for(int k=0; k<n; k++){
					if(reachable[j][k])
						reachable[i][k] = 1;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		if(reachable[0][i])
			printf("%d ", i);
	}
	return 0;
}