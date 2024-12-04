#include <kipr/wombat.h>

// Wheels & Motors
const int frontLeftWheel    = 3;
const int frontRightWheel   = 1;
const int backLeftWheel     = 2;
const int backRightWheel    = 0;

// Arm
const int hingeServo        = 0; // high values is pi radians, low values pi 3 radians
const int topServo          = 2; // 0 is down 45 degrees, 2000 is 60 degrees in the unit circle

// Sensors
const int frontLeftTape = 1;
const int frontRightTape = 0;

// Button
const int frontLeftButton = 1;
const int frontRightButton = 0;
const int backLeftButton = 3;
const int backRightButton = 2;

const int whiteTapeValue = 3500; // HIGHER IS DARKER

void closeClaw();
void openClaw();
void calibration();
void resetMotors();
void measureDistances();
void yIncrease(int distance);
void xIncrease(int distance);
void yDecrease(int distance);
void xDecrease(int distance);
void rotateLeft(int time);
void rotateRight(int time);
void calibrateTape();
void startArm();
void upArm();

int main()
{
    startArm(); // set values future me btw
    set_servo_position(hingeServo, 1730);
    set_servo_position(topServo, 1300);

   	msleep(500);
    // yDecrease(10);
    xIncrease(450);
    set_servo_position(hingeServo, 1870);
    msleep(1000);
    set_servo_position(topServo, 200);
    upArm();
    msleep(500);
    motor(frontLeftWheel, -15);
    motor(backRightWheel, -15);
    motor(frontRightWheel, -15);
    motor(backLeftWheel, -15);
    msleep(500);
    set_servo_position(hingeServo, 1750);
    msleep(20);
    set_servo_position(hingeServo, 1700);
    msleep(20);
    set_servo_position(hingeServo, 1650);
    msleep(20);
    set_servo_position(hingeServo, 1600);
    msleep(20);
    set_servo_position(hingeServo, 1550);
    msleep(1550);
    set_servo_position(hingeServo, 1450);
    ao();
    msleep(300);
    set_servo_position(hingeServo, 1300);
    msleep(300);
    xDecrease(150);
    rotateLeft(1650);
    xIncrease(100);
    msleep(300);
    yDecrease(380);
    msleep(50);
    ao();
    set_servo_position(hingeServo, 1400);
    msleep(500);
    set_servo_position(topServo, 1300);
    msleep(500);
    printf("cooking");
    msleep(3000);
    set_servo_position(topServo, 1800);
    msleep(500);
    set_servo_position(hingeServo, 1730)
    msleep(300);
    ao();
    yIncrease(380);
    msleep(300);
    xDecrease(100);
    rotateRight(1650);
    yDecrease(100);
    msleep(500);
    xIncrease(30);
    set_servo_position(hingeServo, 1300);
    msleep(500);
    set_servo_position(topServo, 200);
    upArm();
    msleep(500);
    motor(frontLeftWheel, -15);
    motor(backRightWheel, -15);
    motor(frontRightWheel, -15);
    motor(backLeftWheel, -15);
    msleep(500);
    set_servo_position(hingeServo, 1750);
    msleep(20);
    set_servo_position(hingeServo, 1700);
    msleep(20);
    set_servo_position(hingeServo, 1650);
    msleep(20);
    set_servo_position(hingeServo, 1600);
    msleep(20);
    set_servo_position(hingeServo, 1550);
    msleep(1550);
    set_servo_position(hingeServo, 1450);
    ao();
    msleep(300);
    set_servo_position(hingeServo, 1300);
    msleep(5000);
    //  first stove

}


void closeClaw() {
    set_servo_position(topServo, 350);
    msleep(1500);
}

void openClaw() {
    set_servo_position(topServo, 1300);
    msleep(1500);
}

void startArm() {
    enable_servos();
    set_servo_position(hingeServo, 1800);
    set_servo_position(topServo, 1300);
}

void upArm() {
    set_servo_position(hingeServo, 1300);
    
}

void calibration() {
    resetMotors();

    (digital(0) == 0) ? printf("Left is stronger!\n") : printf("Right Button Pressed!\n");
    if (digital(0) == 0) {
        freeze(0);
        gmpc(0);
    }
    else {
    	freeze(1);
    	gmpc(1);
    }
    ao();
    printf("Right: %d, Left: %d\n", gmpc(0), gmpc(1));

}

void resetMotors() {
    cmpc(frontLeftWheel);
    cmpc(frontRightWheel);
    cmpc(backLeftWheel);
    cmpc(backRightWheel);
    msleep(50);
}

void measureDistances() {

}

void yIncrease(int distance) {
    motor(frontLeftWheel, 100);
    motor(backRightWheel, 100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void xIncrease(int distance) {
    motor(frontLeftWheel, 100);
    motor(backRightWheel, 100);
    motor(frontRightWheel, 100);
    motor(backLeftWheel, 100);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void yDecrease(int distance) {
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, 100);
    motor(backLeftWheel, 100);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void xDecrease(int distance) {
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void rotateLeft(int time) {
    motor(frontLeftWheel, 0);
    motor(backRightWheel, 0);
    motor(frontRightWheel, 100);
    motor(backLeftWheel, -100);
    msleep(time);
    ao();
}

void rotateRight(int time) {
    motor(frontLeftWheel, 0);
    motor(backRightWheel, 0);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, 100);
    msleep(time);
    ao();
}

void calibrateTape() {
    while ((digital(frontLeftTape) < 3000) && (digital(frontRightTape) < 3000)) {
        motor(frontLeftWheel, 10);
        motor(backRightWheel, 10);
        motor(frontRightWheel, 10);
        motor(backLeftWheel, 10);
        msleep(10);
        ao();
    }
    msleep(500);
    while (digital(frontLeftTape) < 3500) {
        freeze(frontRightWheel);
        freeze(backRightWheel);
        motor(frontLeftWheel, 10);
        motor(backLeftWheel, 10);
        printf("%d", digital(frontLeftTape));
        printf("%d", digital(frontRightTape));
        msleep(5);
    }
    while (digital(frontRightTape) < 3500) {
        freeze(frontLeftWheel);
        freeze(backLeftWheel);
        motor(frontRightWheel, 10);
        motor(backRightWheel, 10);
        printf("%d", digital(frontLeftTape));
        printf("%d", digital(frontRightTape));
        msleep(5);
    }
    ao();
    printf("%d", gmpc(0));
}
