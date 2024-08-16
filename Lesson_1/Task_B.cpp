#include <iostream>
/*Раунд плей-офф между двумя командами состоит из двух матчей.
Каждая команда проводит по одному матчу «дома» и «в гостях». Выигрывает команда,
забившая большее число мячей. Если же число забитых мячей совпадает,
выигрывает команда, забившая больше мячей «в гостях».
Если и это число мячей совпадает, матч переходит
в дополнительный тайм или серию пенальти.
Вам дан счёт первого матча, а также счёт текущей игры
(которая ещё не завершилась). Помогите комментатору сообщить,
сколько голов необходимо забить первой команде, чтобы победить,
не переводя игру в дополнительное время.*/
int footballMatch(std::pair<int, int> &first, std::pair<int, int> &second,
                  int place) {
    int needGoals = 0;
    needGoals = (first.second + second.second) - (first.first + second.first);
    if (needGoals < 0) {
        return 0;
    }
    if (needGoals == 0) {
        if ((place == 2 && first.first < second.first) ||
            (first.first == first.second && first.first == second.first &&
             first.first == second.second) ||
            (place == 1 && first.first > first.second &&
             second.first < second.second) ||
            (place == 2 && first.second <= second.first) ||
            (place == 1 && first.first == first.second &&
             first.second > second.first) ||
            (first.first == second.second && first.second == second.first) ||
            (place == 1 && first.first > second.first)) {
            return 1;
        } else {
            return 0;
        }
        // g1.first == g2.second && g1.second == g2.first
        //   test 4
        //    3:3          // 2 : 2           //2:2       //2:2
        //    2:2          // 3 : 3           //1:1       //3:3
        //    1 -> 1       // 2 -> 1 ready    //1 -> 1    //1 -> 0

        // 0:0           // 3:3
        // 0:0           // 3:3
        // 2/1 ->1 ready // 1/2 -> 1 ready

        // 2:4           // 4:2
        // 3:1           // 1:3
        // 1 -> 0 ready  // 1 -> 1 ready

        // 2:3          // 5:2                      //3:4
        // 3:2          // 2:5                      //4:3
        // 1 -> 1 ready // 2 -> 1 ready //17 test   //1 -> 1

        // 2:3          // 2:4
        // 3:2          // 3:1
        // 2 -> 1 ready // 2 -> 1 ready

        // 4:2          //4:2
        // 1:3          //1:3
        // 2 -> 0 ready //1 -> 1 ready

        // 2:3
        // 1:0
        // 1 -> 1
    }
    if ((place == 2 && first.first < first.second &&
         second.first < second.second) ||
        (place == 2 && first.first <= first.second) ||
        (place == 1 && second.second > second.first &&
         first.first > first.second) ||
        (place == 1 && second.first == second.second &&
         first.first < first.second)) {
        needGoals += 1;

        // 2:5           // 2:5
        // 0:2           // 0:2
        // 1 -> 5 ready  // 2 -> 6 ready

        // 0:2          // 0:2
        // 0:3          // 0:3
        // 1 -> 5 ready // 2 -> 6 ready

        // 5:2          // 5:2
        // 1:5          // 1:5
        // 1 -> 2 ready // 2 -> 1 ready

        // 2:2 test 8   // 1:4
        // 0:5          // 0:5
        // 1 -> 5 ready // 1 -> 8 ready //test 9

        // 2:2          // 3:4
        // 0:5          // 2:2
        // 2 -> 6 ready // 1 -> 2 ready

        // 1:3          // 5:2
        // 3:2          // 0:5
        // 1 -> 1 ready // 1 -> 3 ready//test 20
    }
    return needGoals;
}  //(place == 2 && first.first <= first.second) ||
   // first.first > second.first

int main() {
    std::string s1, s2;
    short unsigned v;

    std::cin >> s1 >> s2 >> v;

    std::pair<int, int> g1, g2;

    g1.first = s1[0] - '0';
    g1.second = s1[2] - '0';

    g2.first = s2[0] - '0';
    g2.second = s2[2] - '0';
    std::cout << footballMatch(g1, g2, v);
    return 0;
}