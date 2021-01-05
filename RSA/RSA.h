#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "boost_1_66_0/boost/multiprecision/cpp_int.hpp"
#include <iostream>
#include <thread>
#include <future>
#include <fstream>
using big_int = boost::multiprecision::cpp_int;

class RSA {
  big_int privateKey;
  big_int publicKey;
  big_int modulo;
  big_int GenerateNum(int NumOfBits);
  void GeneratePrime(std::promise<big_int> * promObj);
  bool PrimalityTest(int IterNum, big_int n);
  big_int ModularExponentiation(big_int a, big_int m, big_int n);
  big_int GCD(big_int a, big_int b);
  big_int ExtendedGCD(big_int a, big_int b);
  public:
  RSA();
  void Encryption(std::ifstream& inp, std::string plainFile, std::ofstream& out, std::string cipherFile);
  void Decryption(std::ifstream& inp, std::string cipherFile, std::ofstream& out, std::string decipherFile);
  big_int GetPublicKey();
  big_int GetModulo();
};