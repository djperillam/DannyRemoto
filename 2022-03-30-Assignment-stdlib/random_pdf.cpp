#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atof(argv[1]);
  const int NSAMPLES = std::atof(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atof(argv[7]);
 
  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  //histogram stuff
  double dx = (xmax - xmin) / nbins;
  std:: vector<int> counting(nbins,0);  // contador en cada subintervalo

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    //counting histogram
    for (int ii = 0; ii < nbins; ii = ii + 1)
      {
      if (r > xmin + ii * dx && r < xmin + (ii + 1) * dx)
      {
	counting[ii]++;
      }
      }
  }
    //print values
    for (int jj = 0; jj < nbins; jj = jj + 1){
      std::cout << jj << "\t" <<   + (xmin + jj * dx + xmin + (jj + 1) * dx) / 2 << "\t" << counting[jj] << "\n";
  }
}
