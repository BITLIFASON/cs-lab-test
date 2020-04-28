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

struct Student{

char name[17];  //имя
uint16_t entr_year;   //год поступления
float aver_mark;   //средний балл
uint8_t gender:1;  //по умолчанию мужской
uint8_t fin_courses; //пройденные курсы
Student* headman;   //староста
};

int main()
{
    /*
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
    */
    Student Students[3]={
       {"Artem", 2019, 3.5, 1, 2, nullptr},
       {"Andrey", 2019, 4.6, 1, 2},
       {"Sasha", 2019, 3.2, 1, 2},
    };

    cout << "Address of Students: \t" << &Students << endl;
    cout << "Size of Students: \t" << sizeof(Students) << endl;

    cout << "Address of Students[1]: \t" << &Students[1] << endl;
    cout << "Size of Students[1]: \t" << sizeof(Students[1]) << endl;
    cout << "Address of Students[2]: \t" << &Students[2] << endl;
    cout << "Size of Students[2]: \t" << sizeof(Students[2]) << endl;
    cout << "Address of Students[3]: \t" << &Students[3] << endl;
    cout << "Size of Students[3]: \t" << sizeof(Students[3]) << endl;

    cout << "Address of name: \t" << &Students[2].name << endl;
    cout << "Address of entr_year: \t" << &Students[2].entr_year << endl;
    cout << "Address of aver_mark: \t" << &Students[2].aver_mark << endl;
    cout << "Address of fin_courses: \t" << &Students[2].fin_courses << endl;  //не работает, но при этом отладчик видит его в 0x74ff09

    cout << "Name is at offset: \t" << offsetof(Student, name) << endl;
    cout << "Year is at offset: \t" << offsetof(Student, entr_year) << endl;
    cout << "Aver is at offset: \t" << offsetof(Student, aver_mark) << endl;
    cout << "Course is at offset: \t" << offsetof(Student, fin_courses) << endl;

    cout << "Size of name: \t" << sizeof(Students[2].name) << endl;
    cout << "Size of year: \t" << sizeof(Students[2].entr_year) << endl;
    cout << "Size of aver: \t" << sizeof(Students[2].aver_mark) << endl;
    cout << "Size of fin_courses: \t" << sizeof(Students[2].fin_courses) << endl;

    cout << "Year in hex: \t";
    print_in_hex(&Students[2].entr_year, sizeof(Students[2].entr_year));
    cout << endl;
    cout << "Aver in hex: \t";
    print_in_hex(&Students[2].aver_mark, sizeof(Students[2].aver_mark));
    cout << endl;
    cout << "Course in hex: \t";
    print_in_hex(&Students[2].fin_courses, sizeof(Students[2].fin_courses));
    cout << endl;

    cout << "Year in bin: \t";
    print_in_binary(&Students[2].entr_year, sizeof(Students[2].entr_year));
    cout << endl;
    cout << "Aver in bin: \t";
    print_in_binary(Students[2].aver_mark);
    cout << endl;
    cout << "Course in bin: \t";
    print_in_binary(Students[2].fin_courses);
    cout << endl;

    cout << "entr_year       aver_mark         fin_courses \n";
    for (int i = 0; i < 3; i++){
        print_in_hex(&Students[i].entr_year, sizeof(Students[i].entr_year));
        cout << "    |    ";
        print_in_hex(&Students[i].aver_mark, sizeof(Students[i].aver_mark));
        cout << "    |    ";
        print_in_hex(&Students[i].fin_courses, sizeof(Students[i].fin_courses));
        cout << endl;
    }

//    uint16_t u1 = 1025;
//    uint16_t u2 = 127;
//    calc(u1, '&', u2);
//    uint32_t u32 = 42;
//    cout << "u32 bytes: ";
//    print_in_hex(&u32, sizeof(u32));
//    cout << "\n";
//    uint16_t u16 = 0x42;
//    cout << "u16 bytes: ";
//    print_in_hex(&u16, sizeof(u16));
//    cout << "\n";
//    uint8_t u8 = 0x42;
//    cout << "u8 bytes: ";
//    print_in_hex(&u8, sizeof(u8));
//    cout << "\n";
//    print_in_binary(&u32, sizeof(u32));
//    cout << "\n";
//    print_in_binary(&u16, sizeof(u16));
//    cout << "\n";
//    print_in_binary(&u8, sizeof(u8));
//    cout << "\n";

}
