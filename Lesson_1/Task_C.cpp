/*Петя - начинающий программист. Сегодня он написал код из n строк.
К сожалению оказалось, что этот код трудно читать.
Петя решил исправить это, добавив в различные места пробелы.
А точнее, для i-й строки ему нужно добавить ровно a i пробелов.
Для добавления пробелов Петя выделяет строку и нажимает на
одну из трёх клавиш: Space, Tab, и Backspace.
При нажатии на Space в строку добавляется один пробел.
При нажатии на Tab в строку добавляются четыре пробела.
При нажатии на Backspace в строке удаляется один пробел.
Ему хочется узнать, какое наименьшее количество клавиш придётся нажать,
чтобы добавить необходимое количество пробелов в каждую строку.
Помогите ему!*/
#include <iostream>
#include <vector>
unsigned long long AddingSpaces(int quantity_of_string, const std::vector<unsigned long long>& v) {
    unsigned long long sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i] / 4;
        switch (v[i] % 4) {
            case 1:
                sum += 1;
                break;
            case 2:
                sum += 2;
                break;
            case 3:
                sum += 2;
        }
    }
    return sum;
}
int main() {
    int a;
    std::cin >> a;
    std::vector<unsigned long long> v(a);
    for (int i = 0; i < v.size(); ++i) {
        std::cin >> v[i];
    }
    std::cout << AddingSpaces(a, v);
}

// using ull = unsigned long long;

// ull MakeFormat( ull countOfStrings )
// {
//    if( countOfStrings == 0 )
//    {
//       return 0;
//    }
//    ull result = 0;
//    result += countOfStrings / 4;

//    ull remainder = countOfStrings % 4;
//    switch( remainder )
//    {
//    case 1:
//       result++;
//       break;
//    case 2:
//       result += 2;
//       break;
//    case 3:
//       result += 2;
//       break;
//    }

//    return result;
// }

// int main()
// {
//    size_t n;
//    std::cin >> n;
//    ull result = 0;
//    for( size_t i = 0; i < n; ++i )
//    {
//       ull v;
//       std::cin >> v;
//       result += MakeFormat( v );
//    }
//    std::cout << result;
//    return 0; // dds
// }
// 11 -> 4+4+4-1

// 10 -> 4+4+4-1-1 / 4+4+1+1

// 1 -> 1

// 2 -> 1+1

// 3 -> 4-1 -> 2

// 4 -> 4

// 5 -> 4+1

// 6 -> 4+1+1

// 7 -> 4 + 4 -1

// 8 -> 4+4

// 9 -> 4+4+1

// 10 -> 4+4+1+1

// 11 -> 4+4+4-1

// 13 -> 4+4+4+1
