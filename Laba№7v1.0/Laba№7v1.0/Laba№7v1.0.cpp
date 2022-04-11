#include <iostream>
using namespace std;



double F(double);
double FindRoot(double, double, double);

int main()
{
	setlocale(LC_ALL, "rus");
	double a = -7, b = 3, h = 0.1, eps = 0.001;
	int n = 0;
	int i = 1;
	cout << "При параметрах:\na = "<< a<< "\nb = " <<b << "\nh = "<<h<< "\ne = " <<eps<< "\n\n";
	for (double x = a; x <= b; x += h)
	{
		cout << i << ")" << "\tx=" << x << "\t\tF(x)=" << F(x) << endl;
		i++;
		if (F(x) * F(x + h) < 0)
		{
			n++;
			cout << "*********************" << endl;
			cout << "x" <<n<< " = " <<FindRoot(x + h, eps, h)<< "\n";
			cout << "*********************" << endl;
		}
	}
	if (!n) cout << "Корней нет\n";
}

double F(double x)
{
	return sin(x)*sin(x) - 3 * cos(x);
}

double FindRoot(double x0, double eps, double q)
{
	double x1 = x0 - F(x0) * q / (F(x0) - F(x0 - q));
	while (fabs(x1 - x0) > eps)
	{
		x0 = x1;
		x1 = x1 - F(x1) * q / (F(x1) - F(x1 - q));
	}
	return x0;
}
