/*
 * Example to demonstrate thread definition.
 */
#include <FreeRTOS_ARM.h>
#include "PowerDueLED.h"

// Declare a semaphore handle.
SemaphoreHandle_t sem;
//------------------------------------------------------------------------------
/*
 * ThreadRed, turn the RED LED on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadRed(void*arg){
  //Turn the Red led on.
  SerialUSB.println("Turning the Red Led on");
  pd_rgb_led(PD_RED);

  //Sleep for 500 milliseconds
  vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
  
  //Turn the Red led off.
  SerialUSB.println("Turning the Red Led off");
  pd_rgb_led(PD_OFF);

  //Sleep for 500 milliseconds
  vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);

  //Done with the thread
  SerialUSB.println("Done");

  //Turn the Green led on.
  SerialUSB.println("Turning the Green  Led on");
  pd_rgb_led(PD_GREEN);

  //Sleep for 500 milliseconds
  vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
  
  //Turn the green led off.
  SerialUSB.println("Turning the Green Led off");
  pd_rgb_led(PD_OFF);

  //Sleep for 500 milliseconds
  vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);

   SerialUSB.println("Turning the Blue Led on");
  pd_rgb_led(PD_BLUE);

  //Sleep for 500 milliseconds
  vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
  
  //Turn the blue led off.
  SerialUSB.println("Turning the Blue Led off");
  pd_rgb_led(PD_OFF);

  //Sleep for 500 milliseconds
  vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);

  //Done with the thread
  SerialUSB.println("Done");
  while(1);
  
}



//------------------------------------------------------------------------------
void setup() {
  //INTILIAZING PINS FOR Output LEDS
  
  pinMode(PD_RED, OUTPUT); 
  pinMode(PD_GREEN, OUTPUT);
  pinMode(PD_BLUE, OUTPUT);

  
  digitalWrite(PD_RED, LOW );   
  digitalWrite(PD_GREEN, LOW);   
  digitalWrite(PD_BLUE, LOW); 
  
  portBASE_TYPE s1, s2, s3 ;

  Serial.begin(9600);

  // initialize semaphore
  sem = xSemaphoreCreateCounting(1, 0);

  // create task at priority two
  s1 = xTaskCreate(ThreadRed,NULL,configMINIMAL_STACK_SIZE, NULL, 5, NULL);

  // create task at priority one
  s2 = xTaskCreate(ThreadGreen, NULL, configMINIMAL_STACK_SIZE, NULL, 5, NULL);

  //create task at priority five
   s3 = xTaskCreate(ThreadBlue, NULL, configMINIMAL_STACK_SIZE, NULL, 5, NULL);
  

  // check for creation errors
  if (sem== NULL || s1 != pdPASS || s2 != pdPASS || s3 != pdPASS ) {
    Serial.println(F("Creation problem"));
    while(1);
  }
  // start scheduler
  vTaskStartScheduler();

  Serial.println(configMINIMAL_STACK_SIZE);
  Serial.println(configTICK_RATE_HZ);
}
//------------------------------------------------------------------------------
// WARNING idle loop has a very small stack (configMINIMAL_STACK_SIZE)
// loop must never block
void loop() {
  // Not used.
}
