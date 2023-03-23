#include <stdio.h>
#include <math.h>

typedef struct 
{
    float x,y;
}Tponto;


float Distancia(Tponto pa, Tponto pt);

int main(){
    Tponto pa,pt;
    float ra,rt;
    scanf("%f %f %f %f %f %f", &pa.x, &pa.y, &pt.x, &pt.y, &ra, &rt);
    if(Distancia(pa, pt) > ra+rt)
        printf("Errou\n");
    else printf("Acertou\n");

    return 0;
}

float Distancia(Tponto pa, Tponto pt){
    return sqrt(pow(pa.x - pt.x,2) + pow(pa.y - pt.y,2));
}