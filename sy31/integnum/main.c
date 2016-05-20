#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 x(k+1) = x(k)+v(k).dt.cosθ(k)
 y(k+1) = y(k)+v(k).dt.sinθ(k)
 θ(k+1) = θ(k)+ω(k).dt
 */

double fx(double x, double v, int dt, double theta )
{

    return x+v*dt*cos(theta);
}

double fy(double y, double v, int dt, double theta )
{

    return y+v*dt*sin(theta);
}

double ftheta(double w, int dt, double theta )
{

    return theta+w*dt;
}

int main(int argc, const char * argv[])
{
    printf("Reconstruction de la position du robot par intégration numérique!\n");

    double x=0.0,y=0.0,theta=0.0;
    double v = 2.0; // m/s
    double w = 0.1; // rad/s
    int dt = 1; // s
    int k;
    printf("k\tx          \ty          \ttheta\n");
    for (k = 0; k<10; k++) {
        printf("%3d\t%.6f\t%.6f\t%.6f\n",k,x,y,theta);
        x = fx(x, v, dt, theta);
        y = fy(y, v, dt, theta);
        theta = ftheta(w, dt, theta);
    }


    return 0;
}

