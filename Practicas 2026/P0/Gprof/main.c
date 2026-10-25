#include <stdio.h>

// Arrays for the SAXPY benchmark.

#ifndef N
#define N 4096
#endif

float x[N], y[N];

// SAXPY loop.

void saxpy(float a, float *restrict x, float *restrict y, int n)
{
  for (int k = 0; k < n; ++k)
    y[k] = a * x[k] + y[k];
}

// Busy-wait delay.

static inline void delay(void)
{
  for (int k = 0; k < 2000; ++k)
    ;
}

// Benchmark.

void benchmark(int n)
{
  for (int k = 0; k < n; ++k) {
    saxpy(0.5, x, y, N);
    delay();
  }
}

// Loop to repeat the benchmark.

void loop(int n)
{
  for (int k = 0; k < n; ++k)
    benchmark(n);
}

// Benchmark initialization and start up.

const int n = 1000;

int main(void)
{
  for (int k = 0; k < N; ++k) {
    x[k] = 0.001;
    y[k] = 0.01;
  }
  loop(n);
  return 0;
}
