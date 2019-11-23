//
// Created by Zachary Kurmas on 2019-11-19.
//

#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// https://asecuritysite.com/encryption/random3?val=32
unsigned long long x_32_bit = 2'865'430'069;
unsigned long long x_48_bit = 208'451'094'725'309;
unsigned long long x_52_bit = 3'949'404'427'601'627;
unsigned long long x_56_bit = 29'624'369'536'642'963;
unsigned long long x_60_bit = 293'859'883'014'095'719;
unsigned long long x_62_bit = 4'227'810'282'801'500'953;
unsigned long long x_64_bit = 11'843'074'266'365'748'139U;


// Traditional "brute-force" algorithm for testing primality
bool isPrime(unsigned long long x) {
  if (x % 2 == 0) {
    return false;
  }
  for (unsigned long long i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void timeIsPrime(unsigned bits, unsigned long long x) {
  auto start = high_resolution_clock::now();
  bool result = isPrime(x);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  cout << bits << "\t" << duration.count() << flush;
  cout << "\t# " << x << (result ? " is " : " is not ") << "prime." << endl;
}

int timeBruteForce() {
  timeIsPrime(32, x_32_bit);
  timeIsPrime(48, x_48_bit);
  timeIsPrime(52, x_52_bit);
  timeIsPrime(56, x_56_bit);
  timeIsPrime(60, x_60_bit);
  timeIsPrime(62, x_62_bit);
  timeIsPrime(64, x_64_bit);

  return 0;
}


unsigned long long check1(unsigned long long a, unsigned long long i, unsigned long long n) {

  if (i == 0) {
    return 1;
  }
  if (i == 1) {
    return a;
  }

  // Need 128 bits to store the result of 64-bit multiplication.
  // At least one parameter must be cast to 128-bit to ensure the proper multiplication is done;
  // (If we don't cast one of the parameters, then it will calculate a 64-bit truncated answer,
  // then cast the incorrect answer to 128 bits.)
  __uint128_t a_squared = (__uint128_t) a * a;
  if (i % 2 == 0) {
    return check1((a_squared) % n, i / 2, n) % n;
  } else {
    return ((__uint128_t) check1((a_squared) % n, i / 2, n) * a) % n;
  }
}

unsigned long long check2(unsigned long long a, unsigned long long i) {

  if (i == 0) {
    return 1;
  }
  if (i == 1) {
    return a;
  }
  if (i % 2 == 0) {
    return check2((a * a), i / 2);
  } else {
    return check2((a * a), i / 2) * a;
  }
}

bool isPrimeWeak(long long x, unsigned attempts) {
  for (unsigned i = 0; i < attempts; ++i) {
    unsigned long long r = (rand() % (x -5)) + 4;
    auto val = check1(r, x - 1, x);
    if ( val != 1) {
      //cout << r << " proves " << x << " not prime " << val << endl;
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {

  srand(1);

  unsigned long long success_count = 0;
  unsigned long long fail_count = 0;

  //cout << "1201a " << isPrimeWeak(1187, 100) << endl;
  //cout << "1201b " << isPrimeWeak(1201, 100) << endl;
  //cout << "1201c " << isPrimeWeak(1201, 100) << endl;
  //cout << "1201d " << isPrimeWeak(1201, 100) << endl;
  //return 0;

  if (argc < 2 || string(argv[1]) != "--skip") {
    timeBruteForce();
  }

  unsigned long long start = (1024 / 10) * 10 - 100;
  unsigned long long stop = 10 * x_56_bit;

  if (start % 10 != 0) {
    cout << "Start must be a multiple of 10" << endl;
    return 1;
  }

  unsigned offsets[] = {1, 3, 7, 9};

  for (unsigned long long i = start; i <= stop; i += 10) {

    if (i % 100'000 == 0) {
      cout << "." << flush;
    }

    for (unsigned offset : offsets) {
      unsigned long long candidate = i + offset;
      bool ans = isPrimeWeak(candidate, 100);
      if (isPrimeWeak(candidate, 100)) {
        // cout << candidate << " Looks prime ... " << flush;
        if (isPrime(candidate)) {
         // cout << "*" << flush;
         success_count++;
        } else {
          ++fail_count;
          cout << "FAIL " << candidate << " incorrectly identified as prime. ";
          cout <<  endl << fail_count << " failures out of " << success_count << endl;
        }
      } // if weak true
    } // end inner for
  } // end outer for
  return 0;
}


