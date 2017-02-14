#include <stdio.h>
#include <stdlib.h>

/** Logaritmo */
int valor = 0;
int base = 0;

int main() {
    /** Log base 2 /
    while (valor <= 1) {
        printf("Informe o valor do logaritmando:\n");
        scanf("%d", &valor);
    }
    printf("\nO logaritmo de %d na base 2 eh %d\n", valor, log2_piso(valor));
    //*/

    /** Log base N /
    do {
        printf("Informe o valor do logaritmando:\n");
        scanf("%d", &valor);

        printf("Informe o valor da base:\n");
        scanf("%d", &base);
    } while (valor <= 0 || base <= 0 && !(base * base < valor));

    printf("\nO logaritmo de %d na base %d eh %d\n", valor, base, log_piso(valor, base));
    //*/

    /** Primo */
    printf("Informe o numero para verificar se ele eh primo:\n");
    scanf("%d", &valor);

    if (verificar_primo(valor) == 0) {
        printf("\nO numero %d nao eh primo.\n", valor);
    }
    else {
        printf("\nO numero %d eh primo.\n", valor);
    }

    //*/
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
