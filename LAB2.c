%%file lab2.c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fibonacci (int n){
    int i = 2;
    int term_n = 0;
    int term_ant_1 = 1;
    int term_ant_2 = 1;
    if (n == 0)
    {
        term_n = 1;
    }
    if (n == 1)
    {
        term_n = 1;
    }
    while (i<=n)
    {
        term_n = term_ant_1 + term_ant_2;
        term_ant_2 = term_ant_1;
        term_ant_1 = term_n;
        i++;
    }
    return term_n;
}


double aureo_for(int cant_terminos, double *term_for){
    double num_aureo = 0;
    for(int i = 2; i<=cant_terminos; i++){
        num_aureo = (double)fibonacci(i)/fibonacci(i-1);
        term_for[i] = num_aureo;
    }
    return num_aureo;
}
double aureo_while1(double referente, double precision, int tope, double *term_w1, int *i_w1) {
    double num_aureo = 0.0;
    int i = 2;
    double error = 123.0;
    while (1) {
        num_aureo = (double)fibonacci(i) / fibonacci(i - 1);
        error = fabs((referente-num_aureo)/referente);
        term_w1[i] = num_aureo;
        if (error<=precision) {
            break;
        }
        if (i>=tope) {
            break;
        }
        i++;
    }
    i_w1[0] = i-1;
    return num_aureo;
}




double aureo_while2(double precision, int tope, double *term_w2, int *i_w2){
    double num_aureo = 0;
    int i = 2;
    double n_ant = 0.5;
    while (1)
    {
        double termino = (double)fibonacci(i) / fibonacci(i-1);
        num_aureo = termino;
        term_w2[i] = num_aureo;
        double error = fabs((num_aureo-n_ant)/n_ant);
        if (error <= precision)
        {
            break;
        }
        if (i >= tope)
        {
            break;
        }

        i++;
    }
    i_w2[0] = i-1;
    return num_aureo;
}


int main(int argc, char const *argv[])
{
    int tope = 15;
    double referencia = (1+sqrt(5))/2;
    //generando espacio en la memoria para los terminos de cada serie
    int *term_fib = (int *)malloc(sizeof(int)*10);

    //Impresion de 10 primeros terminos de la serie de fibonacci
    printf("10 primeros terminos de la serie de fibonacci:\n");
    for (int i = 0; i <10; i++)
    {
        term_fib[i] = fibonacci(i);
        printf("%d\n",term_fib[i]);
    }
   //Impresion ciclo for:
   //10 iteraciones
   double *term_for = (double *)malloc(sizeof(double)*(21));
   double resultado_for_10 = aureo_for(10, term_for);
   printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= 10; i++)
    {
        printf("%f\n",term_for[i]);
    }
    printf("El valor de la serie con 10 iteraciones es: %f\n",resultado_for_10);

    //20 iteraciones
    double resultado_for_20 = aureo_for(20, term_for);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= 20; i++)
    {
        printf("%f\n",term_for[i]);
    }
    printf("El valor de la serie con 20 iteraciones es: %f\n",resultado_for_20);
    free(term_for);

    //Impresion bucle while1
    double *term_w1 = (double *)malloc(sizeof(double)*(15+1));
    int *i_w1 = (int *)malloc(sizeof(int));
    double resultado_while1_e1 = aureo_while1(referencia, 1e-1, tope, term_w1, i_w1);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= i_w1[0]+1; i++) {
        printf("%f\n", term_w1[i]);
    }
    printf("El valor de la serie con una precision de 1e-1 es: %f, con %d iteraciones\n", resultado_while1_e1, i_w1[0]);

    //double *term_w1 = (double *)malloc(sizeof(double)*(tope+1));
    //int *i_w1 = (int *)malloc(sizeof(int));
    double resultado_while1_e2 = aureo_while1(referencia, 1e-2, tope, term_w1, i_w1);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= i_w1[0]+1; i++) {
        printf("%f\n", term_w1[i]);
    }
    printf("El valor de la serie con una precision de 1e-2 es: %f, con %d iteraciones\n", resultado_while1_e2, i_w1[0]);

    //double *term_w1 = (double *)malloc(sizeof(double)*(tope+1));
    //int *i_w1 = (int *)malloc(sizeof(int));
    double resultado_while1_e3 = aureo_while1(referencia, 1e-3, tope, term_w1, i_w1);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= i_w1[0]+1; i++) {
        printf("%f\n", term_w1[i]);
    }
    printf("El valor de la serie con una precision de 1e-3 es: %f, con %d iteraciones\n", resultado_while1_e3, i_w1[0]);
    free(term_w1);
    free(i_w1);

    //Impresion bucle while2

    double *term_w2 = (double *)malloc(sizeof(double)*(tope+1));
    int *i_w2 = (int *)malloc(sizeof(int));
    double resultado_while2_e1 = aureo_while2(1e-1, tope, term_w2, i_w2);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= i_w2[0]+1; i++) {
        printf("%f\n", term_w2[i]);
    }
    printf("El valor de la serie con una precision de 1e-1 es: %f, con %d iteraciones\n", resultado_while2_e1, i_w2[0]+1);

    double resultado_while2_e2 = aureo_while2(1e-2, tope, term_w2, i_w2);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= i_w2[0]+1; i++) {
        printf("%f\n", term_w2[i]);
    }
    printf("El valor de la serie con una precision de 1e-2 es: %f, con %d iteraciones\n", resultado_while2_e2, i_w2[0]+1);

    double resultado_while2_e3 = aureo_while2(1e-3, tope, term_w2, i_w2);
    printf("Valores parciales de la serie: \n");
    for (int i = 2; i <= i_w2[0]+1; i++) {
        printf("%f\n", term_w2[i]);
    }
    printf("El valor de la serie con una precision de 1e-3 es: %f, con %d iteraciones\n", resultado_while2_e3, i_w2[0]+1);
    free(term_w2);
    free(i_w2);
    free(term_fib);
    return 0;
