#include <stdio.h>

void OrdenacaoCrescente(int vet[], int tam);
void LerVetor(int tam, int vet[]);
void ImprimirVetor(int tam, int vet[]);
void ImprimirLivrosParaComprar(int vet[], int tam);

int main(){
    int tam;
    scanf("%d", &tam);
    int vet[tam];
    LerVetor(tam, vet);
    OrdenacaoCrescente(vet,tam);
    // ImprimirVetor(tam, vet);
    ImprimirLivrosParaComprar(vet, tam);

    return 0;
}

void OrdenacaoCrescente(int vet[], int tam){
    int temp;
    for(int i=0; i<tam;i++){
        for(int j=0; j<tam-1;j++){
            if(vet[j]>vet[j+1]){
                temp = vet[j];
                vet[j]= vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}
void LerVetor(int tam, int vet[]){
    int n;
      for(int i=0; i<tam;i++){
        scanf(" %d", &n);
        vet[i]=n;
    }
}
void ImprimirVetor(int tam, int vet[]){
    for(int i=0; i<tam; i++){
        printf(" %d", vet[i]);
    }
    printf("\n");
}
void ImprimirLivrosParaComprar(int vet[], int tam){
    int cont=0;
     for(int i=0; i<tam; i++){
        for(int j=0; j<tam;j++){
            if(vet[i]==vet[j]){
                cont++;
            }
        }
        if(cont==1)
            printf(" %d", vet[i]);
        cont =0;
    }
    printf("\n");
}