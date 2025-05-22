#include<Servo.h>
#include<math.h>

Servo servos[10];
const int servoPins[10] = {9, 10, 5, 6, 3, 4, 2, 7, 8, 11};

float angleOffset = 90;     
float amplitude = 40;       
float frequency = 1.5;      
float phaseDiff = PI / 5.0; 

void setup() {
for (int i = 0; i < 10; i++) {
servos[i].attach(servoPins[i]);
}
}

void loop() {
float t = millis() / 1000.0; 


for (int i = 0; i < 10; i++) {
    float phase = i * phaseDiff;
    
    float angle = angleOffset + amplitude * sin(2 * PI * frequency * t + phase);
    angle = constrain(angle, 0, 180); // Ensure valid servo angle
    servos[i].write(angle);
}
delay(5); 


}
