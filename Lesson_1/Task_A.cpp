#include <iostream>
#include <set>
/*Вася и Маша участвуют в субботнике и красят стволы деревьев в белый цвет.
Деревья растут вдоль улицы через равные промежутки в 1 метр.
Одно из деревьев обозначено числом ноль, деревья по одну
сторону занумерованы положительными числами
1,2 и т.д., а в другую — отрицательными −1,−2 и т.д.
Ведро с краской для Васи установили возле дерева P, а для Маши — возле дерева
Q. Ведра с краской очень тяжелые и Вася с Машей не могут их переставить,
поэтому они окунают кисть в ведро и уже с этой кистью идут красить дерево.
Краска на кисти из ведра Васи засыхает, когда он удаляется от ведра более чем на
V метров, а из ведра Маши — на M метров.
Определите, сколько деревьев может быть покрашено.*/

// FIRST DECISION
//  int paintTrees(std::pair<int, int> &a, std::pair<int, int> &b) {
//      std::set<int> allTree;
//      int tmp = a.first - a.second;
//      int tmp2 = b.first - b.second;
//      for (int i = 0; i < (a.second * 2 + 1); ++i) {
//          allTree.emplace(tmp);
//          ++tmp;
//      }
//      for (int j = 0; j < (b.second * 2 + 1); ++j) {
//          allTree.emplace(tmp2);
//          ++tmp2;
//      }
//      return allTree.size();
//  }
// MEMORY LIMIT
int paintTrees(std::pair<int, int> &a,
               std::pair<int, int> &b) {  // SECOND DECISION
    int paintTrees = 0;
    paintTrees += (a.second * 2) + 1;  // 5
    paintTrees += (b.second * 2) + 1;  // 5 + 7 = 12
    std::pair<int, int> first, second;
    if (a.first - a.second < b.first - b.second) {  // -5 - 3 = -8 -6 - 1 = -7
        first.first = a.first - a.second;
        first.second = a.first + a.second;
        second.first = b.first - b.second;
        second.second = b.first + b.second;
    } else {
        second.first = a.first - a.second;
        second.second = a.first + a.second;
        first.first = b.first - b.second;
        first.second = b.first + b.second;
    }
    if (first.second < second.first) {
        return paintTrees;
    } else if (first.second > second.second) {
        paintTrees -= second.second - second.first + 1;
    } else {
        paintTrees -= (first.second - second.first + 1);
    }
    // -5 3

    // -4 3

    //  |                 |
    // -8 -7 -6 -5 -4 -3 -2 -1 0 1 2   // -1 -(-2) + 1 = 2
    //     |                 |
    // 5 3 -> [2, 8]
    // 7 2 -> [5, 9]
    // |           |
    // 2 3 4 5 6 7 8 9
    //       |        |
    // 5 3 -> [2, 8] // 7

    // 6 1 -> [5, 7] // 3

    // 10 -= 8 - 5 = 3

    // |             |
    // 2 3 4 5 6 7 8 9
    //       |   |

    return paintTrees;
    // CASE WORKS
}

int main() {
    std::pair<int, int> masha;
    std::pair<int, int> vasya;
    std::cin >> masha.first >> masha.second;
    std::cin >> vasya.first >> vasya.second;
    std::cout << paintTrees(masha, vasya);

    return 0;
}
// 13 4
// 0 3

// 0 7
// 12 5

// 8 2
// 5 3

// 2 3 4 5 6 7 8
// 6 7 8 9 10