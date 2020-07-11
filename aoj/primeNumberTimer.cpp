#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

/*
*並列処理ができなくてうまくいかない
*waitTimer()を並列で処理すれば、いい感じに動くと思っている。
*/

bool canCalc = true;
void waitTimer(int);

int main()
{
    cout << "How long do you want to measure ?" << endl;
    int waitTime;
    cin >> waitTime;
    vector<int> n;
    bool flag = false;
    while (canCalc)
    {
        for (int i = 2; i < waitTime * 4000; i++)
        {
            flag = true;
            for (int j = 2; j < i * 4000; j++)
            {
                if (j < i)
                {
                    if (i % j == 0)
                    {
                        flag = false;
                    }
                }
            }
            if (flag)
                n.push_back(i);
        }
    }
    cout << "Good work!" << endl;
    for (auto i = n.begin(); i != n.end(); i++)
    {
        cout << *i << endl;
    }
    return 0;
}

void waitTimer(int waitTime){
    sleep(waitTime);
    canCalc = false;
}