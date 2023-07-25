#include "jsno4t_sonar.h"


float sonar_measure(uint32_t triger_pin, uint32_t echo_pin)
{
    gpio_set_direction(triger_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(echo_pin, GPIO_MODE_INPUT);

    while (1)
    {
        gpio_set_level(triger_pin, 1);  // triggering signal is given
        vTaskDelay(pdMS_TO_TICKS(10));  /// delay for 10us
        gpio_set_level(triger_pin, 0);

        // wait for the echo pin to go high
        while (gpio_get_level(echo_pin) == 0);
        uint32_t start_time = esp_timer_get_time();  // starting the time

        // wait for the echo to go low
        while (gpio_get_level(echo_pin) == 1);
        uint32_t end_time = esp_timer_get_time();
        uint32_t high_time_us = end_time - start_time;
        float speed_sound = 0.034;
        float test_distance = ((high_time_us * speed_sound) / 2); // convert to cm
        vTaskDelay(pdMS_TO_TICKS(1000));

        return test_distance;
    }
}

