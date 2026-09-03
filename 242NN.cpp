#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double sigmoid(double x){
    return 1.0 / (1.0 + exp(-x));
}

int main(){

    vector<vector<double>> input = {
        {0,0},
        {0,1},
        {1,0},
        {1,1}
    };

    vector<double> target1 = {0,0,0,1};
    vector<double> target2 = {0,1,1,1};

    double n = 0.5;

    double w11=0.1, w12=0.2, w13=0.3, w14=0.4;
    double w21=0.4, w22=0.3, w23=0.2, w24=0.1;

    double w01=0.5, w02=0.6, w03=0.7, w04=0.8;

    double v1a=0.1, v2a=0.2, v3a=0.1, v4a=0.2;
    double v1b=0.2, v2b=0.4, v3b=0.4, v4b=0.2;

    double v0a=0.3, v0b=0.3;

    cout << fixed << setprecision(4);

    for(int epoch=0; epoch<1500; epoch++){

        double SSE=0;

        double dw11=0,dw12=0,dw13=0,dw14=0;
        double dw21=0,dw22=0,dw23=0,dw24=0;
        double dw01=0,dw02=0,dw03=0,dw04=0;

        double dv1a=0,dv2a=0,dv3a=0,dv4a=0;
        double dv1b=0,dv2b=0,dv3b=0,dv4b=0;
        double dv0a=0,dv0b=0;

        for(int i=0;i<4;i++){

            double a1=w11*input[i][0]+w21*input[i][1]+w01;
            double a2=w12*input[i][0]+w22*input[i][1]+w02;
            double a3=w13*input[i][0]+w23*input[i][1]+w03;
            double a4=w14*input[i][0]+w24*input[i][1]+w04;

            double z1=sigmoid(a1);
            double z2=sigmoid(a2);
            double z3=sigmoid(a3);
            double z4=sigmoid(a4);

            double aa=v1a*z1+v2a*z2+v3a*z3+v4a*z4+v0a;
            double ab=v1b*z1+v2b*z2+v3b*z3+v4b*z4+v0b;

            double e1=target1[i]-aa;
            double e2=target2[i]-ab;

            SSE+=e1*e1+e2*e2;

            double d1=(e1*v1a+e2*v1b)*z1*(1-z1);
            double d2=(e1*v2a+e2*v2b)*z2*(1-z2);
            double d3=(e1*v3a+e2*v3b)*z3*(1-z3);
            double d4=(e1*v4a+e2*v4b)*z4*(1-z4);

            dw11+=d1*input[i][0];
            dw21+=d1*input[i][1];
            dw01+=d1;

            dw12+=d2*input[i][0];
            dw22+=d2*input[i][1];
            dw02+=d2;

            dw13+=d3*input[i][0];
            dw23+=d3*input[i][1];
            dw03+=d3;

            dw14+=d4*input[i][0];
            dw24+=d4*input[i][1];
            dw04+=d4;

            dv1a+=e1*z1;
            dv2a+=e1*z2;
            dv3a+=e1*z3;
            dv4a+=e1*z4;

            dv1b+=e2*z1;
            dv2b+=e2*z2;
            dv3b+=e2*z3;
            dv4b+=e2*z4;

            dv0a+=e1;
            dv0b+=e2;
        }

        dw11/=4; dw12/=4; dw13/=4; dw14/=4;
        dw21/=4; dw22/=4; dw23/=4; dw24/=4;
        dw01/=4; dw02/=4; dw03/=4; dw04/=4;

        dv1a/=4; dv2a/=4; dv3a/=4; dv4a/=4;
        dv1b/=4; dv2b/=4; dv3b/=4; dv4b/=4;
        dv0a/=4; dv0b/=4;

        w11+=n*dw11;
        w12+=n*dw12;
        w13+=n*dw13;
        w14+=n*dw14;

        w21+=n*dw21;
        w22+=n*dw22;
        w23+=n*dw23;
        w24+=n*dw24;

        w01+=n*dw01;
        w02+=n*dw02;
        w03+=n*dw03;
        w04+=n*dw04;

        v1a+=n*dv1a;
        v2a+=n*dv2a;
        v3a+=n*dv3a;
        v4a+=n*dv4a;

        v1b+=n*dv1b;
        v2b+=n*dv2b;
        v3b+=n*dv3b;
        v4b+=n*dv4b;

        v0a+=n*dv0a;
        v0b+=n*dv0b;

        cout << "Epoch " << epoch
             << " | SSE = " << SSE << endl;
    }

    cout << "\nFinal W:\n";
    cout << w11 << " " << w12 << " "
         << w13 << " " << w14 << endl;
    cout << w21 << " " << w22 << " "
         << w23 << " " << w24 << endl;

    cout << "\nFinal V-a:\n";
    cout << v1a << " " << v2a << " "
         << v3a << " " << v4a << endl;

    cout << "\nFinal V-b:\n";
    cout << v1b << " " << v2b << " "
         << v3b << " " << v4b << endl;

    return 0;
}