#include<FreeRTOS_ARM.h>
#include"PowerDueLED.h"


QueueHandle_t input_q;

static void GetInputs(void*arg){
  while(1){
  if (SerialUSB){
    char colors= SerialUSB.read();
    xQueueSendToBack(input_q,&colors,portMAX_DELAY);
   }
  vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
  }
}


static void BlinkLeds(void*arg){
  while(1){
    char input_color;
    pd_rgb_led(PD_OFF);

    xQueueReceive(input_q,&input_color,portMAX_DELAY);

    switch (input_color){
      case 'r':
      pd_rgb_led(PD_RED);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      case 'g':
      pd_rgb_led(PD_GREEN);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      case 'b':
      pd_rgb_led(PD_BLUE);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      case 'y':
      pd_rgb_led(PD_YELLOW);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      case 'p':
      pd_rgb_led(PD_PURPLE);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      case 't':
      pd_rgb_led(PD_TIEL);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      case 'w':
      pd_rgb_led(PD_WHITE);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      pd_rgb_led(PD_OFF)
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      break;
      
      
    }
    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
  }
}

void setup(){
  portBASE_TYPE s1,s2;
  SerialUSB.begin(9600);
  while(!SerialUSB);
  input_q = xQueueCreate(10,1);
  pd_rgb_led_init();

  s1 =xTaskCreate(GetInputs,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
  s2 =xTaskCreate(BlinkLeds,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);  


vTaskStartScheduler();
Serial.println("Insufficient RAM");
while(1);
}

void loop(){
}
