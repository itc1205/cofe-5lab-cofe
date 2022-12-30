#include <iostream>
#include <bitset>
#include <climits>

#define BINARY_SIZE 8

using namespace std;

char* convert_to_binary(int number) {
    char* char_buffer = new char[BINARY_SIZE] {'0', '0', '0', '0', '0', '0', '0', '0'}; // Создаем в куче массив из 8 символов
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

    char* new_char_buffer = new char[BINARY_SIZE] {'0', '0', '0', '0', '0', '0', '0', '0'}; 

    for (int i = 0; i < BINARY_SIZE; i++) {
        new_char_buffer[BINARY_SIZE - 1 - i] = char_buffer[i];
    }
    
    delete [] char_buffer;

    return new_char_buffer;
}

char* convert_to_signed_binary(int number) {
    char* char_buffer = convert_to_binary(abs(number));
    if (number < 0) {
        char_buffer[0] = '1';
    }
    return char_buffer;
}

char* _convert_to_float_binary_unfinished(float number) {
    int FLOAT_OFFSET = 0;
    int B = 2;
    char* char_buffer = new char[1 + 8 + 23];
    for (int i = 0; i < 1 + 8 + 23; i++) {
        char_buffer[i] = '0';
    }
    
    if (number < 0) {
        char_buffer[FLOAT_OFFSET] = '1';
    }
    FLOAT_OFFSET++;
    
    FLOAT_OFFSET = 9;
    return nullptr;
}

bitset<sizeof(float) * CHAR_BIT> bits_float_binary(float number) {
    return bitset<sizeof(float) * CHAR_BIT> (number);
}



int main() {
    int number = -12;
    float f_number = 12.5;


    char* p_number_bin = convert_to_binary(abs(number));
    cout << "Number converted to binary: ";
    for (int i = 0; i < BINARY_SIZE; i++) {
        cout << *(p_number_bin + i);
    }
    cout << endl;

    char* p_number_bin_signed = convert_to_signed_binary(number);
    cout << "Number converted to signed binary: ";
    for (int i = 0; i < BINARY_SIZE; i++) {
        cout << *(p_number_bin_signed + i);
    }
    cout << endl;
    cout << "Number converted to float: " << bits_float_binary(number);

    delete[] p_number_bin_signed;
    delete[] p_number_bin;
}