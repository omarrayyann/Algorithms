#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <chrono>
using namespace std::chrono;

using namespace std;

long double square_fast(long long num)
{
    if (num < 0)
    {
        num = num * -1;
    }

    // base case
    if (to_string(num).length() == 1)
    {
        return num * num;
    }
    // divide to three parts
    string numStr = to_string(num);
    int numDigits = numStr.length();
    int numPerPart = (numDigits) / 3;
    int extraDigits = numDigits % 3;
    vector<string> parts;
    parts.resize(3, "");
    int powerM;
    if (numDigits == 2)
    {
        parts.at(0) = "0";
        parts.at(1) = to_string(num / 10);
        parts.at(2) = to_string(num % 10);
        powerM = 1;
    }
    else
    {
        if (extraDigits == 0)
        {
            parts.at(0) = numStr.substr(0, numPerPart);
            parts.at(1) = numStr.substr(numPerPart, numPerPart);
            parts.at(2) = numStr.substr(numPerPart * 2, numPerPart);
            powerM = numPerPart;
        }
        else if (extraDigits == 1)
        {
            parts.at(0) = numStr.substr(0, numPerPart + 1);
            parts.at(1) = numStr.substr(numPerPart + 1, numPerPart);
            parts.at(2) = numStr.substr(numPerPart * 2 + 1, numPerPart);
            powerM = numPerPart;
        }
        else if (extraDigits == 2)
        {
            parts.at(0) = numStr.substr(0, numPerPart);
            parts.at(1) = numStr.substr(numPerPart + 2, numPerPart + 1);
            parts.at(2) = numStr.substr(numPerPart * 2 + 1, numPerPart + 1);
            powerM = numPerPart + 1;
        }
    }
    long double a = parts.at(0) == "" ? 0 : stoi(parts.at(0));
    long double b = parts.at(1) == "" ? 0 : stoi(parts.at(1));
    long double c = parts.at(2) == "" ? 0 : stoi(parts.at(2));

    long double m = square_fast(c);
    long double n = square_fast(a);
    long double p = square_fast(a + b + c);
    long double q = square_fast(a - b + c);
    long double s = square_fast(4 * a - 2 * b + c);

    long double answer = pow(10, powerM * 4) * n + pow(10, powerM * 3) * (2 * n + (p + 3 * q - s) / 6 - m / 2) + pow(10, powerM * 2) * (-n + (p + q) / 2 - m) + pow(10, powerM * 1) * ((p / 3) - (2 * n) - q + (s / 6) + (m / 2)) + m;
    return answer;
}

int main()
{

    int number = 456;
    auto start = high_resolution_clock::now();
    cout << square_fast(456) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
}