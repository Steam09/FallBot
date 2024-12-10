#include <kipr/wombat.h>

//motors
const int frontLeftWheel    = 3;
const int frontRightWheel   = 1;
const int backLeftWheel     = 2;
const int backRightWheel    = 0;

//servos
const int bottomServo       = 2;
const int topServo          = 0;

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
int slowSpeed = 1000;

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

int abovePVC    = 1450;
int onPVC       = 1750;
int airPos      = 800;

int eyesPos     = 1560;

int closedPos   = 0;
int openPos     = 1200;
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
    driveLeft(15);

    botGuy();
    driveBackwards(30);
    backAlign();
    driveForwards(80);
    rotateRight(85);

    greenCube();
    driveBackwards(30);
    backAlign();
    driveForwards(80);
    driveRight(15);
    rotateRight(85);
    backAlign();
    
    leftSeasoning();

}

void rightSeasoning() {
    
    servoPos(bottomServo, airPos, 20);
    servoPos(topServo, openPos, 40);
    msleep(500);

    driveForwards(350);
    frontAlign(); // hit the wall
    printf("wall");
    driveBackwards(36);

    servoPos(bottomServo, abovePVC, 50);
    msleep(200);
    driveForwards(14); //A 11 instead of 14
    servoPos(bottomServo, onPVC, 50);
    driveForwards(8);
    driveRight(4);
    servoPos(topServo, closedPos, 50);
    msleep(500);
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    servoPos(bottomServo, airPos, 50);
    msleep(300);
    ao();

    driveBackwards(350);
    backAlign(); // go back to starting position
    driveForwards(20);
    driveLeft(10);
    rotateLeft(90);
    driveLeft(60);
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
    msleep(500);
    servoPos(topServo, openPos, 40);
    msleep(500);
    driveForwards(150);
    frontAlign(); // hit the wall
    driveBackwards(35);

    servoPos(bottomServo, onPVC, 20);
    servoPos(topServo, closedPos, 40);
    servoPos(bottomServo, airPos, 30);
    
    servoPos(bottomServo, airPos, 20);
    servoPos(topServo, openPos, 40);
    msleep(500);

    driveForwards(350);
    frontAlign(); // hit the wall
    printf("wall");
    driveBackwards(36);

    servoPos(bottomServo, abovePVC, 50);
    msleep(200);
    driveForwards(13); //A 11 instead of 14
    servoPos(bottomServo, onPVC, 50);
    driveForwards(8);
    servoPos(topServo, closedPos, 50);
    motor(frontLeftWheel, -100);
    motor(backRightWheel, -100);
    motor(frontRightWheel, -100);
    motor(backLeftWheel, -100);
    servoPos(bottomServo, airPos, 50);
    msleep(300);
    ao();

    driveBackwards(350);
    backAlign(); // go back to starting position
}

void botGuy() {

    servoPos(bottomServo, airPos, 30);
    driveForwards(350);
    frontAlign();

    driveBackwards(60); //A 60 instead of 50
    //servoPos(topServo, openPos, 40);
    servoPos(bottomServo, eyesPos, 40);
    //driveRight(20); //A add/////////////
    driveForwards(20);
    servoPos(topServo, closedPos, 40);
    servoPos(bottomServo, airPos, 20);

    driveBackwards(300);
    backAlign();
    driveForwards(30);
    driveLeft(30);
    rotateLeft(90);
    driveLeft(10);//A added
    driveForwards(30);
    frontAlign();

    driveBackwards(20);
    servoPos(bottomServo, abovePVC, 20);
    servoPos(topServo, openPos, 40);
    servoPos(bottomServo, airPos, 30);
    servoPos(topServo, closedPos, 40);
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
    msleep(500);
    servoPos(topServo, greenclosedPos, 30);
    msleep(500);
    servoPos(bottomServo, airPos, 50);
    msleep(500);
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
    msleep(500);
    disable_servo(bottomServo);
}

void frontAlign() {
    move_at_velocity(frontLeftWheel, slowSpeed);
    move_at_velocity(frontRightWheel, slowSpeed);
    move_at_velocity(backLeftWheel, slowSpeed);
    move_at_velocity(backRightWheel, slowSpeed);
    while ((digital(frontLeftButton) == 0) || (digital(frontRightButton) == 0)) {
        msleep(5);
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
        msleep(5);
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
    msleep(500);
    set_servo_position(topServo, 1300);
    msleep(500);
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
