//#include <iostream>
//using namespace std;
//
//
//
//double f(double x)
//{
//	return (sin(x)*sin(x)-3*cos(x));
//}
//
//
//
//int main()
//{
//	double a=1, b=7;
//	int n=1000;
//	
//	double s = (f(a) + f(b)) / 2.;
//	double h = (b - a) / n;
//	for (int i = 1; i <= n - 1; i++)
//	{
//		s += f(a + i * h);
//	}
//	double I = h * s;
//	cout << I << endl;
//
//	return 0;
//}
#include <iostream>
using namespace std;



double f(double x)
{
	return (sin(x) * sin(x) - 3 * cos(x));
}



int main()
{
	double a = 1, b = 7;
	cout << "Введите n" << endl;
	
	
	int n;
	cin >> n;

	double s = (f(a) + f(b)) / 2.;
	double h = (b - a) / n;
	double x1, x2, x;
	double I;
	for (int i = 1; i <= n; i++)
	{
		x1 = a + (i - 1) * h;
		x2 = a + i * h;
		x = (x1 + x2) / 2.;
		s += f(x);
	}
	I = h * s;
	
	cout<<"rezult: " << I << endl;

	return 0;
}