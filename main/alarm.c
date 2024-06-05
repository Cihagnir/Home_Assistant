#include "alarm.h"

void configure_buzz(void)
{
    gpio_reset_pin(BUZZER_PIN);
    gpio_set_direction(BUZZER_PIN, GPIO_MODE_OUTPUT);
}
void alarmon(void){
        gpio_set_level(BUZZER_PIN, 1); // Buzzer'ı aç
        vTaskDelay(500 / portTICK_PERIOD_MS); // 500 ms bekle
}
void alarmoff(void){
    gpio_set_level(BUZZER_PIN, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS); 
}