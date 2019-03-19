#include <cmath>
#include <fstream>

using namespace std;


double mysin(int N, double x)
{
    double answer = 0.0;
    double term = x;

    for(int i=1;i<=N;i++)
    {
        answer += term;
        term *= -x*x/((2*i+1)*2*i);
    }

    return answer;
}


int main()
{
    ofstream file("output.dat");
    double x = 0.0;;


    file.precision(20);
    for(unsigned int i=0;i<50;i++)
    {
        // atan(1)= pi/4
        x += 8.0*atan(1.0)/50.0;
        file << x << " " << sin(x) << " " << mysin(3,x) << endl;
    }
}