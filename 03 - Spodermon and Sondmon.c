#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	int roots[n];
	for(int i=0; i<n; i++){
		roots[i]=i;
	}
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d\n", &a, &b);
		if(roots[b]>roots[a]){
			for(int j=0; j<n; j++){
				if(roots[j]==roots[b])
					roots[j] = roots[a];
			}
		}
		else{
			for(int j=0; j<n; j++){
				if(roots[j]==roots[a])
					roots[j] = roots[b];
			}
		}
	}
	for(int i=0; i<n; i++){
		if(roots[i]!=roots[roots[i]]){
			roots[i]=roots[roots[i]];
		}
	}
	int done[n], unique=0;
	for(int i=0; i<n; i++){
		done[i]=0;
	}
	for(int i=0; i<n; i++){
		if(!done[roots[i]]){
			unique++;
			done[roots[i]]=1;
		}
	}
	printf("%d\n", unique);
	return 0;
}