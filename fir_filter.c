
#include <stdio.h>
#define FILTER_TAP_NUM 5

// Simple moving average FIR filter
void fir_filter(float* input, float* output, int length) {
    float buffer[FILTER_TAP_NUM] = {0};
    for (int i = 0; i < length; i++) {
        buffer[i % FILTER_TAP_NUM] = input[i];
        float acc = 0.0;
        int count = 0;
        for (int j = 0; j < FILTER_TAP_NUM; j++) {
            if (i - j >= 0) {
                acc += buffer[(i - j) % FILTER_TAP_NUM];
                count++;
            }
        }
        output[i] = acc / count;
    }
}

int main() {
    // Example input signal: noisy sine wave samples (simplified)
    float input_signal[20] = {0.0, 0.3, 0.5, 0.8, 1.0, 0.9, 0.7, 0.4, 0.1, -0.2,
                              -0.4, -0.6, -0.7, -0.6, -0.4, -0.1, 0.2, 0.5, 0.7, 0.8};
    float filtered_signal[20] = {0};

    int length = 20;

    fir_filter(input_signal, filtered_signal, length);

    printf("Input Signal  | Filtered Signal\n");
    printf("-------------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%12.4f | %14.4f\n", input_signal[i], filtered_signal[i]);
    }

    return 0;
}
