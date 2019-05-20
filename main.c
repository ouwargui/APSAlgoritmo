#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <string.h>

int main()
{
    setlocale(LC_CTYPE, "Portuguese");
    int i, j, k = 0, opc, desvioAtv = 0, localMaior = 0, localMenor = 0;
    float mediaAlt = 0, desvio, medianaAlt = 0, altura[10], alturaTotal = 0, alturaTotal2 = 0, menor, maior;
    char matriz[10][50];

    menor = altura[0];
    maior = altura[0];

    printf("Feito por: \n");
    printf("-----------------------------\n");
    printf("Guilherme Santos, R.A 21271755\n");
    printf("-----------------------------\n");
    printf("William Vitor, R.A 21271755\n");
    printf("-----------------------------\n");
    printf("Maria Julia, R.A 21271755\n");
    printf("-----------------------------\n");
    printf("Gabriel Gredinare, R.A 21271755\n");
    printf("-----------------------------\n");
    printf("Caique Sobral, R.A 21271755\n");
    printf("-----------------------------\n");

    /*Sleep(5000);*/
    system("CLS");

    for(i = 0; i < 10; i++){
        printf("Digite o primeiro nome do %iº jogador: \n", (i + 1));
        scanf("%s", matriz[i]);
        printf("Digite a altura desse jogador: \n");
        scanf("%f", &altura[i]);
        alturaTotal += altura[i];
        fflush(stdin);
        while(altura[i] <= 0){
            printf("Este número é inválido, digite a altura novamente: \n");
            scanf("%f", &altura[i]);
            alturaTotal += altura[i];
        }
    }

    mediaAlt = (alturaTotal / 10);
    for(i = 0; i < 10; i++){
        alturaTotal2 += pow(altura[i], 2);
    }
    desvio = ((alturaTotal2 - alturaTotal) - mediaAlt);

    for(i = 0; i < 10; i++){
        if(altura[i] < menor){
            menor = altura[i];
            localMenor = i;
        }
    }
    for(j = 0; j < 10; j++){
        if(altura[j] > maior){
            maior = altura[j];
            localMaior = j;
        }
    }

    system("CLS");

    while(1){
        printf("----------------------------------\n");
        printf("======== TIME DE BASQUETE ========\n");
        printf("----------------------------------\n");
        printf("1 - Dados dos jogadores \n");
        printf("2 - Média das alturas\n");
        printf("3 - Desvio padrão das alturas\n");
        printf("4 - Maior e menor altura\n");
        printf("5 - Mediana das alturas\n");
        printf("6 - Finalizar\n");
        printf("Digite uma opção: ");
        scanf("%i", &opc);


        if(opc == 1){
            for(i = 0; i < 10; i++){
                printf("O %iº jogador é o %s e ele têm %.2fm de altura.\n", (i + 1), matriz[i], altura[i]);
            }
            printf("\n");
            Sleep(7000);
            system("CLS");
        }
        if(opc == 2){
            printf("A média das alturas dos jogadores é: %.2f\n\n", mediaAlt);
            desvioAtv = 1;
            Sleep(3000);
            system("CLS");
        }
        if(opc == 3){
            if(desvioAtv == 1){
                printf("O desvio padrão é: %.2f\n\n", desvio);
            }
            else{
                printf("Você só pode ver o desvio depois de calcular a média das alturas.\n\n");
            }
            Sleep(3000);
            system("CLS");
        }
        if(opc == 4){
            printf("O menor jogador é o: %s e ele tem %.2fm de altura.\n", matriz[localMenor], altura[localMenor]);
            printf("O maior jogador é o: %s e ele tem %.2fm de altura.\n", matriz[localMaior], altura[localMaior]);
            Sleep(6000);
            system("CLS");
        }
        if(opc == 5){
            for(j = 0; j < 10; j++){
                for(i = j + 1; i < 10; i++){
                    if(altura[j] > altura[i]){
                        k = altura[j];
                        altura[j] = altura[i];
                        altura[i] = k;
                    }
                }
            }
            for(i = 0; i < 10; i++){
            printf("%.2f\n", altura[i]);
            }
            medianaAlt += ((altura[4] + altura[5]) / 2);
            printf("%.2f\n", medianaAlt);
        }
        if(opc == 6){
            printf("Finalizando...");
            Sleep(3000);
            exit(0);
        }

        while(opc < 1 || opc > 6){
            printf("Digite uma opção válida: \n");
            scanf("%i", &opc);
            if(opc == 1){
                for(i = 0; i < 10; i++){
                    printf("O %iº jogador é o %s e ele têm %.2fm de altura.\n", (i + 1), matriz[i], altura[i]);
                }
                printf("\n");
                Sleep(7000);
                system("CLS");
            }
            if(opc == 2){
                printf("A média das alturas dos jogadores é: %.2f\n\n", mediaAlt);
                desvioAtv = 1;
                Sleep(3000);
                system("CLS");
            }
            if(opc == 3){
                if(desvioAtv == 1){
                    printf("O desvio padrão é: %.2f\n\n", desvio);
                }
                else{
                    printf("Você só pode ver o desvio depois de calcular a média das alturas.\n\n");
                }
                Sleep(3000);
                system("CLS");
            }
            if(opc == 4){
                printf("O menor jogador é o: %s e ele tem %.2fm de altura.\n", matriz[localMenor], altura[localMenor]);
                printf("O maior jogador é o: %s e ele tem %.2fm de altura.\n", matriz[localMaior], altura[localMaior]);
                Sleep(6000);
                system("CLS");
            }
            if(opc == 5){
                for(j = 0; j < 10; j++){
                    for(i = j + 1; i < 10; i++){
                        if(altura[j] > altura[i]){
                            k = altura[j];
                            altura[j] = altura[i];
                            altura[i] = k;
                        }
                    }
                }
                for(i = 0; i < 10; i++){
                    printf("%.2f\n", altura[i]);
                }
                medianaAlt += ((altura[4] + altura[5]) / 2);
                printf("%.2f\n", medianaAlt);
            }
            if(opc == 6){
            printf("Finalizando...");
            Sleep(3000);
            exit(0);
            }
        }
    }

    return 0;
}
