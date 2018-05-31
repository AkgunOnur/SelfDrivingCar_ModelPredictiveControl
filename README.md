# Model Predictive Control

[//]: # (Image References)
[image1]: ./examples/1.png "Equations"
[image2]: ./examples/result.gif "Results"
![alt text][image2]

## Overview

In this project, Self Driving Car is controlled successfully by Model Predictive Control. The goal of this project is to navigate a track in the simulator, which communicates telemetry and track waypoint data via websocket, by sending steering and acceleration commands back to the simulator. The solution needs to handle 100ms latency, because one may encounter in real-world application. In this work, the IPOPT and CPPAD libraries are utilized to calculate an optimal trajectory and its associated actuation commands in order to minimize error with a third-degree polynomial fit to the given waypoints. The optimization takes into consideration only a short duration's worth of waypoints, and produces a trajectory for that duration based upon a model of the vehicle's kinematics and a cost function based mostly on the vehicle's cross-track error (roughly the distance from the track waypoints) and orientation angle error, with other cost factors included to improve performance

## Controller Design

The kinematic model includes the vehicle's x and y coordinates, orientation angle (psi), and velocity, as well as the cross-track error and psi error (epsi). Actuator outputs are acceleration and delta (steering angle):
![alt text][image1]

N and dt values are optimized by trial-error method. The values chosen for N and dt are 10 and 0.1, respectively. These values mean that the optimizer is considering a one-second duration in which to determine a corrective trajectory.

The waypoints are transformed to the vehicle's perspective. This simplifies the process to fit a polynomial to the waypoints because the vehicle's x and y coordinates are now at the origin and the orientation angle is zero.

The original kinematic equations depend on the actuations from the previous timestep, but with a delay of 100ms. The actuations are applied another timestep later in order to solve latency problem. Also, in addition to the cost functions suggested before (penalizing cte, epsi, velocity error, delta, acceleration, change in delta, and change in acceleration) an extra penalizing term, which is a combination of velocity and delta, is added. According to the simulation results, the controller is promising.

## Prerequisites

The project has the following dependencies :

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.

* **Ipopt and CppAD:** Please refer to [this document](https://github.com/udacity/CarND-MPC-Project/blob/master/install_Ipopt_CppAD.md) for installation instructions.
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page). This is already part of the repo so you shouldn't have to worry about it.
* Simulator. You can download these from the [releases tab](https://github.com/udacity/self-driving-car-sim/releases).
* Not a dependency but read the [DATA.md](./DATA.md) for a description of the data sent back from the simulator.


## Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./mpc`.
