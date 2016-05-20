#include <stdio.h>

int f1(void)
{
    int x = 10;
    int y, z;
    x *= y = z = 4;
    printf("x = %d \n",x);
}


int f2(void)
{
    int x, y, z;
    x = 2;
    y = 1;
    z = 0;
    x = x && y || z;
    printf("x = %d \n",x);
}


int f3(void)
{
    int x = 2, y = 1, z = 0;
    z += -x++ + ++y;
    printf("x=%d  y=%d  z=%d  \n",x, y, z);
}


int f4(void)
{
    int x = 3, z = 0;
    z = x / ++x;
    printf("x=%d    z=%d  \n",x, z);
}


int f5(void)
{
    int x = 03, y = 02, z = 01;
    int a, b;

    a = x | y & ~z;
    b = x ^ y & ~z;
    printf("a=%d  b=%d \n", a, b);
}

int f6(void)
{
    int x = 01, y = -01;
    int a;
    a = ~x | x;
    y <<= 3;
    printf("a=%d  y=%d \n", a, y);

}



int f7(void)
{
    int x = 3, y = 2;
    int a;
    a = x < y ? x++ : y++;
    printf("x=%d  y=%d a=%d \n", x, y, a);
}


int f8(void)
{
    int x = -1, y = -1, z = -1;
    int a;
    a = ++x && ++y || ++z;
    printf("y=%d  a=%d \n", y, a);
}

int f9(void)
{
    int x1 = 5, x2 = 5, z=2, y =2;
    z = x1++;
    y = ++x2;
    printf("y=%d ; z=%d\n",y,z);

}
int main()
{
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
    f9();
    return 0;
}