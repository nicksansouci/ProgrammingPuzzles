#include <iostream> 
#include <string>
#include <unordered_map>
using namespace std;
class GridTraveler
{
    public:
    GridTraveler(int m, int n);
    private:
    int m;
    int n;
};

int GridTraveler(int m, int n)
{
    unordered_map<string, int> memo;
    string gridkey = to_string(m) + ',' + to_string(n);
    if (memo.count(gridkey) != 0) return memo[gridkey];
    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m == 0 || n == 0)
    {
        return 0;
    }
    memo.insert(make_pair(gridkey, GridTraveler(m - 1, n) + GridTraveler(m, n - 1)));
    return memo[gridkey];

}



int main() 
{
    cout << GridTraveler(10, 10) << endl;
}