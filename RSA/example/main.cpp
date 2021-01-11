#include "../src/RSA.h"

int main(void){
  // Create two file handles
  std::ifstream inp;
  std::ofstream out;

  srand (time(NULL));
  RSA rsa;

  // encryption stage
  rsa.Encryption(inp,"plain.txt", out, "cipher.txt");

  // decryption stage
  rsa.Decryption(inp, "cipher.txt", out, "decipher.txt");

  return 0;
}
