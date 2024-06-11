#include <stdio.h>
#include <math.h>

void questao5(float *v, int m, int j, int k){
    int pmenor, pdir, pesq;
    pesq = j - 1;
    pdir = j + 1;
    while(k>0){
        if((pesq >= 0 ) & (pdir<m)){
            if(fabs(v[pesq] - v[j]) < fabs(v[pdir] - v[j])){
                pmenor = pesq;
                pesq--;
            }
            else{
                pmenor = pdir;
                pdir++;
            }
        }
        else if(pesq >= 0){
            pmenor = pesq;
            pesq--;
        }
        else if(pdir<m){
            pmenor = pdir;
            pdir++;
        }
        else{
            break;
        }

        printf("%.2f ", v[pmenor]);
        k--;
    }
    printf("\n");

    return;
}

int main(){
    float a[5];
    for(int i=0;i<5;i++){
        scanf("%f",&a[i]);
    }
    questao5(a,5,2,2);
}