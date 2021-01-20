#include"testing.h"

template<typename InputIterator1, typename InputIterator2>
bool range_equal(InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, InputIterator2 last2){
  while(first1 != last1 && first2 != last2){
      if(*first1 != *first2) return false;
      ++first1;
      ++first2;
  }
  return (first1 == last1) && (first2 == last2);
}

bool compare_files(const std::string& filename1, const std::string& filename2){
  std::ifstream file1(filename1);
  std::ifstream file2(filename2);

  std::istreambuf_iterator<char> begin1(file1);
  std::istreambuf_iterator<char> begin2(file2);

  std::istreambuf_iterator<char> end;

  return range_equal(begin1, end, begin2, end);
}

std::string gen_random(const int len) {
  std::string tmp_s;
  static const char alphanum[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
  
  tmp_s.reserve(len);

  for (int i = 0; i < len; ++i) 
    tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
  
  return tmp_s;
}

int testing(int max_iter){
  int correct_results = 0;
  std::ifstream inp;
  std::ofstream out;

  for(int i=0; i<max_iter; i++){
    //create rsa object
    RSA rsa;
    //create random plaintext
    std::ofstream outfile ("plain.txt");
    outfile << gen_random(15) << std::endl;
    outfile.close();

    // encryption stage
    rsa.Encryption(inp,"plain.txt", out, "cipher.txt");

    // decryption stage
    rsa.Decryption(inp, "cipher.txt", out, "decipher.txt");

    //compare plain.txt to decipher.txt
    if(compare_files("plain.txt", "decipher.txt")) correct_results++;

    //print wrong results every 100 tests
    if(i % 10 == 0) std::cout << "Number of correct results so far: " 
      << correct_results << " out of " << i+1 << "\n";
  }
  return correct_results;
}
