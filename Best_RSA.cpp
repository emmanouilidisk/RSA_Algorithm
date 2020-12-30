#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "boost_1_66_0/boost/multiprecision/cpp_int.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using big_int = boost::multiprecision::cpp_int ;

class RSA {
  int privateKey;
  int publicKey;
  int modulo;
  bool PrimalityTest(int a, int i);
  big_int FindT(big_int a, int m, int n);
  void FastExponention(int bit, int n, big_int * y, big_int* a);
  int GCD(int a, int b);
  int ExtendedGCD(int a, int b);
  public:
  RSA();
  void Encryption(int value, std::ofstream &out);
  void Decryption(int value, std::ofstream &out);
};

RSA::RSA(){
    int p, q;
    int phi_n;
    do {
      do
      p = rand();
      while (p % 2 == 0);
    } while (!PrimalityTest(2, p));

  do {
    do
      q = rand();
    while (q % 2 == 0);
  } while (!PrimalityTest(2, q));

	modulo = p * q;
	phi_n = (p - 1) * (q - 1);

	do
		publicKey = rand() % (phi_n - 2) + 2; // 1 < e < phi_n
	while (GCD(publicKey, phi_n) != 1);

	privateKey = ExtendedGCD(phi_n, publicKey);
  std::cout << publicKey << " " << privateKey << std::endl;
}

bool RSA::PrimalityTest(int a, int i){
	int n = i - 1;
	int k = 0;
	int j, m;
  big_int T;

  while (n % 2 == 0) {
    k++;
    n = n / 2;
	}

	m = n;
	T = FindT(a, m, i);

	if (T == 1 || T == i - 1)
		return true;

	for (j = 0; j < k; j++) {
		T = FindT(T, 2, i);
		if (T == 1)
			return false;
		if (T == i - 1)
			return true;
	}
	return false;
}

big_int RSA::FindT(big_int a, int m, int n){
  int r;
  big_int y = 1;

	while (m > 0) {
		r = m % 2;
		FastExponention(r, n, &y, &a);
		m = m / 2;
	}
  //std::cout << y << std::endl;
	return y;
}

void RSA::FastExponention(int bit, int n, big_int *y, big_int *a){
  if (bit == 1)
    *y = (*y * (*a)) % n;

  *a = (*a) * (*a) % n;
}

int RSA::GCD(int a, int b){
  int q, r1, r2, r;

	if (a > b) {
		r1 = a;
		r2 = b;
	}
	else {
		r1 = b;
		r2 = a;
	}

	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;
	}

	return r1;
}

int RSA::ExtendedGCD(int a, int b){
  int inv;
  int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;

  while (r2 > 0) {
    q = r1 / r2;
    r = r1 % r2;
    r1 = r2;
    r2 = r;

    t = t1 - q * t2;
    t1 = t2;
    t2 = t;
  }

  if (r1 == 1)
    inv = t1;

  if (inv < 0)
    inv = inv + a;

  return inv;
}

void RSA::Encryption(int value, std::ofstream& out){
  big_int cipher;
	cipher = FindT(value,publicKey , modulo);
  out << cipher << " ";
}

void RSA::Decryption(int value, std::ofstream& out){
  big_int decipher;
  decipher = FindT(value, privateKey, modulo);
  std::stringstream ss;
  ss << decipher;
  int temp;
  ss >> temp;
  out << (char)temp;
}


int main(void){
  FILE *inp;
  std::ofstream out;

  // destroy contents of these files (from previous runs, if any)
  out.open("cipher.txt");
  out.close();
  out.open("decipher.txt");
  out.close();

  srand (time(NULL));
  RSA rsa;

  inp = fopen("plain.txt", "r+");
  if (inp == NULL) {
    printf("Error opening Source File.\n");
    exit(1);
  }

  out.open("cipher.txt");
  if (!out) {
    printf("Error opening Destination File.\n");
    exit(1);
  }

  // encryption starts
  while (true) {
    char ch = getc(inp);
    if (ch == -1)
      break;
    int value = toascii(ch);
    rsa.Encryption(value, out);
  }

	fclose(inp);
	out.close();

	// decryption starts
	inp = fopen("cipher.txt", "r");
	if (inp == NULL) {
		printf("Error opening Cipher Text.\n");
		exit(1);
	}

  out.open("decipher.txt");
  if (!out) {
    printf("Error opening File.\n");
    exit(1);
  }

  while (1) {
    int cip;
    if (fscanf(inp, "%d", &cip) == -1)
      break;
    rsa.Decryption(cip, out);
  }
  out.close();

  return 0;
}
