#include <stdio.h>
#include "driver/gpio.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "jsno4t_sonar.h"

uint8_t triger_pin= GPIO_NUM_22;
uint8_t echo_pin= GPIO_NUM_23;

// to send the signal
 /*float sonar_measure(uint32_t triger_pin, uint32_t echo_pin)
 {
    
    gpio_set_direction(triger_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(echo_pin,GPIO_MODE_INPUT);
    
    while(1)
    {
        gpio_set_level(triger_pin,1);  // triggring signsl is given
        vTaskDelay(pdMS_TO_TICKS(10));  /// delay for 10us
        gpio_set_level(triger_pin,0);

        // wait for the echo pin to high
        while(gpio_get_level(echo_pin)==0);
        uint32_t start_time = esp_timer_get_time();  // starting the time
        // wait for the echo go low
        while(gpio_get_level(echo_pin)==1);
        uint32_t end_time = esp_timer_get_time(); 
        uint32_t high_time_s =end_time-start_time;
        //float high_time_sec=high_time_s/1000000; // converts to seconds
        float speed_sound=0.034;
        float test_distance=((high_time_s*speed_sound)/2); // convert to cm 
        vTaskDelay(pdMS_TO_TICKS(1000));

        return test_distance;

    }


 }*/
 /*float object_detection(uint8_t triger_pin, uint8_t echo_pin)
 {
    
    gpio_set_direction(triger_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(echo_pin,GPIO_MODE_INPUT);

   
    
   while(1)
    {
        gpio_set_level(triger_pin,1);  // triggring signsl is given
        vTaskDelay(pdMS_TO_TICKS(10));  /// delay for 10us
        gpio_set_level(triger_pin,0);

        // wait for the echo pin to high
        while(gpio_get_level(echo_pin)==0);
        uint8_t start_time = esp_timer_get_time();  // starting the time
        // wait for the echo go low
        while(gpio_get_level(echo_pin)==1);
        uint8_t endtime = esp_timer_get_time(); 
        uint8_t hightime_s =end_time-start_time;
        float hightimesec=hightimes/1000000; // converts to seconds
        float testdistance=(hightimesec*340)/2*100; // convert to cm 
        if(testdistance > 20 && testdistance < 600)
        {
            return true;
        }
        else 
        {
            return false;

        }
    }



 }*/





void app_main(void)
{
    
    while(1)
    {
        float object_distance= sonar_measure(triger_pin,echo_pin);
        printf("Distance: %f cm\n",object_distance);

    }
    
    //bool test_distance= object_detection(triger_pin,echo_pin);





}
