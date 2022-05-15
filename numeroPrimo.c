#include <math.h>

int numeroPrimo(unsigned long long N){
    unsigned long long i, s;
    if(N==2){
        return 1;
    }
    if (N%2 == 0 || N==1){
        return 0;
    }
    if (N > 2){
        s = sqrt(N)+1;
        for(i = 3; i < s; i = i + 2){
            if (N%i == 0){
                return 0;
            }
        }
    }
    return 1;
}