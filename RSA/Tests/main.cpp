#include "testing.h"

int main(void){
  srand (time(NULL));
  
  //testing for random plain text files
  int max_iter = 10;
  std::cout << "Start testing..." << "\n";
  std::cout << "Number of correct results: " << testing(max_iter) << " out of " << max_iter;

  return 0;
}