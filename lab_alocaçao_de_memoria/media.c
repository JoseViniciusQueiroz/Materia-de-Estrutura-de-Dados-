#include <stdio.h>

float Media(float *pV, int pn){
    float pM = 0;
    int pInd;
    for(pInd = 0; pInd < pn; pInd++){
        pM += pV[pInd];
    }
    return pM/pn;
}

int main(){

    float pv[5] = {2.0,3.0,3.5,5.0,2.5};
    printf("%.2f\n",Media(pv,5));

}