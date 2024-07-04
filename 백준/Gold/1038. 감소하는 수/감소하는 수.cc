#include <cstdio>
using namespace std;
int main(){
    int n, k = -1;
    scanf("%d", &n);
    for(long long i1 = 0; i1 < 10; i1++){
        for(int i2 = 0; i2 < (i1 == 0 ? 10 : i1); i2++){
            for(int i3 = 0; i3 < (i2 == 0 ? 10 : i2); i3++){
                if(i1 && i2 == i3){
                    break;
                }
                for(int i4 = 0; i4 < (i3 == 0 ? 10 : i3); i4++){
                    if(i2 && i3 == i4){
                        break;
                    }
                    for(int i5 = 0; i5 < (i4 == 0 ? 10 : i4); i5++){
                        if(i3 && i4 == i5){
                            break;
                        }
                        for(int i6 = 0; i6 < (i5 == 0 ? 10 : i5); i6++){
                            if(i4 && i5 == i6){
                                break;
                            }
                            for(int i7 = 0; i7 < (i6 == 0 ? 10 : i6); i7++){
                                if(i5 && i6 == i7){
                                    break;
                                }
                                for(int i8 = 0; i8 < (i7 == 0 ? 10 : i7); i8++){
                                    if(i6 && i7 == i8){
                                        break;
                                    }
                                    for(int i9 = 0; i9 < (i8 == 0 ? 10 : i8); i9++){
                                        if(i7 && i8 == i9){
                                            break;
                                        }
                                        for(int i10 = 0; i10 < (i9 == 0 ? 10 : i9); i10++){
                                            if(i8 && i9 == i10){
                                                break;
                                            }
                                            k++;
                                            if(k == n){
                                                printf("%lld", i10 + i9*10 + i8*100 + i7*1000 + i6*10000 + i5*100000 + i4*1000000 + i3*10000000 + i2*100000000 + i1*1000000000);
                                                return 0;
                                            }
                                        }   
                                    }   
                                }   
                            }   
                        }
                    }
                }
            }
        }
    }
    printf("-1");
    return 0;
}