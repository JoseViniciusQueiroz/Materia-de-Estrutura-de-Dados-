#include <stdio.h>


int ackermann(int x,int y){
    if (x<0 || y<0){
        return 0;
    }
    else if(x==0){
        return y+1;
    }
    else if(y==0){
        return ackermann(x-1,1);
    }
    else{
        return ackermann(x-1,ackermann(x,y-1));
    }

}

int main (){

    int x=2;
    int y=0;
    printf("%d\n",ackermann(x,y));

}