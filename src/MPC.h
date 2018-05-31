#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

const double w_cte = 3000;
const double w_epsi = 3000;
const double w_vel = 1;
const double w_delta = 5;
const double w_a = 5;
const double w_delta_a = 700;
const double w_delta_d = 200;
const double w_a_d = 10;

const double delta_bound = 0.436332;
const double a_bound = 1.0;
const double bound = 1.0e19;


using namespace std;

class MPC {
 public:
  MPC();

  virtual ~MPC();

  // Solve the model given an initial state and polynomial coefficients.
  // Return the first actuatotions.
  vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
};

#endif /* MPC_H */
