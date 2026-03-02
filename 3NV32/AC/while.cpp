#include <stdio.h>
#include <conio.h>
int main()
{
    int i=0,n;
    float sum=0, prom, d;
    printf("Este programa obtiene el promedio de calificaciones\n");
    printf("Cuantas calificaciones desea promediar? ");
    scanf("%d",&n);
    if(n>0)
    {
        printf("Ingrese las calificaciones: \n");
        for(i=0;i<n;i++)
        {
            printf("Calificacion %d: ",i+1);
            scanf("%f",&d);
            sum+=d;
        }
        prom=sum/n;
        printf("El promedio es: %.2f\n",prom);
    }
    getch();
}