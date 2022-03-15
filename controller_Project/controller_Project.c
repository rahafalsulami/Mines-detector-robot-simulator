
#include <stdio.h>
#include <stdlib.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <webots/robot.h>

#define TIME_STEP 64

int i=0;
int j=0;

int main(int argc, char **argv) {
 WbDeviceTag ds0;
WbDeviceTag ds1;
WbDeviceTag ds2;
WbDeviceTag acds;

  // init webots stuff
  wb_robot_init();
  /* get a handler to the distance sensors. */
  ds0 = wb_robot_get_device("ds0");
   ds1 = wb_robot_get_device("ds1");
    ds2 = wb_robot_get_device("ds2");
     acds = wb_robot_get_device("acds");
    //very TIME_STEP millisecond. */
  wb_distance_sensor_enable(ds0, TIME_STEP);
  wb_distance_sensor_enable(ds1, TIME_STEP);
  wb_distance_sensor_enable(ds2, TIME_STEP);
  wb_distance_sensor_enable(acds, TIME_STEP);


  // get devices
  
  WbDeviceTag front_left_wheel = wb_robot_get_device("front left wheel");
  WbDeviceTag front_right_wheel = wb_robot_get_device("front right wheel");
  WbDeviceTag back_left_wheel = wb_robot_get_device("back left wheel");
  WbDeviceTag back_right_wheel = wb_robot_get_device("back right wheel");


  // init motors
  wb_motor_set_position(front_left_wheel, INFINITY);
  wb_motor_set_position(front_right_wheel, INFINITY);
  wb_motor_set_position(back_left_wheel, INFINITY);
  wb_motor_set_position(back_right_wheel, INFINITY);

  // init speed for each wheel
  double back_left_speed = 3, back_right_speed = 3;
  double front_left_speed = 3, front_right_speed = 3;
  wb_motor_set_velocity(front_left_wheel, front_left_speed);
  wb_motor_set_velocity(front_right_wheel, front_right_speed);
  wb_motor_set_velocity(back_left_wheel, back_left_speed);
  wb_motor_set_velocity(back_right_wheel, back_right_speed);

  
  // control loop
  while (wb_robot_step(TIME_STEP) != -1) {
  
   const double ds0_value = wb_distance_sensor_get_value(ds0);
    const double ds1_value = wb_distance_sensor_get_value(ds1);
     const double ds2_value = wb_distance_sensor_get_value(ds2);
     const double acds_value = wb_distance_sensor_get_value(acds);
     
     
     
   if (ds0_value < 605 ) {
        back_left_speed = 0.0;
        back_right_speed = 0.0;
        front_left_speed = 0.0;
        front_right_speed = 0.0;
        
      }
      else if (ds1_value < 605 ) {
        back_left_speed = 0.0;
        back_right_speed = 0.0;
        front_left_speed = 0.0;
        front_right_speed = 0.0;
        }
      else if (ds2_value < 605 ) {
        back_left_speed = 0.0;
        back_right_speed = 0.0;
        front_left_speed = 0.0;
        front_right_speed = 0.0;
         }
         
       else {
       
if (j>0) {
j--;
 back_left_speed = -3;
 back_right_speed = 3;
 front_left_speed = -3;
 front_right_speed = 3;
}     
   
else {
       if (acds_value < 900 ) {
    j=50;
        
        }
        
        
         
       
       
        back_left_speed = 3;
        back_right_speed = 3;
        front_left_speed = 3;
        front_right_speed = 3;
       
     
   }
   
}
   
   
    // set actuators
    wb_motor_set_velocity(front_left_wheel, front_left_speed);
    wb_motor_set_velocity(front_right_wheel, front_right_speed);
    wb_motor_set_velocity(back_left_wheel, back_left_speed);
    wb_motor_set_velocity(back_right_wheel, back_right_speed);

   }
  

 
  wb_robot_cleanup();

  return 0;
}
