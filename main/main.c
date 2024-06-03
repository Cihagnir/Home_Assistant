
////// 
//      INCLUDE SECTION 
//////

// Hand Made Libraries Section
#include "WiFi_Defns.h"
#include "Socket_Defns.h"
#include "Esp_Cam_SD_Defns.h"



////// 
//      PROJECT DEFINE SECTION  
//////

// static char *End_Msg = "END";
char *recv_data;
//char *Client_Init_Msg = "INIT_CAM_01";
//char *Client_Init_Msg = "INIT_CAM_02";
char *Client_Init_Msg = "INIT_CAM_03";


static bool is_client_start = false;
static camera_fb_t *picture_start_pointer ;

uint8_t Init_Msg_Length = 11;

////// 
//      MAIN LOOP  
//////

void app_main(void){

    esp_err_t nsv_return = nvs_flash_init();

    if (nsv_return == ESP_ERR_NVS_NO_FREE_PAGES || nsv_return == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      nsv_return = nvs_flash_init();
    }
    ESP_ERROR_CHECK(nsv_return);
    
    // Module Init Section
    WiFi_Init_Sta();

    Camera_Init();

    //SD_Card_Init();

    Socket_Connection_Hand();
    
    // Init Msg Sended
    Socket_Message_Sender_Hand(Client_Init_Msg, Init_Msg_Length, 0);

    while (1){ 
      
      recv_data = Socket_Message_Recv_Hand();

      is_client_start = (bool) *recv_data;
      

      while(is_client_start) {

        picture_start_pointer = Cam_Take_Picture();

        Socket_Message_Sender_Hand(picture_start_pointer->buf, picture_start_pointer->len,0);

        esp_camera_fb_return(picture_start_pointer);
      
      }
      
    }

}
