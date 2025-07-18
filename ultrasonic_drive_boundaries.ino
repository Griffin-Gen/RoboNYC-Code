float robot_speed = 0.5;
float backBoundDist = 20;
float leftBoundDist = 20;

float dist_front;
float dist_back;
float dist_left;
float dist_right;

float slow_down_factor;
float drive_ang;

bool opponent_block_x = false;
bool opponent_block_y = false;

void setDriveBounds(float frontBoundDist, float leftBoundDist, float rightBoundDist, float backBoundDist) {
  // Closer it is to wall, the higher the speed correction is (will slow down)
  float robot_radius = 11;
  float xDrive;
  float yDrive;

  if (opponent_block_x || opponent_block_y) {
    if (opponent_block_x) {
      xDrive = sin((drive_ang / 180) * 3.14159) * robot_speed;
      yDrive = constrain(cos((drive_ang / 180) * 3.14159) * robot_speed, (((backBoundDist + robot_radius) - (float)dist_back) / backBoundDist), (((float)dist_front / frontBoundDist)));
      robot_speed = slow_down_factor * robot_speed;
    } if (opponent_block_y) {
      yDrive = cos((drive_ang / 180) * 3.14159) * robot_speed;
      xDrive = constrain(sin((drive_ang / 180) * 3.14159) * robot_speed, (((leftBoundDist + robot_radius) - (float)dist_left) / leftBoundDist), (((float)dist_right - (robot_radius + rightBoundDist)) / rightBoundDist));  // increase integer numerator
      robot_speed = slow_down_factor * robot_speed;
    }
  } else {
    xDrive = constrain(sin((drive_ang / 180) * 3.14159) * robot_speed, (((leftBoundDist + robot_radius) - (float)dist_left) / leftBoundDist), (((float)dist_right - (robot_radius + rightBoundDist)) / rightBoundDist));  // increase integer numerator
    yDrive = constrain(cos((drive_ang / 180) * 3.14159) * robot_speed, (((backBoundDist + robot_radius) - (float)dist_back) / backBoundDist), (((float)dist_front / frontBoundDist)));                                    // Stops when something in front, but never go backwards(((float)dist_front-30) / 19));
  }

  xDrive = constrain(xDrive, -robot_speed, robot_speed);
  yDrive = constrain(yDrive, -robot_speed, robot_speed);
  // if grayscale then yDrive = 0
  robot_speed = sqrt((xDrive * xDrive) + (yDrive * yDrive));
  drive_ang = (atan2(xDrive, yDrive) * RAD_TO_DEG);  // inverse tangent that preserves the sign

}
