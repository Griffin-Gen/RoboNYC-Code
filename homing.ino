// update/adjust values as needed
float loc_x;
float loc_y;
float home_x = 50;
float home_y = 50;

void goHome() {
  float home_delta_x = home_x - loc_x;  // field delta x
  float home_delta_y = home_y - loc_y;  // field delta y
  float home_ang = atan2(home_delta_x, home_delta_y) * RAD_TO_DEG;
  float home_speed = sqrt(sq(home_delta_x) + sq(home_delta_y)) / 150;  // might need to reduce 150, 150 is max pythag dist it can be

  float home_speed_min = 0.5;
  float home_speed_max = 0.6;

  float homing_ang = 0;
  float homing_speed = 0;


  if (sqrt(sq(home_delta_x) + sq(home_delta_y)) < 10) {
    homing_speed = 0;
  } else {
    homing_ang = home_ang;
    homing_speed = constrain(home_speed, home_speed_min, home_speed_max);
  }
  
  // then, drive at homing ang and homing speed
}
