#include <bits/stdc++.h>

using namespace std;

int ToHop(int n, int k)
{
	if (k == 0 || k == n)
		return 1;
	return (ToHop(n - 1, k - 1) + ToHop(n - 1, k));
}

float Bernoulli(int n)
{
    if (n == 0)
        return 1;
    else
    {
        float t = 1;
        for (int i = 0; i < n; i++)
            t += ToHop(n, i) * Bernoulli(i) / (n - i + 1);
        return float(1 - t);
    }
}

float Tangent(int i)
{
    return float((pow(2, 2 * i) * (pow(2, 2 * i) - 1) * abs(Bernoulli(2 * i))) / (2 * i));
}

void TBernoulli()
{
    for (int i = 0; i < 10; i++)
        cout << i << " " << Bernoulli(i) << "\n";
}

void TTangent()
{
    for (int i = 1; i < 10; i++)
        cout << i << " " << abs(Bernoulli(2 * i)) << " " << Tangent(i) << endl;
}

int EulerNumbers(int  n)
{
    if (n == 0)
        return 1;
    else
    {
        float t = 0;
        for (int i = 0; i < n; i++)
            t += ToHop(n, i) * EulerNumbers(i) * pow(2,(n - i - 1));
        return float(1 - t);
    }
}
void TEulerNumbers()
{
    for (int i = 0; i < 15; i+=2)
    {
        cout << i << " " << abs(EulerNumbers(i)) << endl;
    }
}
int main()
{
    TBernoulli();
    cout<<endl;
    TTangent();
    cout<<endl;
    TEulerNumbers();
    return 1;
}
