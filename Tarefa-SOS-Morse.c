#include "pico/stdlib.h"

#define LED_PIN 13
#define BUZZER_PIN 10
#define POINT_DURATION_TIME 200
#define DASH_DURATION_TIME 800
#define GAP_SIGNAL_TIME 125
#define LETTER_GAP_TIME 250
#define CYCLE_DELAY_TIME 2750 // Ajustado o CYCLE_DELAY_TIME para 2750 (3000ms - LETTER_GAP_TIME (que vale 250ms)) para garantir que o intervalo total entre ciclos SOS seja exatamente 3000ms.

void blink_led_and_buzz(uint32_t duration_ms)
{
    gpio_put(LED_PIN, true);
    gpio_put(BUZZER_PIN, true);
    sleep_ms(duration_ms);
    gpio_put(LED_PIN, false);
    gpio_put(BUZZER_PIN, false);
}

void generate_morse_signal(uint32_t duration_ms, int count)
{
    for (int i = 0; i < count; i++)
    {
        blink_led_and_buzz(duration_ms);
        if (i < count - 1)
        {
            sleep_ms(GAP_SIGNAL_TIME);
        }
    }
    sleep_ms(LETTER_GAP_TIME);
}

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    while (true)
    {
        // Gera a letra "S"
        generate_morse_signal(POINT_DURATION_TIME, 3);

        // Gera a letra "O"
        generate_morse_signal(DASH_DURATION_TIME, 3);

        // Gera a letra "S"
        generate_morse_signal(POINT_DURATION_TIME, 3);

        sleep_ms(CYCLE_DELAY_TIME);
    }

    return 0;
}
