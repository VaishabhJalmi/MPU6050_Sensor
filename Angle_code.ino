#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  // Verify connection
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }
  
  // Calibrate MPU6050
  mpu.CalibrateGyro(6);
  mpu.CalibrateAccel(6);
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  float roll, pitch, yaw;
  static float yaw_angle = 0;  // Accumulated yaw angle
  static unsigned long last_time = 0;  // Time of the last update
  
  // Read raw accel/gyro measurements from device
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert raw data to angles (roll and pitch)
  roll = atan2(ay, az) * 180 / PI;
  pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180 / PI;

  // Calculate time difference for yaw integration
  unsigned long current_time = millis();
  float dt = (current_time - last_time) / 1000.0;  // Convert to seconds
  last_time = current_time;

  // Integrate gyroscope data to get yaw angle
  yaw_angle += gx * dt / 131.0;  // Convert raw gyroscope data to degrees/sec

  // Print angles
  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" Pitch: "); Serial.print(pitch);
  Serial.print(" Yaw: "); Serial.println(yaw_angle);

  delay(500);
}
