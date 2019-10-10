/*
 * Example to demonstrate thread definition, semaphores.
 */
#include <FreeRTOS_ARM.h>
#include "PowerDueLED.h"

// Declare a semaphore handle.
SemaphoreHandle_t semRed, semGreen, semBlue, semRedGreen, semRedBlue, semGreenBlue, semRedGreenBlue;
//------------------------------------------------------------------------------
/*
 * ThreadRed, turn the RED LED on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadRed(void*arg){
  while (1){
    
      // Wait until a semaphore is released
      xSemaphoreTake(semRed, portMAX_DELAY);
      
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
    
      //Done with the thread.Release Semaphore
      SerialUSB.println("Done");
      xSemaphoreGive(semGreen);
   }
}


/*
 * ThreadGreen, turn the Green LED on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadGreen(void*arg){
  while (1){
     
      // Wait until a semaphore is released
      xSemaphoreTake(semGreen, portMAX_DELAY);
      //Turn the Green led on.
      SerialUSB.println("Turning the Green Led on");
      pd_rgb_led(PD_GREEN);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
      
      //Turn the Green led off.
      SerialUSB.println("Turning the Green Led off");
      pd_rgb_led(PD_OFF);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
    
      //Done with the thread.Release Semaphore
      SerialUSB.println("Done");
      xSemaphoreGive(semBlue);
  }
}


/*
 * ThreadBlue, turn the Blue LED on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadBlue(void*arg){
  while (1){
     
      // Wait until a semaphore is released
      xSemaphoreTake(semBlue, portMAX_DELAY);
      //Turn the Blue led on.
      SerialUSB.println("Turning the Blue Led on");
      pd_rgb_led(PD_BLUE);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
      
      //Turn the Blue led off.
      SerialUSB.println("Turning the Blue Led off");
      pd_rgb_led(PD_OFF);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
    
      //Done with the thread.Release Semaphore
      SerialUSB.println("Done");
      xSemaphoreGive(semRedGreen);
   }
}

/*
 * ThreadRedGreen, turn the Red and Green LED on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadRedGreen(void*arg){
  while (1){
     
      // Wait until a semaphore is released
      xSemaphoreTake(semRedGreen, portMAX_DELAY);
      
      //Turn the Red and Green LED on.
      SerialUSB.println("Turning the Red and Green LEDs on");
      pd_rgb_led(PD_YELLOW);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
      
      //Turn the Blue led off.
      SerialUSB.println("Turning the Red and Green LEDs off");
      pd_rgb_led(PD_OFF);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
    
      //Done with the thread.Release Semaphore
      SerialUSB.println("Done");
      xSemaphoreGive(semRedBlue);
   }
}


/*
 * ThreadRedBlue, turn the Red and Blue LED on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadRedBlue(void*arg){
  while (1){
     
      // Wait until a semaphore is released
      xSemaphoreTake(semRedBlue, portMAX_DELAY);
      
      //Turn the Red and Blue LEDs on.
      SerialUSB.println("Turning the Red and Blue LEDs on");
      pd_rgb_led(PD_PURPLE);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
      
      //Turn the Red and Blue LEDs off.
      SerialUSB.println("Turning the Red and Blue LEDs off");
      pd_rgb_led(PD_OFF);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
    
      //Done with the thread.Release Semaphore
      SerialUSB.println("Done");
      xSemaphoreGive(semGreenBlue);
   }
}

/*
 * ThreadRedBlue, turn the Green and Blue LEDs on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadGreenBlue(void*arg){
  while (1){
     
      // Wait until a semaphore is released
      xSemaphoreTake(semGreenBlue, portMAX_DELAY);
      
      //Turn the Green and Blue LEDs on.
      SerialUSB.println("Turning the Green and Blue LEDs on");
      pd_rgb_led(PD_TIEL);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
      
      //Turn the Green and Blue LEDs off.
      SerialUSB.println("Turning the Green and Blue  LEDs off");
      pd_rgb_led(PD_OFF);
    
      //Sleep for 500 milliseconds
      vTaskDelay((500L* configTICK_RATE_HZ)/ 1000L);
    
      //Done with the thread.Release Semaphore
      SerialUSB.println("Done");
      xSemaphoreGive(semRedGreenBlue);
  }
}


/*
 * ThreadRedBlue, turn the Red, Green and Blue LEDs on for 500 milliseconds 
 */
// Declare the thread function for thread 1.
static void ThreadRedGreenBlue(void*arg){
  while (1){
      xSemaphoreTake(semRedGreenBlue, portMAX_DELAY);
    
      //Turn on white led.
      SerialUSB.println("Turning on white LED");
      pd_rgb_led(PD_WHITE);
    
      //sleep for 500ms
      vTaskDelay((500L * configTICK_RATE_HZ) / 1000L);
    
      //turn off
      SerialUSB.println("Turning off white LED");
      pd_rgb_led(PD_OFF);
    
      //sleep for 500ms
      vTaskDelay((500L * configTICK_RATE_HZ) / 1000L);
    
      //done with thread
      SerialUSB.println("Done");
      xSemaphoreGive(semRed);
    }
}
//------------------------------------------------------------------------------
void setup() {
  SerialUSB.begin(9600);

  while(!SerialUSB);
  SerialUSB.println("STARTING IMPLEMENTATION \n");
  SerialUSB.flush();
  
  SerialUSB.println(configMINIMAL_STACK_SIZE);
  SerialUSB.println(configTICK_RATE_HZ);

  pd_rgb_led_init();

  
  // initialize semaphore
  semRed = xSemaphoreCreateCounting(1, 0);
  semGreen = xSemaphoreCreateCounting(1, 0);
  semBlue= xSemaphoreCreateCounting(1, 0);
  semRedGreen = xSemaphoreCreateCounting(1, 0);
  semRedBlue = xSemaphoreCreateCounting(1, 0);
  semGreenBlue = xSemaphoreCreateCounting(1, 0);
  semRedGreenBlue = xSemaphoreCreateCounting(1, 0);

  portBASE_TYPE s1, s2, s3, s4, s5, s6, s7;
    // create task at priority two
    s1 = xTaskCreate(ThreadRed, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    s2 = xTaskCreate(ThreadGreen, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    s3 = xTaskCreate(ThreadBlue, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    s4 = xTaskCreate(ThreadRedGreen, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    s5 = xTaskCreate(ThreadRedBlue, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    s6 = xTaskCreate(ThreadGreenBlue, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    s7 = xTaskCreate(ThreadRedGreenBlue, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  xSemaphoreGive(semRed);
  // start scheduler
  vTaskStartScheduler();
}
//------------------------------------------------------------------------------
// WARNING idle loop has a very small stack (configMINIMAL_STACK_SIZE)
// loop must never block
void loop() {
  // Not used.
}
