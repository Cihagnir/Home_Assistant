////// 
//      INCLUDE SECTION 
//////
#include "Esp_Task.h"


////// 
//      FUNCTION SECTION  
//////


esp_err_t Io_Config_Init( 
  gpio_num_t Io_num, gpio_mode_t Io_mode, gpio_pullup_t Io_pullUp, 
  gpio_pulldown_t Io_pullDown, gpio_int_type_t Io_intrt 
  ){
  
  esp_err_t Is_io_set = gpio_reset_pin(DOOR_LOCK_CONTRL_PIN);

  gpio_set_direction(DOOR_LOCK_CONTRL_PIN,GPIO_MODE_OUTPUT);

  gpio_pulldown_en(DOOR_LOCK_CONTRL_PIN);
  
  return Is_io_set;
}
