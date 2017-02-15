#include <stdio.h>
#include <stdlib.h>

/** Logaritmo */
int valor = 1;
int base = 1;

/** MDC */
int valor2 = -2;
int valor3 = -1;

/** Torre de Hanói */
int num_discos = 0;

int main() {
    /** Log base 2 /
    while (valor <= 1) {
        printf("Informe o valor do logaritmando:\n");
        scanf("%d", &valor);

        printf("\n");
    }
    printf("\nO logaritmo de %d na base 2 eh %d\n", valor, log2_piso(valor));
    //*/

    /** Log base N /
    while (valor <= 1 && base <= 1) {
        printf("Informe o valor do logaritmando:\n");
        scanf("%d", &valor);

        printf("Informe o valor da base:\n");
        scanf("%d", &base);

        printf("\n");
    }

    printf("\nO logaritmo de %d na base %d eh %d\n", valor, base, log_piso(valor, base));
    //*/

    /** Primo /
    printf("Informe o numero para verificar se ele eh primo:\n");
    scanf("%d", &valor);

    if (verificar_primo(valor) == 0) {
        printf("\nO numero %d nao eh primo.\n", valor);
    }
    else {
        printf("\nO numero %d eh primo.\n", valor);
    }

    //*/

    /** Algoritmo de Euclides /
    while (valor2 < valor3) {
        printf("Infome o primeiro valor:\n");
        scanf("%d", &valor2);

        printf("\nInforme o segundo valor:\n");
        scanf("%d", &valor3);

        printf("\n");
    }

    printf("MDC = %d\n", MDC(valor2, valor3));
    //*/

    /** Torre de Hanói */

    while (num_discos == 0) {
        printf("Digite o numero de discos:\n");
        scanf("%d", &num_discos);
    }

    Transfere (num_discos, 'A', 'C', 'B');
    //*/

    return 0;
}

int log2_piso (int logaritmando) {
    if (logaritmando / 2 == 1) {
        return 1;
    }
    return log2_piso (logaritmando / 2) + 1;
}

int log_piso (int logaritmando, int base) {
    if (logaritmando / base == 0) {
        return;
    }

    if (logaritmando / base == 1) {
        return 1;
    }

    return log_piso (logaritmando / base, base) + 1;
}

int MDC (int minuendo, int subtraendo) {
    int resto;

    if (subtraendo == 0) {
        return minuendo;
    }

    resto = minuendo % subtraendo;

    return MDC (subtraendo, resto);
}

void Transfere (int tamanho, char origem, char destino, char auxiliar) {
    if (tamanho == 1) {
        return;
    }

    else {
        Transfere (tamanho - 1, origem, auxiliar, destino);
        Transfere (tamanho - 1, auxiliar, destino, origem);
    }
}

int verificar_primo (int numero) {
    if (numero == 1) {
        return 1;
    }

    if (numero == 2) {
        return 1;
    }

    int limite = sqrt(numero);

    return (verificar_primo_aux (numero, limite) == 0) ? 0 : 1;
}

int verificar_primo_aux (int numero, int limite) {

    if (limite == 0 || limite == 1) {
        return 1;
    }

    if (numero % limite == 0) {
        return 0;
    }

    return verificar_primo_aux (numero, limite - 1);
}
