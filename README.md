
# Simple FIR Filter in C

This project implements a simple Finite Impulse Response (FIR) filter using a moving average filter algorithm in C.

## Description

- The filter is a basic moving average filter with a fixed tap number (5).
- It smooths the input signal by averaging the current and previous samples.
- This example uses a small array of noisy sine wave-like samples.
- The filtered output is printed alongside the original input.

## How to compile and run

Use `gcc` to compile:

```bash
gcc -o fir_filter fir_filter.c
./fir_filter
```

## Output

The program prints a table showing the original input signal and the filtered output signal.

## License

This code is released under the MIT License.
