#include <kipr/wombat.h>

//motors
const int frontLeftWheel    = 3;
const int frontRightWheel   = 1;
const int backLeftWheel     = 2;
const int backRightWheel    = 0;

//servos
const int bottomServo       = 1;
const int topServo          = 3;

//analog IR ports
const int frontLeftTape     = 1;
const int frontRightTape    = 0;

//digital button ports
const int frontLeftButton   = 1;
const int frontRightButton  = 0;
const int backLeftButton    = 3;
const int backRightButton   = 2;

//analog values
const int whiteTapeValue = 3500;

//motor values
int slowSpeed = 4000;

//functions
void driveRight(int distance);  
void driveForwards(int distance);
void driveLeft(int distance);
void driveBackwards(int distance);
void rotateLeft(int time);
void rotateRight(int time);
void startFunction();
void prestartFunction();
void closeClaw();
void openClaw();

void frontAlign();
void backAlign();

void pickUpSeasonings();

void rightSeasoning();
void leftSeasoning();
void botGuy();
void greenCube();

void servoPos(int port, int endPos, int speed); // higher == faster, 50 max

int abovePVC    = 1600;
int onPVC       = 1700;
int airPos      = 800;

int eyesPos     = 1560;

int closedPos   = 0;
int openPos     = 1500;
int greenclosedPos = 30;

int main() {
    
    prestartFunction();
    startFunction();

    rightSeasoning();

    driveBackwards(40);
    backAlign();
    driveForwards(35);
    driveRight(20);
    rotateRight(88);
    backAlign();
    driveRight(5);

    botGuy();
    driveBackwards(30);
    backAlign();
    driveForwards(80);
    rotateRight(80);
    backAlign();
    
    
    leftSeasoning();
    driveBackwards(165);
	rotateLeft(75);
    driveForwards(900);
    rotateLeft(150);
    driveRight(250);
    frontAlign();

}

void rightSeasoning() {
    
    //servoPos(bottomServo, airPos, 20);
    //servoPos(topServo, openPos, 40);
    //msleep(100);

    motor(frontLeftWheel, 100);
    motor(backRightWheel, 99);
    motor(frontRightWheel, 99);
    motor(backLeftWheel, 100);
    msleep(3500);
    //ao();
    //msleep(300);
    frontAlign(); // hit the wall
    ao();
    msleep(200);
    driveBackwards(20);
    driveRight(60);
    servoPos(bottomServo, onPVC, 50);
    driveForwards(73-11); //A 11 instead of 14
    servoPos(topServo, closedPos, 50);
    msleep(300);
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    servoPos(bottomServo, airPos, 50);
    msleep(100);
    ao();

    driveBackwards(300);
    backAlign(); // go back to starting position
    
    driveForwards(20);
    driveLeft(10);
    rotateLeft(90);
    driveLeft(80);
    driveForwards(50);
    frontAlign(); // hit the side of the stove
    driveBackwards(10);

    servoPos(bottomServo, abovePVC, 20);
    servoPos(topServo, openPos, 40);
    servoPos(bottomServo, airPos, 50);
    //servoPos(topServo, closedPos, 40);
    printf("Put seasoning right in!\n");

}

void leftSeasoning() {
    
    servoPos(bottomServo, airPos, 30);
    msleep(100);
    driveForwards(250);
    frontAlign(); // hit the wall
    driveBackwards(34);
    servoPos(bottomServo, abovePVC, 20);
    driveLeft(84);
    //driveForwards(4);
    servoPos(bottomServo, onPVC, 20);
    driveForwards(6);
    servoPos(topServo, closedPos, 50);
    msleep(300);
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    msleep(20);
    servoPos(bottomServo, airPos, 50);
    msleep(100);
    ao();
	msleep(5000);
    driveBackwards(300);
    ao();
    servoPos(bottomServo, airPos, 20);
    servoPos(topServo, openPos, 40);
    msleep(200);

    driveForwards(350);
    frontAlign(); // hit the wall
    printf("wall");
    driveBackwards(36);

    servoPos(bottomServo, abovePVC, 50);
    msleep(200);
    driveForwards(18); //A 11 instead of 14
    servoPos(bottomServo, onPVC, 50);
    driveForwards(23);
    msleep(100);
    servoPos(topServo, closedPos, 50);
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    servoPos(bottomServo, airPos, 50);
    msleep(300);
    ao();
	frontAlign();
    ao();
    msleep(12000);
}

void botGuy() {

    servoPos(bottomServo, airPos, 30);
    driveForwards(350);
    frontAlign();

    driveBackwards(60); //A 60 instead of 50
    driveLeft(10);
    //servoPos(topServo, openPos, 40);
    servoPos(bottomServo, eyesPos, 40);
    driveForwards(20);
    servoPos(topServo, closedPos, 40);
    driveRight(3);
    servoPos(bottomServo, airPos, 20);

    driveBackwards(300);
    backAlign();
    driveForwards(7);
    driveLeft(30);
    rotateLeft(90);
    servoPos(bottomServo, (airPos + eyesPos) / 2 , 30);
    driveForwards(30);
    rotateRight(20);
    frontAlign();

    driveBackwards(20);
    //servoPos(bottomServo, abovePVC, 20);
    servoPos(topServo, openPos, 40);
    servoPos(bottomServo, 1850, 30);
    msleep(50);
    driveBackwards(10);
    servoPos(bottomServo, airPos, 30);
    printf("Put botguy right in!\n");

}

