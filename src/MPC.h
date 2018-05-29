#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

#define w_cte 5000
#define w_epsi 5000
#define w_v 10;
#define w_delta 5
#define w_a 15
#define w_delta_d 200000
#define w_a_d 10

#define delta_bound 0.436332
#define a_bound 1.0
#define bound 1.0e19


using namespace std;

class MPC {
 public:
  MPC();

  virtual ~MPC();

  // Solve the model given an initial state and polynomial coefficients.
  // Return the first actuatotions.
  vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
  vector<double> mpc_x;
  vector<double> mpc_y;
};

#endif /* MPC_H */
