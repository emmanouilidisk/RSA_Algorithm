#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "boost_1_66_0/boost/multiprecision/cpp_int.hpp"
#include <iostream>
#include <fstream>
using big_int = boost::multiprecision::cpp_int;

class RSA {
  int privateKey;
  int publicKey;
  int modulo;
  bool PrimalityTest(int IterNum, int i);
  big_int ModularExponentiation(big_int a, int m, int n);
  int ExtendedGCD(int a, int b);
  public:
  RSA();
  void Encryption(std::ifstream& inp, std::string plainFile, std::ofstream& out, std::string cipherFile);
  void Decryption(std::ifstream& inp, std::string cipherFile, std::ofstream& out, std::string decipherFile);
};

RSA::RSA(){
    int p, q;
    int phi_n;
    do {
      do
      p = rand();
      while (p % 2 == 0);
    } while (!PrimalityTest(20, p));

  do {
    do
      q = rand();
    while (q % 2 == 0);
  } while (!PrimalityTest(20, q));

  modulo = p * q;
  phi_n = (p - 1) * (q - 1);

  do
    publicKey = rand() % (phi_n - 2) + 2; // 1 < publicKey < phi_n
  while (std::__gcd(publicKey, phi_n) != 1);

  privateKey = ExtendedGCD(phi_n, publicKey);
}

bool RSA::PrimalityTest(int IterNum, int n){
  if (n%3 == 0|| n%5 == 0|| n%7 == 0||n%11 == 0)
    return false;
  for (int j = 0; j < IterNum; ++j){
    int d = n - 1;
    int k = 0;
    big_int T;
    // select a random base
    int a = 2 + rand() % (n - 4); 

    // Find d,k such that n = (2^k)*d + 1
    while (d % 2 == 0) {
      k++;
      d = d / 2;
    }

    // Miller-Rabin test
    T = ModularExponentiation(a, d, n);

    if (T == 1 || T == n - 1)
      return true;

    for (int i = 0; i < k; i++) {
      T = ModularExponentiation(T, 2, n);
      if (T == 1)
        return false;
      if (T == n - 1)
        return true;
    }
  }
  return false;
}

big_int RSA::ModularExponentiation(big_int base, int exponent, int modulus){
  int r;
  big_int y = 1;

//Right-to-left binary method
  while (exponent > 0) {
    r = exponent % 2;
    if (r)
      y = y * base % modulus;
    base = base * base % modulus;
    exponent = exponent>>1;
  }
  return y;
}

int RSA::ExtendedGCD(int a, int b){
  //ax + by = gcd(a,b)
  int inv, x = 0, y = 1;
  int q, temp, tempA = a;

  while (b > 0) {
    q = a / b; //Do not remove q
    temp = a % b;
    a = b;
    b = temp;

    temp = x - q * y;
    x = y;
    y = temp;
  }

  if (a == 1)
    inv = x;

  if (inv < 0)
    inv = inv + tempA;

  return inv;
}

void RSA::Encryption(std::ifstream& inp, std::string plainFile, std::ofstream& out, std::string cipherFile){
  inp.open(plainFile);
  // destroy contents of these files (from previous runs, if any)
  out.open(cipherFile);
  out.close();
  // Check if files can be opened.
  if (!inp) {
    printf("Error opening Source File.\n");
    exit(1);
  }

  out.open(cipherFile);
  if (!out) {
    printf("Error opening Destination File.\n");
    exit(1);
  }
  
  while (true) {
    char ch;
    inp.read(&ch,1);
    if (inp.eof())
      break;
    int value = toascii(ch);
    big_int cipher;
	  cipher = ModularExponentiation(value,publicKey , modulo);
    out << cipher << " ";
  }
  
  inp.close();
  out.close();
}

void RSA::Decryption(std::ifstream& inp, std::string cipherFile, std::ofstream& out, std::string decipherFile){
  inp.open(cipherFile);
  // destroy contents of these files (from previous runs, if any)
  out.open(decipherFile);
  out.close();

  // Check if files can be opened.
  if (!inp) {
    std::cout << "Error opening Cipher Text.\n";
    exit(1);
  }

  out.open(decipherFile);
  if (!out) {
    std::cout << "Error opening File.\n";
    exit(1);
  }
  
  while (1) {
    big_int cipherNum;
    std::stringstream ss;
    big_int decipher;
    int temp;
    
    if (!(inp >> cipherNum))
      break;

    decipher = ModularExponentiation(cipherNum, privateKey, modulo);
    ss << decipher;
    ss >> temp;
    out << (char)temp;
  }
  out.close();
  inp.close();
}

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





