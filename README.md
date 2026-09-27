# Line Follower Robot

A line follower robot that uses IR sensors and four motors to follow a designed path.
Made to be highly modular and flexible.

## Usage
- configure it however you like, below is a reference of the code.

### Movement
- The pre-programmed motor movements are in the `movement.h` file with functions `forward`, `backward` etc.
- The conditions on when to move are in the `bindings.h` file.
```cpp
    int (*func_ptr)(int, int);
    int l_speed;
    int r_speed;
    char map[5];
    void (*callback)();
```
- The order is as follows:
    1. Function to call when condition is true.
    2. Left speed of the motor (value from 0-255)
    3. Right speed of the motor (value from 0-255)
    4. The condition to check for in the sensor.
    5. A function to call once the main function is done.

### Junction Counting
- The primary file to read is `junction_count.h`
- A junction is a location on the track where the robot has 3 primary movements:
    - forwards
    - left
    - right
- A junction is reached when all the 5 sensors read 0 (meaning all black)
- There is already a sample `switch` statement setup which should be self explanatory.
