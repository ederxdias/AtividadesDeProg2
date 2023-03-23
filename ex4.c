#include <stdio.h>


int ConverterDecimalParaOctal(int c,int num);

int main(){
    int num;
    scanf("%d", &num);
    int c=1;
    printf("%d", ConverterDecimalParaOctal(c, num));
    return 0;
}


int ConverterDecimalParaOctal(int c,int num){
    if(num<8){  
        return num*c;
    }
    int resp;
    resp = c*(num%8) +  ConverterDecimalParaOctal(10*c,num /8); 
    return   resp; 
}

