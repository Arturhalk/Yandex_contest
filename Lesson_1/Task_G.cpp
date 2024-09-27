// Вы играете в интересную стратегию. У вашего соперника остались всего одна
// казарма — здание, в котором постоянно появляются новые солдаты. Перед атакой
// у вас есть x солдат. За один раунд каждый солдат может убить одного из солдат
// противника или нанести 1 очко урона казарме (вычесть единицу здоровья у
// казармы). Изначально у вашего оппонента нет солдат. Тем не менее, его казарма
// имеет y единиц здоровья и производит p солдат за раунд. Ход одного раунда:
// Каждый солдат из вашей армии либо убивает одного из солдат вашего противника,
// либо наносит 1 очко урона казарме. Каждый солдат может выбрать своё действие.
// Когда казарма теряет все свои единицы здоровья, она разрушается.
// Ваш противник атакует. Он убьет k ваших солдат, где k — количество оставшихся
// у противника солдат. Если казармы еще не разрушены, ваш противник производит
// p новых солдат. Ваша задача — разрушить казарму и убить всех солдат
// противника. Если это возможно, посчитайте минимальное количество раундов,
// которое вам нужно для этого. В противном случае выведите -1.
#include <iostream>
#include <vector>
#include <algorithm>

bool MakeFirstTurn(long long x, long long &y)
{
    y -= x;
    if (y <= 0)
    {
        return true;
    }
    return false;
}

using ll = long long;

std::pair<bool, ll> CanFinishOff(ll ourSoldiers, ll tmpHpTaverna, ll tmpResult, ll enemySoldiers, long long p)
{

    // проверяем добитие, если будем играть через разрушение таверны
    while (enemySoldiers > 0 && tmpHpTaverna >= 0 && ourSoldiers > 0)
    {
        auto deltaOurAndKazarma = ourSoldiers - tmpHpTaverna; // 1
        if (deltaOurAndKazarma < 0)
        {
            deltaOurAndKazarma = 0;
        }
        tmpHpTaverna -= ourSoldiers - deltaOurAndKazarma; // 4 - 1 = 3
        enemySoldiers -= deltaOurAndKazarma;
        ourSoldiers -= enemySoldiers;
        if (tmpHpTaverna != 0)
        {
            enemySoldiers += p;
        }
        tmpResult++;
    }
    if (enemySoldiers <= 0 && tmpHpTaverna <= 0)
    {
        return {true, tmpResult};
    }
    return {false, -1};
}

/*
250    250    250   126
500 -> 250 -> 187 -> 0
187    187    187   124

4       1      2     3
*/
// 250 250
// 187 154
// 187 218
// 1
// 499
// 1

// 1
// 1
// 1
//  y - здоровье казармы
//  x - количество бойцов
//  p - прирощение вражеских бойцов от казармы
int CalculateQuantityRoundsForWin(long long x, long long y, long long p)
{
    int result = 1;
    if (MakeFirstTurn(x, y))
    {
        return 1;
    }
    long long enemySoldiers = p;
    std::vector<int> answers;
    while (x > 0 && y > 0 && p > 0)
    {
        if ((x * 2) > y)
        {

            auto canFinish0ff = CanFinishOff(x, y, result, enemySoldiers, p);
            if (canFinish0ff.first)
            {
                answers.push_back(canFinish0ff.second);
            }
        }
        auto deltaSoldiers = x - enemySoldiers; // 25-10=15
        if (deltaSoldiers < 0)
        {
            break;
        }
        enemySoldiers -= x - deltaSoldiers;
        x -= enemySoldiers;
        y -= deltaSoldiers;
        if (y > 0)
        {
            enemySoldiers += p;
        }
        if ((x == y && x == enemySoldiers) || (x == enemySoldiers && (x - enemySoldiers) < y))
        {
            break;
        }
        result++;
    }
    auto iter = std::min_element(answers.begin(), answers.end());
    if (iter != answers.end())
    {
        return *iter;
    }
    if (y <= 0 && enemySoldiers <= 0)
    {
        return result;
    }
    return -1;
}
// 499    499
// 500 -> 1  ->
// 499    499
int main()
{
    long long x, y, p;
    std::cin >> x;
    std::cin >> y;
    std::cin >> p;
    std::cout << CalculateQuantityRoundsForWin(x, y, p);
}
// 250
// 500
// 188
//  250    250    250     250    250    128    128
//  500 -> 250 -> 218 ->  186 -> 154 ->  0 ->   0
//  218    218    218     218    218    122     0
//          1      2       3      4      5      6
//  6
//  8
//  250     250    250    250    250
//  500 ->  250 -> 226 -> 202 -> 202
//  226     226    226    226