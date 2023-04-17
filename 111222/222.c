#include <stdio.h>

int arr[205][205];

int main(){
    
    int t;
    scanf("%d", &t);
    int n, m;
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        int maxi = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = arr[i][j];
                //i-k j-k i+k j+k // i-k j+k i+k j-k
                for(int k = 1; ;k++){
                    if(i-k >= 0 && j-k >= 0){
                        sum += arr[i-k][j-k];
                    }if(i+k < n && j+k < m){
                        sum += arr[i+k][j+k];
                    }if(i-k >= 0 && j+k < m){
                        sum += arr[i-k][j+k];
                    }if(i+k < n && j-k >= 0){
                        sum += arr[i+k][j-k];
                    }
                    if(i-k < 0 && j-k < 0 && i+k >= n && j+k >= m){
                        break;
                    }
                }
                maxi = max(maxi, sum);
            }
            
        }   
        printf("%d\n", maxi);
    }
    return 0;
}