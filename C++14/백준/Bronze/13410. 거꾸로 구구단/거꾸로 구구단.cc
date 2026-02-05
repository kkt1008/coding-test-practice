#include <cstdio>
#include <math.h>

int MAX(int a, int b){
    return a > b ? a : b;
}
int main(){
    int N, K, max = 0;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= K; i++){
        int temp = 0;
        int multiply = N * i;
        temp = multiply;
        int cnt = 0;
        while(temp >= 10){
            temp /= 10;
            cnt++;
        }
        temp = 0;
        for(int j = cnt; j >= 0; j--){
            int f = pow(10, j);
            int ff = multiply / f;
            temp += ff * pow(10, cnt - j);
            multiply %= f;
        }
        max = MAX(temp, max);
    }
    printf("%d", max);
}