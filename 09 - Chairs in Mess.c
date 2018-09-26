#include <stdio.h>

int main(int argc, char const *argv[]) {
	int chairs[2000];
	int n;
	scanf("%d\n", &n);
	int max_chairs=0;
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d\n", &a, &b);
		for(int j=a; j<=b; j++){
			chairs[j]++;
			if(chairs[j]>max_chairs)
				max_chairs=chairs[j];
		}
	}
	printf("%d\n", max_chairs);
	return 0;
}