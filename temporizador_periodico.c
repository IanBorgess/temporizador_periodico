#include <stdio.h>
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.
#include "pico/time.h"   // Biblioteca para gerenciamento de tempo, como manipulação de temporizadores e atrasos.

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int led_atual = LED_PIN_GREEN;

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) {

    gpio_put(led_atual, false);

    // Alterna para o próximo LED
    if (led_atual == LED_PIN_GREEN) {
        led_atual = LED_PIN_RED;
    } else if (led_atual == LED_PIN_RED) {
        led_atual = LED_PIN_YELLOW;
    } else if (led_atual == LED_PIN_YELLOW) {
        led_atual = LED_PIN_GREEN;
    }

    // Liga o próximo LED
    gpio_put(led_atual, true);
    
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

int main() {
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializar o pino GPIO11
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED,true);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW,true);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN,true);


    // Declaração de uma estrutura de temporizador de repetição.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 1 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        // Imprime uma mensagem a cada segundo
        printf("LED atual: %s\n", 
               led_atual == LED_PIN_RED ? "Vermelho" : 
               led_atual == LED_PIN_YELLOW ? "Amarelo" : "Verde");

        // Pausa de 1 segundo para reduzir o uso da CPU.
        sleep_ms(1000);
    }
    return 0;
}