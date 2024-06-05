#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUZZER_PIN GPIO_NUM_27


void configure_buzz(void);
void alarmon(void);
void alarmoff(void);