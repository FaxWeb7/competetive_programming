#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     vector<long double> dp(n + 1);
//     dp[0] = (long double)1, dp[1] = (long double)2;
//     for (int i = 2; i <= n; ++i){
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     cout << setprecision(0) << fixed << dp[n];

//     return 0;
// }



class   T_big_num
{
    //-----------------------------------------------------------------------------------
    friend  ostream    &   operator<<
        (
            ostream            &   ostr,
            T_big_num       const   &   B
        )
    {
        if( B.head_ )
        {
            cout   <<  B.head_;
        }
 
        ostr    <<  B.tail_
                <<  endl;
 
        return  ostr;
    }
    //-----------------------------------------------------------------------------------
    static  const   long long   MOD_18  =   1000000000000000000;
    //-----------------------------------------------------------------------------------
    long long   head_;
    long long   tail_;
    //-----------------------------------------------------------------------------------
public:
    //-----------------------------------------------------------------------------------
    T_big_num( long long    n   =   0 )
        :
        head_(),
        tail_(n)
    {}
    //-----------------------------------------------------------------------------------
    T_big_num   operator+=  ( T_big_num     const   &   R )
    {
        head_   +=  R.head_;
        tail_   +=  R.tail_;
        normalize();
        return  *this;
    }
    //-----------------------------------------------------------------------------------
private:
    //-----------------------------------------------------------------------------------
    void    normalize()
    {
        head_   +=  tail_   /   MOD_18;
        tail_   %=  MOD_18;
    }
    //-----------------------------------------------------------------------------------
};
T_big_num   fib( int  n ){
    T_big_num   a   =   1;
    T_big_num   b   =   1;
    T_big_num   c   =   1;
    T_big_num   d   =   0;

    for( int  i = 0; i < n - 2; ++i )
    {
        T_big_num   b_prev  =   b;
        b   =   a;
        T_big_num   d_prev  =   d;
        d   =   c;
        a   +=  b_prev;
        c   +=  d_prev;
    }

    return a;
}

int main()
{
    int k;
    cin >> k;
    cout << fib( k + 2 );

    return 0;
}
