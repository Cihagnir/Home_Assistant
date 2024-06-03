
////// 
//      INCLUDE SECTION 
//////

// Hand Made Libraries Section
#include "WiFi_Defns.h"
#include "Socket_Defns.h"
#include "EspTask.h"
////// 
//      PROJECT DEFINE SECTION  
//////
char*  recv_data;
static char *end_message = "END";
char *Client_Init_Msg = "INIT_GASS";
uint8_t Init_Msg_Lenght = 9;

void app_main(void){

    esp_err_t nsv_return = nvs_flash_init();

    if (nsv_return == ESP_ERR_NVS_NO_FREE_PAGES || nsv_return == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      nsv_return = nvs_flash_init();
    }
    ESP_ERROR_CHECK(nsv_return);
    
    WiFi_Init_Sta();

    Socket_Connection_Hand();

    Socket_Message_Sender_Hand(Client_Init_Msg, Init_Msg_Lenght, 0);

    Io_Config_Init(
      GAS_SENSOR_INPUT_IO, GPIO_MODE_INPUT, GPIO_PULLUP_DISABLE,
      GPIO_PULLDOWN_DISABLE, GPIO_INTR_DISABLE
    );

    int gpio_read_status;
    bool Is_already_send = false;

    while (true){
      // MAIN LOOP OF THE SYSTEM

      gpio_read_status = gpio_get_level(GAS_SENSOR_INPUT_IO);
      ESP_LOGI("GAS SENSOR", "Gas sensor read %d", gpio_read_status);

      if(!gpio_read_status){

        if(! Is_already_send){
          ESP_LOGI("GAS SENSOR", "FUCKINK LEAK");
          Socket_Message_Sender_Hand(&"1", TASK_MSG_LENGHT,0);
          Is_already_send = true;
        }

      }else{
        Socket_Message_Sender_Hand(&"0", TASK_MSG_LENGHT,0);
        Is_already_send = false;
      }

    }
    
}
