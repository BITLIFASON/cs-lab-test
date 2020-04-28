#include <iostream>
#include <cassert>
using namespace std;

char nibble_to_hex(uint8_t i){      //пукт 1.1

    assert(0x0 <= i && i <= 0xf);
    char digits[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    return digits[i];
    }

void print_in_hex(uint8_t byte) {
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

const uint8_t* as_bytes(const void* data){
    return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);

        // Для удобства чтения: пробелы между байтам, по 16 байт на строку.
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}

void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte, 0);
}

void print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

        // Для удобства чтения: пробелы между байтами, по 4 байта на строку.
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

void calc(uint16_t op1, char oper, uint16_t op2){
    print_in_hex (&op1, sizeof(op1));
    cout << oper;
    print_in_hex (&op2, sizeof(op2));
    cout << "= ";
    uint16_t rez;
    if ( oper=='&'){
        rez=op1&op2;
    }
    if ( oper=='|'){
        rez=op1|op2;
    }
    if (oper == '^') {
        rez = op1^op2;
    }
    print_in_hex (&rez, sizeof(rez));
      cout << '\n';
    print_in_binary (&op1, sizeof(op1));
    cout << oper;
    print_in_binary (&op2, sizeof(op2));
    cout << "= ";
    print_in_binary (&rez, sizeof(rez));
}

int main()
{
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    calc(0xAA,'|',0xA5);
}
