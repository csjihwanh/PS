#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

double x[5], y[5];
void swap(double* a, double* b) {
	double temp;
	temp = *a;
	*a= *b;
	*b = temp;
}

int checkCross();
double calcGrad(double* x, double* y);

class Function {
	double m_x[3];
	double m_y[3];
	
	double m_alpha =0;
	double m_beta =0;
	
	public:
	void setFunction(double* x, double* y) {
		for(int i = 1; i <=2 ; i++) {
			m_x[i]=x[i-1];
			m_y[i]=y[i-1];
		}
		m_alpha = calcGrad(&m_x[1], &m_y[1]);
		m_beta = (m_alpha * m_x[1]) - m_y[1];
	}
	
	double getAlpha() {
		return m_alpha;
	}
	
	double getBeta() {
		return m_beta;
	}
	
	double getValue(double x) {
		return ((m_alpha * x) + m_beta);
	}
};

Function f1, f2;



int main (void) {

	freopen("/workspace/PS_Git/BOJ/17386/input.txt","r",stdin);
	double temp;
	for(int i = 1; i<=4; i++) scanf("%lf %lf", &x[i], &y[i]);
	
	for(int i = 1; i <=3 ; i+=2) 
		if(x[i]>x[i+1]) {
			swap(&x[i], &x[i+1]);
			swap(&y[i], &y[i+1]);
		}
	
	f1.setFunction(&x[1], &y[1]);
	f2.setFunction(&x[3], &y[3]);
	
	cout<<checkCross()<<endl;
	return 0;
	
}

double calcGrad(double* x, double* y) {
	for(int i =0; i <=1; i++) {
		printf("calcGrad : x[%d] = %lf\n", i,x[i]);
		printf("calcGrad : y[%d] = %lf\n", i,y[i]);
	}
	if(x[0] == x[1]) return INF;
	else return (y[1]-y[0])/(x[1]-x[0]);
}

int checkCross() {
	double crossX, crossY;
	double alpha[3], beta[3];
	
	alpha[1] = f1.getAlpha(); alpha[2] = f2.getAlpha();
	beta[1] = f1.getBeta(); beta[2] = f2.getBeta();
	
	cout<<alpha[1]<<endl<<alpha[2]<<endl;
	cout<<beta[1]<<endl<<beta[2]<<endl;
	if(alpha[1] == alpha[2]) //parallel
		return 0;
	
	crossX = (beta[2]-beta[1])/(alpha[2]-alpha[1]);
	crossY = f1.getValue(crossX);
	
	if(crossX >=x[1] && crossX<=x[2]) return 1;
	return 0;
}

