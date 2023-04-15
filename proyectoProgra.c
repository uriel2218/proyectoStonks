#include <stdio.h>
#include <stdlib.h>

int printMenu (char message [], char **options){
    int row = sizeof(options) / sizeof(options[0]);
    int column = sizeof (options [0]) /row;
    int option;
    printf(" %s\n", message);
    system("clear");
    fflush( stdin );
    for (int i = 1; i <= column; i++){
        printf("\n%i %s\n", i, options [i]);

    }
    scanf("%d", &option);
    if(option)
        return option;
    else
        return 0;
    }

void suma(int x, int y){
    if((x%2==0 && y%2==0) || (x>10 && y >10) )
        printf("%d",x+y);
    else
        printf("Error");
}

int main(){
    char inutil, opciones = {"mensaje1","mensaje2","mensaje3","mensaje4"};
    int flag = 0;
    while(flag!=4){
        flag = printMenu("Mensaje de prueba",opciones);
        printf("Dame la opcion: \n");
        scanf("");
        switch (flag){
            case 1:
                printf("\n1");
                break;
            
            case 2:
                printf("\n2");
                break;
            
            case 3:
                printf("\n3");
                break;
            
            case 0:
                printf("\nNo valido");
                break;
            default:
                printf("\nNo valido");
                break;
        }
        printf("\nOprima enter tecla cualquiera para continuar ");
        fflush( stdin );
        scanf("%c",&inutil);
    }
    printf("excelente");
}