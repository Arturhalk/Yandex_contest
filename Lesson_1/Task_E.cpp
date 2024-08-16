// k друзей организовали стартап по производству укулеле для кошек.
// На сегодняшний день прибыль составила
// n рублей. Вы, как главный бухгалтер компании,
// хотите в каждый из ближайших
// dvдней приписывать по одной цифре в конец числа,
// выражающего прибыль.
// При этом в каждый из дней прибыль должна делиться на k.
#include <iostream>
#include <vector>
unsigned long long convert(std::string a, char b);
std::string profitСounter(unsigned long long n, unsigned long long k,
                          unsigned long d) {
    int same = n % k;
    std::string a = std::to_string(n);
    bool flag = true;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < 10; ++j) {
            long some = (same * 10 + j) % k;
            if (some == 0) {
                a += std::to_string(j);
                same = some;
                flag = false;
                break;
            }
        }
        if (flag) {
            return "-1";
        }
        flag = true;
    }
    return a;
}

int main() {
    long d;
    long long n;
    long long k;
    std::cin >> n >> k >> d;
    std::cout << profitСounter(n, k, d);
}
//  PYTHON
//   n,k,d =map(int,input().split())
//   nowmod = n%k
//   ans =[n]
//   flag = True
//   for i in range(d):
//       for j in range(10):
//           newmod = (nowmod * 10 + j) % k
//           if newmod == 0:
//               ans.append(j)
//               nowmod = newmod
//               break
//       else:
//           flag = False
//   if flag:
//       print(''.join(map(str,ans)))
//   else:
//       print(-1)
//   n  k  d
//   21 108 1
//   10 5 2 -> 1000
//   10 6 3 -> 10200
//   29420920 98069736 69929