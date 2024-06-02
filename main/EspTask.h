// Hand Made Libraries Section
#include "General_Defns.h"

// External Libraries Section
#include "driver/gpio.h"
#include "string.h"

// Esp Task Define section
#define GAS_SENSOR_INPUT_IO    GPIO_NUM_27
#define GAS_LEAK_MSG            '1'
#define TASK_MSG_LENGHT         1



void Task_Msg_Hand(bool task_msg_pointer);
void Gas_Sensor_Read_Hand(int is_door_lock);
esp_err_t Io_Config_Init( gpio_num_t Io_num, gpio_mode_t Io_mode, gpio_pullup_t Io_pullUp, gpio_pulldown_t Io_pullDown, gpio_int_type_t Io_intrt );




