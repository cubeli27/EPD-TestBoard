#include <Arduino.h>

#define BUZZER_PIN 10
#define PWM_CHANNEL 0
#define PWM_FREQ 2000
#define PWM_RESOLUTION 8

uint32_t duty50 = 128;   // 50% duty (128/255)

void setup() {
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(BUZZER_PIN, PWM_CHANNEL);
    ledcWrite(PWM_CHANNEL, 0);
}

void loop() {

    // Turn buzzer ON (4 kHz, 50%)
    ledcWrite(PWM_CHANNEL, duty50);

    delay(1000);

    // Turn buzzer OFF
    ledcWrite(PWM_CHANNEL, 0);

    delay(3000); 
}
