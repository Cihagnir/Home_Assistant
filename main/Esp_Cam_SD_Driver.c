
////// 
//      INCLUDE SECTION 
//////
#include <Esp_Cam_SD_Defns.h>

uint64_t counter = 1 ;
////// 
//      GLOBAL VARIABLE SECTION  
//////
static camera_config_t camera_config_struct = {

    .pin_pwdn = CAM_PIN_PWDN,
    .pin_reset = CAM_PIN_RESET,
    .pin_xclk = CAM_PIN_XCLK,
    .pin_sscb_sda = CAM_PIN_SIOD,
    .pin_sscb_scl = CAM_PIN_SIOC,

    .pin_d7 = CAM_PIN_D7,
    .pin_d6 = CAM_PIN_D6,
    .pin_d5 = CAM_PIN_D5,
    .pin_d4 = CAM_PIN_D4,
    .pin_d3 = CAM_PIN_D3,
    .pin_d2 = CAM_PIN_D2,
    .pin_d1 = CAM_PIN_D1,
    .pin_d0 = CAM_PIN_D0,
    .pin_vsync = CAM_PIN_VSYNC,
    .pin_href = CAM_PIN_HREF,
    .pin_pclk = CAM_PIN_PCLK,
    .fb_location = CAMERA_FB_IN_PSRAM,

    //XCLK 20MHz or 10MHz for OV2640 double FPS (Experimental)
    .xclk_freq_hz = 20000000,
    // .ledc_timer = LEDC_TIMER_0,
    // .ledc_channel = LEDC_CHANNEL_0,


    .pixel_format   = PIXFORMAT_JPEG,
    .frame_size     = FRAMESIZE_VGA,
    .jpeg_quality   = 5,
    .fb_count       = 1,
    .grab_mode      = CAMERA_GRAB_LATEST

};


camera_fb_t *picture_start_pointer;


////// 
//      FUNCTION SECTION  
//////

// Cam Init Function 
esp_err_t Camera_Init()
{   
    ESP_LOGE("Camera_Init Started", "Camare init Start");
    //initialize the camera
    esp_err_t err = esp_camera_init(&camera_config_struct);
    if (err != ESP_OK)
    {
        ESP_LOGE("Camera_Init Started", "Camera Init Failed");
        return err;
    }

    return ESP_OK;
}


// SD Init Function 
void SD_Card_Init()
{
  esp_err_t ret = ESP_FAIL;

  esp_vfs_fat_sdmmc_mount_config_t mount_config = {
      .format_if_mount_failed = false,
      .max_files = 20,
      .allocation_unit_size = 16 * 1024
  };
  sdmmc_card_t *card;

  const char mount_point[] = MOUNT_POINT;
  ESP_LOGI("Sd Card Init :: ", "Initializing SD card");

  sdmmc_host_t host = SDMMC_HOST_DEFAULT();
  sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

  ESP_LOGI("Sd Card Init :: ", "Mounting SD card...");
  gpio_set_pull_mode(15, GPIO_PULLUP_ONLY);   // CMD, needed in 4- and 1- line modes
  gpio_set_pull_mode(2, GPIO_PULLUP_ONLY);    // D0, needed in 4- and 1-line modes
  gpio_set_pull_mode(4, GPIO_PULLUP_ONLY);    // D1, needed in 4-line mode only
  gpio_set_pull_mode(12, GPIO_PULLUP_ONLY);   // D2, needed in 4-line mode only
  gpio_set_pull_mode(13, GPIO_PULLUP_ONLY);   // D3, needed in 4- and 1-line modes

  ret = esp_vfs_fat_sdmmc_mount(mount_point, &host, &slot_config, &mount_config, &card);

  if (ret == ESP_OK)
  {
    ESP_LOGI("Sd Card Init :: ", "SD card mount successfully!");
  }
  else
  {
    ESP_LOGE("Sd Card Init :: ", "Failed to mount SD card VFAT filesystem. Error: %s", esp_err_to_name(ret));
  }

  // Card has been initialized, print its properties
  // sdmmc_card_print_info(stdout, card);

}


camera_fb_t* Cam_Take_Picture(){

  ESP_LOGI("Came_Take_Picture :: ", "Picture Take start ..." );

  picture_start_pointer = esp_camera_fb_get();
  ESP_LOGE("Came_Take_Picture :: ", "picture returned ");
  
  char *picture_name_char = malloc(30 + sizeof(uint64_t));

  /*  SD Card Save
  sprintf(picture_name_char, MOUNT_POINT"/pic_%lli.jpg", counter);
  
  counter++;

  FILE *picture_file = fopen(picture_name_char, "w");

  if (picture_file != NULL){
    
    fwrite(picture_start_pointer->buf, 1, picture_start_pointer->len, picture_file);
    ESP_LOGI("Came_Take_Picture :: ", "File saved: %s", picture_name_char);

  }
    else{
      ESP_LOGE("Came_Take_Picture :: ", "Could not open file ");
  }

  fclose(picture_file);
  */

  return picture_start_pointer;
}
