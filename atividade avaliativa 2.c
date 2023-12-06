#include <stdio.h>
#include <string.h>

typedef struct {
    char genre[2];
    float wage;
} Salaried;

int checkWage(float wage) {
    if (wage < 1.00) {
        printf("Salario invalido, digite novamente\n");
        return 0;
    } else {
        return 1;
    }
}

void classifyWage(float wage, char *classification) {
    const float minimumWage = 1400.00;

    if (wage > minimumWage) {
        strcpy(classification, "Acima do salario minimo");
    } else if (wage == minimumWage) {
        strcpy(classification, "Igual ao salario minimo");
    } else {
        strcpy(classification, "Abaixo do salario minimo");
    }
}

void showClassification(Salaried salaried) {
    char classification[50];

    classifyWage(salaried.wage, classification);

    printf("\n\nSalario: %.2f", salaried.wage);
    printf("\nClassificacao: %s", classification);
    printf("\nSexo: %s\n", (strcmp(salaried.genre, "M") == 0) ? "Masculino" : "Feminino");
}

int main() {
    int numSalaried;
    printf("Digite o numero de assalariados: ");
    scanf("%d", &numSalaried);

    Salaried salariedList[numSalaried];

    int belowMinimumWage = 0;
    int aboveMinimumWage = 0;

    for (int i = 0; i < numSalaried; ++i) {
        printf("\n\nAssalariado %d:", i + 1);

        printf("\nDigite o sexo (M/F): ");
        scanf("%s", salariedList[i].genre);

        do {
            printf("Digite o salario: ");
            scanf("%f", &salariedList[i].wage);
        } while (!checkWage(salariedList[i].wage));

        showClassification(salariedList[i]);

        if (salariedList[i].wage < 1400.00) {
            belowMinimumWage++;
        } else {
            aboveMinimumWage++;
        }
    }

    printf("\n\nResultado:");
    printf("\nabaixo do salario minimo: %d", belowMinimumWage);
    printf("\nacima do salario minimo: %d\n", aboveMinimumWage);

    return 0;
}
