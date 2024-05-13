
////// 
//      INCLUDE SECTION 
//////

// Hand Made Libraries Section
#include "WiFi_Defns.h"
#include "Socket_Defns.h"
////// 
//      PROJECT DEFINE SECTION  
//////
char*  recv_data;
static char *end_message = "END";

void app_main(void){

    esp_err_t nsv_return = nvs_flash_init();

    if (nsv_return == ESP_ERR_NVS_NO_FREE_PAGES || nsv_return == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      nsv_return = nvs_flash_init();
    }
    ESP_ERROR_CHECK(nsv_return);
    
    WiFi_Init_Sta();

    Socket_Connection_Hand();

    while (true)
    {
      // MAIN LOOP OF THE SYSTEM
    }
    


    // xTaskCreate(Tcp_Client_Task, "tcp_client", 4096, NULL, 5, NULL);




}
