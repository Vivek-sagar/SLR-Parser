#include <iostream>

using namespace std;

class hello
{
    public:
        int a;
        int b;
    
    void hai(hello g)
    {
        a = g.b;
    }
};

int main()
{
    hello x, y;
    x.b = 10;
    y.b = 20;
    x.hai(y);
    cout << x.a << " " << x.b;
    return 0;
}
