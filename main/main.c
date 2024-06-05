
#include "alarm.h"
#include "WiFi_Defns.h"
#include "Socket_Defns.h"


char*  recv_data;
static bool data_recieved = 1;
static char *end_message = "END";
char *Init_Msg = "INIT_BUZZER" ;
uint8_t init_msg_length = 11 ;

void app_main(void){

    esp_err_t nsv_return = nvs_flash_init();

    if (nsv_return == ESP_ERR_NVS_NO_FREE_PAGES || nsv_return == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      nsv_return = nvs_flash_init();
    }
    ESP_ERROR_CHECK(nsv_return);
    
    WiFi_Init_Sta();

    Socket_Connection_Hand();

    configure_buzz();

    Socket_Message_Sender_Hand(Init_Msg, init_msg_length, 1);
    while (true){
        recv_data = Socket_Message_Recv_Hand();
        ESP_LOGE(SOCKET_MSG_TAG, "Recived data before tranformation %s", recv_data);

        data_recieved = (bool)(((int) *recv_data)- 48);
        
        ESP_LOGE(SOCKET_MSG_TAG, "Recived data after tranformation %d", data_recieved);

       if(data_recieved == true){
        ESP_LOGE("ALARM : ", " Alarm Turn ON ") ;
         alarmon();//alarm acik
         
         }
        else{
            alarmoff();//alarm kapali
          
    }
    }


    // xTaskCreate(Tcp_Client_Task, "tcp_client", 4096, NULL, 5, NULL);




}