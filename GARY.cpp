#include <kipr/wombat.h>

// Wheels & Motors
const int frontLeftWheel    = 3;
const int frontRightWheel   = 1;
const int backLeftWheel     = 2;
const int backRightWheel    = 0;

// Arm
const int hingeServo        = 0; // high values is pi radians, low values pi 3 radians
const int topServo          = 1; // 0 is down 45 degrees, 2000 is 60 degrees in the unit circle

// Sensors
const int frontLeftTape = 1;
const int frontRightTape = 0;

// Button
const int frontLeftButton = 1;
const int frontRightButton = 0;
const int backLeftButton = 3;
const int backRightButton = 2;

const int whiteTapeValue = 3500; // HIGHER IS DARKER

void calibration();
void resetMotors();
void measureDistances();
void yIncrease(int distance);
void xIncrease(int distance);
void yDecrease(int distance);
void xDecrease(int distance);
void rotateLeft();
void rotateRight();
void calibrateTape();

int main()
{
    yDecrease(10);
    xIncrease(500);
    xDecrease(5);
    
    xIncrease(5);
    yIncrease(10);
    xDecrease(15);
    // Yeah top right board
    msleep(500);
    xDecrease(150);
    yDecrease(400);
    xDecrease(60);
    msleep(500);
    //  first stove
    xIncrease(50);
    yIncrease(400);
    xIncrease(150);
    // seasoning
    yDecrease(140);
    yIncrease(10);
    xDecrease(150);
    yDecrease(580);
    xDecrease(70);
    msleep(500);
    // stove
    xIncrease(50);
    yIncrease(600);
    
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

void rotateLeft() {
    motor(frontLeftWheel, -100);
    motor(backRightWheel, 100);
    motor(frontRightWheel, 100);
    motor(backLeftWheel, -100);
    msleep(1000);
    ao();
}

void rotateRight() {
    motor(frontLeftWheel, 100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, 100);
    msleep(1000);
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
