#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <string.h>

int main()
{
    setlocale(LC_CTYPE, "Portuguese");
    int i, j, c, opc, desvioAtv = 0, localMaior = 0, localMenor = 0;
    float mediaAlt = 0, desvio, medianaAlt = 0, altura[10], alturaTotal = 0, alturaTotal2 = 0, menor, maior, alturaOpc5[10], k = 0;
    char matriz[10][50];
    char matriz2[50];
    char matrizOpc5[10][50];

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

    Sleep(5000);
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
    for(i = 0; i < 10; i++){
        alturaOpc5[i] = altura[i];
    }
    for(i = 0; i < 10; i++){
        strcpy(matrizOpc5[i], matriz[i]);
    }
    mediaAlt = (alturaTotal / 10);
    for(i = 0; i < 10; i++){
        alturaTotal2 += pow(altura[i], 2);
    }

    desvio = ((alturaTotal2 - alturaTotal) - mediaAlt);

    maior = altura[0];
    menor = altura[0];

    for(c = 0; c < 10; c++){
        if(altura[c] < menor){
            menor = altura[c];
            localMenor = c;
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


        switch(opc){
            case(1):
                for(i = 0; i < 10; i++){
                    printf("O %iº jogador é o %s e ele têm %.2fm de altura.\n", (i + 1), matriz[i], altura[i]);
                }
                    printf("\n");
                    Sleep(7000);
                    system("CLS");
            break;
            case(2):
                printf("A média das alturas dos jogadores é: %.2f\n\n", mediaAlt);
                desvioAtv = 1;
                Sleep(3000);
                system("CLS");
            break;
            case(3):
                if(desvioAtv == 1){
                    printf("O desvio padrão é: %.2f\n\n", desvio);
                }
                else{
                    printf("Você só pode ver o desvio depois de calcular a média das alturas.\n\n");
                }
                Sleep(3000);
                system("CLS");
            break;
            case(4):
                printf("O menor jogador é o %s e ele tem %.2fm de altura.\n", matriz[localMenor], altura[localMenor]);
                printf("O maior jogador é o %s e ele tem %.2fm de altura.\n", matriz[localMaior], altura[localMaior]);
                Sleep(5000);
                system("CLS");
            break;
            case(5):
                for(j = 0; j < 10; j++){
                    for(i = j + 1; i < 10; i++){
                        if(alturaOpc5[j] > alturaOpc5[i]){
                            k = alturaOpc5[j];
                            alturaOpc5[j] = alturaOpc5[i];
                            alturaOpc5[i] = k;
                            strcpy(matriz2, matrizOpc5[i]);
                            strcpy(matrizOpc5[i], matrizOpc5[j]);
                            strcpy(matrizOpc5[j], matriz2);
                        }
                    }
                }
                for(i = 0; i < 10; i++){
                    printf("O %iº jogador na lista ordenada é o %s e ele têm %.2f m de altura.\n", (i + 1), matrizOpc5[i], alturaOpc5[i]);
                }
                medianaAlt += ((alturaOpc5[4] + alturaOpc5[5]) / 2);
                printf("A mediana das alturas é: %.2f\n", medianaAlt);
                medianaAlt = 0;
                Sleep(7000);
                system("CLS");
            break;
            case(6):
                printf("Finalizando...");
                Sleep(2000);
                exit(0);
            break;
            default:
                printf("Opção inválida\n");
                Sleep(1000);
                system("CLS");
        }
    }
    return 0;
}
