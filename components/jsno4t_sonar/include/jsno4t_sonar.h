#ifndef JSNO4T_SONAR_H
#define JSNO4T_SONAR_H

#include<stdio.h>
#include<stdbool.h>
#include "driver/gpio.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"


//function to measure the distance
float sonar_measure(uint32_t triger_pin, uint32_t echo_pin);

#endif

