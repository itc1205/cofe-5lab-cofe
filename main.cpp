#include <math.h>
#include <bitset>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#define BINARY_SIZE 8

using namespace std;

char *convert_to_binary(int number) {
  char *char_buffer = new char[BINARY_SIZE]{
      '0', '0', '0', '0',
      '0', '0', '0', '0'}; // Создаем в куче массив из 8 символов
  int i = 0;

  while (number >= 1) {
    if (number % 2 == 1) {
      char_buffer[i] = '1';
    } else {
      char_buffer[i] = '0';
    }
    number /= 2;
    i++;
  }

  char *new_char_buffer =
      new char[BINARY_SIZE]{'0', '0', '0', '0', '0', '0', '0', '0'};

  for (int i = 0; i < BINARY_SIZE; i++) {
    new_char_buffer[BINARY_SIZE - 1 - i] = char_buffer[i];
  }

  delete[] char_buffer;

  return new_char_buffer;
}

char *convert_to_signed_binary(int number) {
  char *char_buffer = convert_to_binary(abs(number));
  for (int i = 0; i < BINARY_SIZE; i++) {
    if (char_buffer[i] == '0') {
      char_buffer[i] = '1';
    } else {
      char_buffer[i] = '0';
    }
  }
  int i = 7;
  if (number < 0) {
    if (char_buffer[7] == '0') {
      char_buffer[7] = '1';
    } else {
      while (char_buffer[i - 1] == '1') {
        char_buffer[i] = '0';
        i--;
        if (i == 1){
          break;
        }
      }
    }
  }
  return char_buffer;
}

void _convert_to_float_binary_second_var(double number) {
  double num, frac;
  int dec, i = 0;
  num = number;
  dec = int(num);
  frac = num - dec;
  string dbin, fbin, exbin;

  while (dec > 0) {
    if (dec % 2 == 0) {
      dbin += "0";
    } else {
      dbin += "1";
    }
    dec /= 2;
  }
  reverse(dbin.begin(), dbin.end());

  fbin = ".";

  for (int i = 0; i < 24; i++) {
    frac *= 2;
    int t = frac;
    if (t == 0) {
      fbin += "0";
    } else {
      fbin += "1";
    }
    frac = frac - t;
    if (frac <= 1e-8)
      break;
  }
  string Num = dbin + fbin;
  double M = stod(Num);
  int ex = 0;
  while (1) {
    if (floor(M / 10) == 0)
      break;
    M /= 10;
    ex++;
  }
  ex += 127;
  while (ex > 0) {
    if (ex % 2 == 0) {
      exbin += "0";
    } else {
      exbin += "1";
    }
    ex /= 2;
  }
  reverse(exbin.begin(), exbin.end());
  stringstream ss;
  ss << fixed << setprecision(15) << M;
  string SM = ss.str();
  int exbi = 0;
  int mbi = 0;
  string PZ = "0";
  SM.erase(0, 2);
  PZ += exbin + SM;
  while (1) {
    if (PZ.length() < 32) {
      PZ += "0";
    } else {
      break;
    }
  }
  cout << setprecision(15) << PZ[0] << " " << PZ.substr(1, 8) << " "
       << PZ.substr(9, PZ.length()) << endl;
}

int main() {
  int number = -12;
  float f_number = 12.5;

  char *p_number_bin = convert_to_binary(abs(number));
  cout << "Number converted to binary: ";
  for (int i = 0; i < BINARY_SIZE; i++) {
    cout << *(p_number_bin + i);
  }
  cout << endl;

  char *p_number_bin_signed = convert_to_signed_binary(number);
  cout << "Number converted to signed binary: ";
  for (int i = 0; i < BINARY_SIZE; i++) {
    cout << *(p_number_bin_signed + i);
  }
  cout << endl;
  _convert_to_float_binary_second_var(f_number);

  delete[] p_number_bin_signed;
  delete[] p_number_bin;
}