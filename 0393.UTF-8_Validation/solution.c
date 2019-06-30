#include <stdio.h>
#include <stdbool.h>

#define ONE_BYTE   0b00000000
#define ONE_MASK   0b10000000
#define TWO_BYTE   0b11000000
#define TWO_MASK   0b11100000
#define THREE_BYTE 0b11100000
#define THREE_MASK 0b11110000
#define FOUR_BYTE  0b11110000
#define FOUR_MASK  0b11111000
#define CONT_BYTE  0b10000000
#define CONT_MASK  0b11000000

bool validUtf8(int* data, int dataSize){
    int cont_byte = 0;
    for (int i = 0; i < dataSize; i++) {
        if (cont_byte) {
            if ((data[i] & CONT_MASK) == CONT_BYTE) {
                cont_byte--;
                continue;
            } else {
                return false;
            }
        }
        if ((data[i] & ONE_MASK) == ONE_BYTE) {
        } else if ((data[i] & TWO_MASK) == TWO_BYTE) {
            cont_byte = 1;
        } else if ((data[i] & THREE_MASK) == THREE_BYTE) {
            cont_byte = 2;
        } else if ((data[i] & FOUR_MASK) == FOUR_BYTE) {
            cont_byte = 3;
        } else {
            return false;
        }
    }
    if (cont_byte) return false;
    return true;
}

int main() {
#if 0
    int data[] = {197, 130, 1};
#elif 0
    int data[] = {235, 140, 4};
#elif 1
    int data[] = {255};
#endif
    int dataSize = sizeof(data)/sizeof(data[0]);
    if (validUtf8(data, dataSize)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}