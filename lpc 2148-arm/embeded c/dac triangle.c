#include <stdint.h>
#include<lpc214x.h>

int main(void) {
    int value = 0;
    int direction = 1;

    // Configure DAC and other necessary peripherals

    while(1) {
        // Generate triangular wave
        DACR = (value << 6); // Set DAC value

        // Update value for next iteration
        value += direction;

        // Change direction if reaching upper or lower limit
        if (value >= 1023 || value <= 0) {
            direction *= -1;
        }

    }
}