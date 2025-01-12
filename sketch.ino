#include "pico/stdlib.h"

// Definições de pinos e tempos
#define PINO_LED 13
#define PONTO_TEMPO_MS 200
#define TRACO_TEMPO_MS 800
#define ESPACO_GAP_TEMPO_MS 125
#define ESPACO_LETRA_TEMPO_MS 250
#define ESPACO_SOS_TEMPO_MS 3000

// Função para acender o LED por um tempo específico
void piscar_led(int duracao_ms) {
    gpio_put(PINO_LED, 1); // Liga o LED
    sleep_ms(duracao_ms);  // Mantém o LED aceso
    gpio_put(PINO_LED, 0); // Desliga o LED
    sleep_ms(ESPACO_GAP_TEMPO_MS); // Gap entre pulsos
}

// Função para transmitir o sinal SOS
void enviar_sinal_sos() {
    // Três pontos (.)
    for (int i = 0; i < 3; i++) {
        piscar_led(PONTO_TEMPO_MS);
    }
    sleep_ms(ESPACO_LETRA_TEMPO_MS);

    // Três traços (-)
    for (int i = 0; i < 3; i++) {
        piscar_led(TRACO_TEMPO_MS);
    }
    sleep_ms(ESPACO_LETRA_TEMPO_MS);

    // Três pontos (.)
    for (int i = 0; i < 3; i++) {
        piscar_led(PONTO_TEMPO_MS);
    }
    sleep_ms(ESPACO_SOS_TEMPO_MS); // Pausa antes de reiniciar
}

int main() {
    // Inicialização do GPIO
    gpio_init(PINO_LED);
    gpio_set_dir(PINO_LED, GPIO_OUT);

    while (true) {
        enviar_sinal_sos();
    }
}