void greenCube() { //A added all
    driveForwards(200);
    frontAlign(); // hit the wall
    driveBackwards(35);
    rotateLeft(90);
    frontAlign();
    driveLeft(20);
    servoPos(topServo, openPos, 30);
    servoPos(bottomServo, 1950, 30);
    msleep(100);
    servoPos(topServo, greenclosedPos, 30);
    msleep(100);
    servoPos(bottomServo, airPos, 20);
    msleep(100);
    driveBackwards(25);
    driveLeft(350);
   	frontAlign();
    driveBackwards(15);
    servoPos(bottomServo, abovePVC, 30);
    servoPos(topServo, openPos, 30);
}

void pickUpSeasonings() {
    int backUpSpeed = 3;
    move_at_velocity(frontLeftWheel, -1 * backUpSpeed);
    move_at_velocity(frontRightWheel, -1 * backUpSpeed);
    move_at_velocity(backLeftWheel, -1 * backUpSpeed);
    move_at_velocity(backRightWheel, -1 * backUpSpeed);
    enable_servo(bottomServo);
    for (int i = 0; i < 50; i++) {
        set_servo_position(bottomServo, (airPos - onPVC)/50);
        msleep(50);
    }
    set_servo_position(bottomServo, airPos);
    printf("grabbed seasonings!");
    msleep(200);
    disable_servo(bottomServo);
}

void frontAlign() {
    move_at_velocity(frontLeftWheel, slowSpeed);
    move_at_velocity(frontRightWheel, slowSpeed);
    move_at_velocity(backLeftWheel, slowSpeed);
    move_at_velocity(backRightWheel, slowSpeed);
    while ((digital(frontLeftButton) == 0) || (digital(frontRightButton) == 0)) {
        if (digital(frontLeftButton) == 1) {
            mav(0, 100);
            mav(2, 100);
            msleep(2);
        }
        if (digital(frontRightButton) == 1) {
            mav(1, 100);
            mav(3, 100);
            msleep(2);
        }

    }
    ao();
    printf("hit a front wall!\n");
}

void backAlign() {
    move_at_velocity(frontLeftWheel, -1 * slowSpeed);
    move_at_velocity(frontRightWheel, -1 * slowSpeed);
    move_at_velocity(backLeftWheel, -1 * slowSpeed);
    move_at_velocity(backRightWheel, -1 * slowSpeed);
    while ((digital(backLeftButton) == 0) || (digital(backRightButton) == 0)) {
        if (digital(backLeftButton) == 1) {
            mav(0, -100);
            mav(2, -100);
            msleep(2);
        }
        if (digital(backRightButton) == 1) {
            mav(1, -100);
            mav(3, -100);
            msleep(2);
        }
    }
    ao();
    printf("hit a back wall!\n");
}

void driveForwards(int distance) {
    motor(frontLeftWheel, 500);
    motor(backRightWheel, 500);
    motor(frontRightWheel, 500);
    motor(backLeftWheel, 500);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void driveBackwards(int distance) {
    motor(frontLeftWheel, -500);
    motor(backRightWheel, -500);
    motor(frontRightWheel, -500);
    motor(backLeftWheel, -500);
    msleep(distance * 10);
    ao();
    printf("drove backwards %d units", distance);
    msleep(300);
}

void driveLeft(int distance) {
    motor(frontLeftWheel, -500);
    motor(backRightWheel, -500);
    motor(frontRightWheel, 500);
    motor(backLeftWheel, 500);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void driveRight(int distance) {
    motor(frontLeftWheel, 500);
    motor(backRightWheel, 500);
    motor(frontRightWheel, -500);
    motor(backLeftWheel, -500);
    msleep(distance * 10);
    ao();
    msleep(300);
}

void startFunction() {
    //wait_for_light(3);
    //shut_down_in(119);    
}

void prestartFunction() {
    enable_servos();
    set_servo_position(bottomServo, airPos);
    msleep(200);
    set_servo_position(topServo, 1300);
    msleep(200);
    disable_servos();
    ao();   
}

void rotateLeft(int time) {
    motor(frontLeftWheel, 0);
    motor(backRightWheel, 0);
    motor(frontRightWheel, 100);
    motor(backLeftWheel, -100);
    msleep(time*18.333);
    ao();
}

void rotateRight(int time) {
    motor(frontLeftWheel, 0);
    motor(backRightWheel, 0);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, 100);
    msleep(time*18.333);
    ao();
}

void servoPos(int port, int endPos, int speed) {
    enable_servo(port);
    set_servo_position(port, endPos);
    msleep(1000);
    disable_servo(port);
}
