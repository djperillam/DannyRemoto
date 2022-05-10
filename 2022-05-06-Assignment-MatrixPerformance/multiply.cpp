#include <Eigen/Dense>
#include <chrono>
#include <iostream>

double multiply(int size);

int main(int argc, char **argv) {
  int N;
  const int M = atoi(argv[1]);
  const int S = atoi(argv[2]);
  const int R = atoi(argv[3]); // Reps
  double sum = 0, sum2 = 0;
  double time = 0;
  for (int rep = 0; rep < R; ++rep) {
    srand(S+rep);
    time = multiply(N);
    sum  += time;
    sum2 += time*time;
  }
  double mean = sum/R;
  double sigma = std::sqrt(R*(sum2/R - mean*mean)/(R-1));
  
  std::cout.setf(std::ios::scientific); std::cout.precision(15);
  std::cout << N*N << "\t" << mean << "\t" << sigma << std::endl;

  return 0;
}

double  multiply(int size) {
  // create matrices
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);

  auto start = std::chrono::steady_clock::now();
  auto C{A * B};        // MULTIPLY
  double tmp = C(0, 0); // use the matrix to make eigen compute it
  auto end = std::chrono::steady_clock::now();

  std::clog << tmp << std::endl; // use the matrix to make eigen compute it

  std::chrono::duration<double> elapsed_seconds = end - start;
  return elapsed_seconds.count();
}
