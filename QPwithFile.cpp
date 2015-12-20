#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "QuadProg++.hpp"

int QPwithFile(std::string G_filename,
	       std::string g0_filename,
	       const int n){
  std::ifstream ifs;
  Matrix<double> G, CE, CI;
  Vector<double> g0, ce0, ci0, x;
  int m = 0, p = 0;
  double sum = 0.0;
  char ch;
  
  G.resize(n, n);
  {
    ifs.open(G_filename.c_str(), std::ios::in);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	ifs >> G[i][j];
      }
    }
    ifs.close();
  }
	
  g0.resize(n);
  {
    ifs.open(g0_filename.c_str(), std::ios::in);
    for(int i = 0; i < n; i++){
      ifs >> g0[i];
    }
    ifs.close();
  }

  m = 0;
  CE.resize(n, m);
  ce0.resize(m);

  p = 0;
  CI.resize(n, p);
  ci0.resize(p);

  x.resize(n);

  std::cerr << "f: " << solve_quadprog(G, g0, CE, ce0, CI, ci0, x) << std::endl;
  std::cerr << "x: " << x << std::endl;
  for (int i = 0; i < n; i++){
    std::cout << x[i] << std::endl;
  }
#if 0  
  /* FOR DOUBLE CHECKING COST since in the solve_quadprog routine the matrix G is modified */
	
  {
    std::istringstream is("4, -2,"
			  "-2, 4 ");
	
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	is >> G[i][j] >> ch;
  }
	
  std::cout << "Double checking cost: ";
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      sum += x[i] * G[i][j] * x[j];
  sum *= 0.5;	
  
  for (int i = 0; i < n; i++)
    sum += g0[i] * x[i];
  std::cout << sum << std::endl;

#endif
  return 0;
}


int main (int argc, char *const argv[]) {
  std::string G_filename = argv[1];
  std::string g0_filename = argv[2];
  int n = atoi(argv[3]);

  QPwithFile(G_filename, g0_filename, n);

  return 0;
}


