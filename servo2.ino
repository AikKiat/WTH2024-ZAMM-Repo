#include <Arduino.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

// Constants
#define SPEED_MODE LEDC_LOW_SPEED_MODE
#define TIMER_NUM LEDC_TIMER_0
#define DUTY_RESOLUTION LEDC_TIMER_13_BIT
#define FREQUENCY 50
#define CLK_CONFIG LEDC_AUTO_CLK
#define CHANNEL LEDC_CHANNEL_0
#define INTR_TYPE LEDC_INTR_DISABLE

#define SERVO_MIN_PULSEWIDTH 500  // Minimum pulse width in microseconds
#define SERVO_MAX_PULSEWIDTH 2500  // Maximum pulse width in microseconds
#define SERVO_MAX_DEGREE 180        // Maximum angle in degrees
#define SERVO_PIN GPIO_NUM_5       // GPIO pin for the servo


void setup_pwm(uint8_t SERVO_PIN) 
{
    // Configure the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = SPEED_MODE,
        .duty_resolution  = DUTY_RESOLUTION, // Ensure correct order
        .timer_num        = TIMER_NUM,
        .freq_hz          = FREQUENCY,
        .clk_cfg          = CLK_CONFIG
    };
    ledc_timer_config(&ledc_timer);

    // Configure the LEDC channel
    ledc_channel_config_t ledc_channel = {
        .gpio_num       = SERVO_PIN,  // Ensure correct order
        .speed_mode     = SPEED_MODE,
        .channel        = CHANNEL,
        .intr_type      = INTR_TYPE,
        .timer_sel      = TIMER_NUM,
        .duty           = 0, // Initial duty cycle
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);
}

void set_servo_angle(int angle) 
{
    // Convert angle to duty cycle
    int pulsewidth = SERVO_MIN_PULSEWIDTH + ((SERVO_MAX_PULSEWIDTH - SERVO_MIN_PULSEWIDTH) * angle) / SERVO_MAX_DEGREE;
    int duty = (pulsewidth * 8192) / 20000; // 8192 is 2^13 for 13-bit resolution
    ledc_set_duty(SPEED_MODE, CHANNEL, duty);
    ledc_update_duty(SPEED_MODE, CHANNEL);
}

void setup() 
{
    Serial.begin(115200);
    setup_pwm(SERVO_PIN); // Initialize PWM
}


bool bmove1 = true;
bool bmove2 =  true;

bool noInput = false;

void move_1()
{
    #define SERVO_MAX_DEGREE 120 
    set_servo_angle(80); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(86); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_2()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(90); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(95); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_3()
{
    #define SERVO_MAX_DEGREE 120 
    set_servo_angle(70); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(80); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_4()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(80); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(90); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_5()
{
    #define SERVO_MAX_DEGREE 120 
    set_servo_angle(80); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(90); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_6()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(90); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(100); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_7()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(75); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(90); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_9()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(70); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(85); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_10()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(85); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(95); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void move_8()
{
    #define SERVO_MAX_DEGREE 120
    set_servo_angle(90); // Move to 60 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));

    #define SERVO_MAX_DEGREE 180
    set_servo_angle(105); // Move to 90 degrees
    delay(1000);
    vTaskDelay(pdMS_TO_TICKS(500));
}

void sweep_glass()
{   
    #define SERVO_MAX_DEGREE 0
    Serial.println("Sweeping Glass!");
    move_1();
    move_2();
    #define SERVO_MAX_DEGREE 180
}

void sweep_metal()
{
    #define SERVO_MAX_DEGREE 0
    Serial.println("Sweeping Metal!");
    move_3();
    move_4();
    #define SERVO_MAX_DEGREE 180
}

void sweep_cardboard()
{
    #define SERVO_MAX_DEGREE 0
    Serial.println("Sweeping Cardboard!");
    move_5();
    move_6();
    #define SERVO_MAX_DEGREE 180
}

void sweep_plastic()
{
    #define SERVO_MAX_DEGREE 0
    Serial.println("Sweeping Plastic!");
    move_7();
    move_8();
    #define SERVO_MAX_DEGREE 180

}

void sweep_trash()
{
    #define SERVO_MAX_DEGREE 0
    Serial.println("Sweepingn Trash!");
    move_9();
    move_10();
    #define SERVO_MAX_DEGREE 180

}


void loop() 
{
    if (Serial.available()>0)
    {
        String incoming = Serial.readStringUntil('\n'); // Read data from the serial port
        incoming.trim(); // Remove any extra whitespace or newline characters
        if (incoming.equalsIgnoreCase("glass"))
        {
            sweep_glass();
        }

        if (incoming.equalsIgnoreCase("metal"))
        {
            sweep_metal();
        }

        if (incoming.equalsIgnoreCase("plastic"))
        {
            sweep_plastic();
        }

        if (incoming.equalsIgnoreCase("cardboard"))
        {
            sweep_cardboard();
        }

        if (incoming.equalsIgnoreCase("trash"))
        {
            sweep_trash();
        }
    }

}
