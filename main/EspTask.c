////// 
//      INCLUDE SECTION 
//////
#include "EspTask.h"


////// 
//      FUNCTION SECTION  
//////


esp_err_t Io_Config_Init( 
  gpio_num_t Io_num, gpio_mode_t Io_mode, gpio_pullup_t Io_pullUp, 
  gpio_pulldown_t Io_pullDown, gpio_int_type_t Io_intrt 
  ){
  
  esp_err_t Is_io_set = gpio_reset_pin(Io_num);

  gpio_set_direction(Io_num,Io_mode);

  if (Io_pullDown){
    gpio_pulldown_en(Io_num);
  }else{
    gpio_pulldown_dis(Io_num);
  }

  if (Io_pullUp){
    gpio_pullup_en(Io_num);
  }else{
    gpio_pullup_dis(Io_num);
  }
  
  return Is_io_set;
}
