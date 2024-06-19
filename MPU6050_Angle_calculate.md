To calculate roll, pitch, and yaw angles using the MPU6050 sensor, we need to understand the data provided by the accelerometer and gyroscope within the sensor. The MPU6050 provides raw data for acceleration along the X, Y, and Z axes and angular velocity (rate of rotation) around these axes. Here's how you can calculate these angles:

Roll and Pitch Calculation
Roll and pitch angles can be directly calculated from the accelerometer data using trigonometric functions. The accelerometer measures the gravitational force acting on the sensor, which can be used to determine the orientation of the sensor.

Roll (rotation around the X-axis)
Formula: 
![image](https://github.com/VaishabhJalmi/MPU6050_Sensor/assets/69182306/458405bf-6a8b-444c-9b48-6f39f0407220)

This calculates the angle between the Y-axis and the gravitational force vector, indicating the tilt of the sensor around the X-axis.
Pitch (rotation around the Y-axis)
Formula: ![image](https://github.com/VaishabhJalmi/MPU6050_Sensor/assets/69182306/81a03473-b374-448e-962b-95cbe0a5d59a)


This calculates the angle between the X-axis and the gravitational force vector, indicating the tilt of the sensor around the Y-axis.
These calculations assume that the sensor is stationary or moving at constant velocity, so the only acceleration detected is due to gravity.

Yaw Calculation
Yaw (rotation around the Z-axis) is more challenging to calculate using only the MPU6050 because it requires knowing the absolute orientation relative to the Earth's magnetic field, which the MPU6050 alone cannot provide (it lacks a magnetometer). However, a simplified version using just the accelerometer and gyroscope data can be attempted, but it's not as accurate.

To improve the yaw calculation, you would typically need additional sensor data from a magnetometer. However, if you want a basic approximation of yaw from the gyroscope data, you can integrate the angular velocity over time.

Gyroscope Data Integration for Yaw
Formula: ![image](https://github.com/VaishabhJalmi/MPU6050_Sensor/assets/69182306/709e8eba-5810-4fbb-932f-180e9a0963b8)


​
  is the angular velocity around the Z-axis provided by the gyroscope. This involves integrating the gyroscope data over time to get the angle.
