# MaRS_task2_controlling-motor-remotely
In the beginning, the RemoteXY library is used to create a WiFi connection and link the mobile app with the NodeMCU. The app sends values to two variables: pushSwitch_01 and pushSwitch_02_dir.

In the loop, the code continuously checks these values.

If pushSwitch_01 is 0, the motor is turned OFF by making both motor pins LOW.

If pushSwitch_01 is 1 and pushSwitch_02_dir is 1, the motor rotates in one direction (right).

If pushSwitch_01 is 1 and pushSwitch_02_dir is 0, the motor rotates in the opposite direction (left).

The enablepin is kept HIGH so that the motor driver is always active.

Serial print is used just to display the current state like OFF, LEFT, or RIGHT.

motorpin1 and motorpin2 are connected to the motor driver input pins, and the D3,D4 pin of ESP328266 MICROCONTROLLER.

These decide the direction of rotation.

enablepin is connected to the enable pin of the driver to activate it and to the D5 of the ESP328266 MICROCONTROLLER.

The motor is connected to the output of the motor driver.

External power is used to run the motor.
