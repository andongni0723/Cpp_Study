#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class Car
{
public:
    bool in;
    int in_time;
    string car_no;

    Car(int in_time, string car_no, bool in = true)
    {
        this->in = in;
        this->in_time = in_time;
        this->car_no = car_no;
    }
};

int money(int before_time, int after_time)
{
    // time to minute
    after_time = (after_time / 100 * 60) + (after_time % 100);
    before_time = (before_time / 100 * 60) + (before_time % 100);
    int parking_time = after_time - before_time;

    return parking_time * 8;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t1, t2, time;
    string car_no;
//    Car current_car;
    vector<Car> vec;

    cin >> n;

    bool is_find = false;
//    int min_time;
    for (int i = 0; i < n; i++)
    {
        cin >> t1;
        switch (t1)
        {
            case 0: // in car
                cin >> time >> car_no;
                vec.emplace_back(Car(time, car_no));
                cout << "done!" << endl;
                break;

            case 1: // out car
                cin >> time >> car_no;

                is_find = false;
                for(auto &it : vec)
                {
                    if(it.car_no == car_no && it.in)
                    {
                        cout << money(it.in_time, time) << endl;
                        it.in = false;
                        is_find = true;
                        break;
                    }
                }

                if(!is_find)
                    cout << -1 << endl;
                break;

            case 2: // Find
                cin >> t2;

                switch(t2)
                {
                    case 1: //P 1最早進還沒離開
                    {
                        int min_time = 100000;
                        string min_time_no;
                        for (auto it: vec)
                        {
                            if (it.in_time < min_time && it.in)
                            {
                                min_time = it.in_time;
                                min_time_no = it.car_no;
                            }
                        }

                        if (min_time == 100000)
                            cout << -1 << endl;
                        else
                            cout << min_time_no << endl;
                        break;
                    }

                    case 2: //2最晚進入離開了
                    {
                        int max_time = 0;
                        string max_time_no;
                        for(auto it : vec)
                        {
                            if(it.in_time > max_time && !it.in)
                            {
                                max_time = it.in_time;
                                max_time_no = it.car_no;
                            }
                        }

                        if(max_time == 0)
                            cout << -1 << endl;
                        else
                            cout << max_time_no << endl;
                        break;
                    }

                    case 3: //3查車牌進入時間
                    {
                        cin >> car_no;

                        is_find = false;
                        for(auto it : vec)
                        {
                            if(it.car_no == car_no)
                            {
                                is_find = true;
                                cout << it.in_time << endl;
                                break;
                            }
                        }

                        if(!is_find)
                            cout << -1 << endl;
                        break;
                    }
                }

        }
    }
}