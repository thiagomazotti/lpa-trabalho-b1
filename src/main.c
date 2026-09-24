#include <stdio.h>

#define TARIFA_POR_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA_ADICIONAL 4.00

#define MODALIDADE_ECONOMICA 1
#define MODALIDADE_EXPRESSA 2
#define MODALIDADE_PRIORITARIA 3

double ler_distancia(void) {
    double distancia;

    do {
        printf("Distancia (km): ");
        scanf("%lf", &distancia);
        if (distancia <= 0) {
            printf("Valor invalido. A distancia deve ser maior que zero.\n");
        }
    } while (distancia <= 0);

    return distancia;
}

double ler_peso(void) {
    double peso;

    do {
        printf("Peso (kg): ");
        scanf("%lf", &peso);
        if (peso <= 0) {
            printf("Valor invalido. O peso deve ser maior que zero.\n");
        }
    } while (peso <= 0);

    return peso;
}

int ler_modalidade(void) {
    int modalidade;

    do {
        printf("Modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ");
        scanf("%d", &modalidade);
        if (modalidade < MODALIDADE_ECONOMICA || modalidade > MODALIDADE_PRIORITARIA) {
            printf("Codigo invalido. Informe 1, 2 ou 3.\n");
        }
    } while (modalidade < MODALIDADE_ECONOMICA || modalidade > MODALIDADE_PRIORITARIA);

    return modalidade;
}

int ler_protecao(void) {
    int protecao;

    do {
        printf("Servico de protecao (1-Sim, 0-Nao): ");
        scanf("%d", &protecao);
        if (protecao != 0 && protecao != 1) {
            printf("Opcao invalida. Informe 0 ou 1.\n");
        }
    } while (protecao != 0 && protecao != 1);

    return protecao;
}

int ler_tentativas_adicionais(void) {
    int tentativas;

    do {
        printf("Tentativas adicionais de entrega: ");
        scanf("%d", &tentativas);
        if (tentativas < 0) {
            printf("Valor invalido. Informe um inteiro maior ou igual a zero.\n");
        }
    } while (tentativas < 0);

    return tentativas;
}

int ler_continuar(void) {
    int continuar;

    do {
        printf("Processar outra entrega? (1-Sim, 0-Nao): ");
        scanf("%d", &continuar);
        if (continuar != 0 && continuar != 1) {
            printf("Opcao invalida. Informe 0 ou 1.\n");
        }
    } while (continuar != 0 && continuar != 1);

    return continuar;
}

double valor_base_distancia(double distancia) {
    if (distancia <= 5) {
        return 8.00;
    }
    if (distancia <= 15) {
        return 12.00;
    }
    if (distancia <= 30) {
        return 18.00;
    }
    return 25.00;
}

double percentual_peso(double peso) {
    if (peso <= 2) {
        return 0.00;
    }
    if (peso <= 5) {
        return 0.05;
    }
    if (peso <= 10) {
        return 0.10;
    }
    return 0.20;
}

double percentual_modalidade(int modalidade) {
    if (modalidade == MODALIDADE_EXPRESSA) {
        return 0.15;
    }
    if (modalidade == MODALIDADE_PRIORITARIA) {
        return 0.30;
    }
    return 0.00;
}

double calcular_valor_final(double distancia, double peso, int modalidade,
                            int protecao, int tentativas) {
    double subtotal = valor_base_distancia(distancia) + distancia * TARIFA_POR_KM;
    double adicional_peso = subtotal * percentual_peso(peso);
    double adicional_modalidade = subtotal * percentual_modalidade(modalidade);
    double valor_protecao = protecao ? VALOR_PROTECAO : 0.0;
    double valor_tentativas = tentativas * VALOR_TENTATIVA_ADICIONAL;

    return subtotal + adicional_peso + adicional_modalidade
           + valor_protecao + valor_tentativas;
}
