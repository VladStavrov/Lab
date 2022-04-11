#include <iostream>
using namespace std;



double f(double x)
{
	return (sin(x) * sin(x) - 3 * cos(x));
}



int main()
{
	double a = 1, b = 7;
	int n = 2;
	double eps = 0.1;
	double s = (f(a) + f(b)) / 2.;
	double h = (b - a) / n;
	double x1, x2, x;
	double I1=1,I2=2;
	for (int i = 1; i <= n; i++)
	{
		x1 = a + (i - 1) * h;
		x2 = a + i * h;
		x = (x1 + x2) / 2.;
		s += f(x);
	}
	I1 = h * s;
	I2 = I1 + 1;
	int k = 1;

	while (fabs(I1-I2)>=eps) {
		n *= 2;
		h = (b - a) / n;
		if (k != 1) {
			I1 = I2;
		}
		s = 0;
		for (int i = 1; i <= n-1; i++)
		{
			x1 = a + (i - 1) * h;
			x2 = a + i * h;
			x = (x1 + x2) / 2.;
			s += f(x);
		}
		
			I2 = h * s;
		
		 
		 
		 k++;
	}
	cout << I2<<endl<<n << endl;

	return 0;
}