// На шахматной доске стоят слоны и ладьи, необходимо посчитать, сколько клеток
// не бьется ни одной из фигур. Шахматная доска имеет размеры 8 на 8. Ладья бьет
// все клетки горизонтали и вертикали, проходящих через клетку, где она стоит,
// до первой встретившейся фигуры. Слон бьет все клетки обеих диагоналей,
// проходящих через клетку, где он стоит, до первой встретившейся фигуры. Формат
// ввода В первых восьми строках ввода описывается шахматная доска. Первые
// восемь символов каждой из этих строк описывают состояние соответствующей
// горизонтали: символ B (заглавная латинская буква) означает, что в клетке
// стоит слон, символ R — ладья, символ * — что клетка пуста. После описания
// горизонтали в строке могут идти пробелы, однако длина каждой строки не
// превышает 250 символов. После описания доски в файле могут быть пустые
// строки.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int Rook(vector<string> &v, int i_, int j_, int &fields);
int Elephant(vector<string> &v, int i_, int j_, int &fields);
int CalculateQuantityOfEmptyFields(vector<string> &v) {
    int fields = 64;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (v[i][j] == '*') {
                continue;
            }
            if (v[i][j] == 'R') {
                Rook(v, i, j, fields);
            }
            if (v[i][j] == 'B') {
                Elephant(v, i, j, fields);
            }
        }
    }
    return fields;
}

int Rook(vector<string> &v, int i_, int j_, int &fields) {
    int i2 = i_;
    int j2 = j_;
    fields--;
    for (int j = j_ - 1; j >= 0; j--) {
        if (v[i2][j] && (v[i2][j] == 'B' || v[i2][j] == 'R')) {
            break;
        }
        if (v[i2][j] == '1') {
            continue;
        }
        v[i2][j] = '1';
        fields--;
    }
    for (int j = j_ + 1; j < 8; j++) {
        if (v[i2][j] && (v[i2][j] == 'B' || v[i2][j] == 'R')) {
            break;
        }
        if (v[i2][j] == '1') {
            continue;
        }
        v[i2][j] = '1';
        fields--;
    }
    for (int i = i_ - 1; i >= 0; i--) {
        if (v[i][j2] && (v[i][j2] == 'B' || v[i][j2] == 'R')) {
            break;
        }
        if (v[i][j2] == '1') {
            continue;
        }
        v[i][j2] = '1';
        fields--;
    }
    for (int i = i_ + 1; i < 8; i++) {
        if (v[i][j2] && (v[i][j2] == 'B' || v[i][j2] == 'R')) {
            break;
        }
        if (v[i][j2] == '1') {
            continue;
        }
        v[i][j2] = '1';
        fields--;
    }
    return fields;
}
int Elephant(vector<string> &v, int i_, int j_, int &fields) {
    int i = i_ + 1;
    int j = j_ - 1;
    while (i < 8 && j >= 0) {
        if (v[i][j] && (v[i][j] == 'B' || v[i][j] == 'R')) {
            break;
        }
        if (v[i][j] == '1') {
            --j;
            ++i;
            continue;
        }
        v[i][j] = '1';
        --j;
        ++i;
        fields--;
    }
    i = i_ + 1;
    j = j_ + 1;
    while (i < 8 && j < 8) {
        if (v[i][j] && (v[i][j] == 'B' || v[i][j] == 'R')) {
            break;
        }
        if (v[i][j] == '1') {
            ++j;
            ++i;
            continue;
        }
        v[i][j] = '1';
        ++j;
        ++i;
        fields--;
    }
    i = i_ - 1;
    j = j_ - 1;
    while (i >= 0 && j >= 0) {
        if (v[i][j] && (v[i][j] == 'B' || v[i][j] == 'R')) {
            break;
        }
        if (v[i][j] == '1') {
            --j;
            --i;
            continue;
        }
        v[i][j] = '1';
        --j;
        --i;
        fields--;
    }
    i = i_ - 1;
    j = j_ + 1;
    while (i >= 0 && j < 8) {
        if (v[i][j] && (v[i][j] == 'B' || v[i][j] == 'R')) {
            break;
        }
        if (v[i][j] == '1') {
            ++j;
            --i;
            continue;
        }
        v[i][j] = '1';
        ++j;
        --i;
        fields--;
    }
    fields--;
    return fields;
}
int main() {
    int res;
    vector<string> v(8);
    for (int i = 0; i < v.size(); ++i) {
        string a;
        cin >> a;
        v[i] = a;
    }
    res = CalculateQuantityOfEmptyFields(v);
    cout << res;
}

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;
// void AnalyzeRow( vector< vector< char > >& m, int row )
// {
//    for( unsigned short i = 0; i < 8; ++i )
//    {
//       if( m[ row ][ i ] == '*' )
//       {
//          continue;
//       }
//       else if( m[ row ][ i ] == 'B' )
//       {
//          int j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             --j;
//             ++mRow;
//          } while( j >= 0 && mRow < 8 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );

//          j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             --j;
//             --mRow;
//          } while( j >= 0 && mRow >= 0 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );

//          j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             ++j;
//             ++mRow;
//          } while( j < 8 && mRow < 8 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );

//          j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             ++j;
//             --mRow;
//          } while( j < 8 && mRow >= 0 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );
//       }
//       else if( m[ row ][ i ] == 'R' )
//       {
//          int j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             --j;
//          } while( j >= 0 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );

//          j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             ++j;
//          } while( j < 8 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );

//          j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             ++mRow;
//          } while( mRow < 8 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );

//          j = i, mRow = row;
//          do
//          {
//             if( m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' )
//                m[ mRow ][ j ] = '-';
//             --mRow;
//          } while( mRow >= 0 && m[ mRow ][ j ] != 'B' && m[ mRow ][ j ] != 'R' );
//       }
//    }
// }

// int main()
// {

//    vector< vector< char > > matr( 8, vector< char >( 8, '*' ) );

//    for( unsigned short i = 0; i < 8; ++i )
//    {
//       string s;
//       cin >> s;
//       for( int j = 0; j < 8; ++j )
//       {
//          matr[ i ][ j ] = s[ j ];
//       }
//    }

//    for( unsigned short i = 0; i < 8; ++i )
//    {
//       AnalyzeRow( matr, i );
//    }

//    size_t res = 0;
//    for( int i = 0; i < 8; ++i )
//    {
//       for( int j = 0; j < 8; ++j )
//       {
//          if( matr[ i ][ j ] == '*' )
//          {
//             res++;
//          }
//       }
//    }
//    cout << res;
//    return 0; // dds
// }

// ****1***
// *****1*1
// ******B*
// *****1*1
// ****1***
// ***1****
// **1*****
// *1******

// **1*****
// *R*1****
// ****1**1
// *****B**
// ****1*1*
// ***1***1
// **1*****
// *1******

// 1*1*1*1*
// *1*B*1**
// **BRB***
// *1**1**
// 1*1*1*1*
// *1***1*1
// 1*****1*
// *******1