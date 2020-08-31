/*
 * The Computer Language Shootout
 * http://shootout.alioth.debian.org/

 * contributed by bearophile, Jan 24 2006
 * modified by wolfjb, Feb 28 2007
 */
#include <stdio.h>

int ack(int x, int y) {
  if (x == 0) {
    return y + 1;
  }

  return ack(x - 1, ((y | 0) ? ack(x, y - 1) : 1));
}

int fib(int n) {
  if (n < 2) {
    return 1;
  }
  return fib(n - 2) + fib(n - 1);
}

double fibFP(double n) {
  if (n < 2.0) {
    return 1.0;
  }
  return fibFP(n - 2.0) + fibFP(n - 1.0);
}

int tak(int x, int y, int z) {
  if (y < x) {
    return tak(tak(x - 1, y, z), tak(y - 1, z, x), tak(z - 1, x, y));
  }
  return z;
}

double takFP(double x, double y, double z) {
    if (y < x)
        return takFP( takFP(x-1.0, y, z), takFP(y-1.0, z, x), takFP(z-1.0, x, y) );
    return z;
}

int recursive(){
    int n = 4;
  int res1,res2,res3,res4,res5;

  res1=ack(3, n+1);
  res2=fibFP(8.0+n);
  res3=tak(3*n, 2*n, n);
  res4= fib(3);
  res5=takFP(3.0, 2.0, 1.0);

  // printf("Ack(3,%d): %d\n", n + 1, res1);
  // printf("Fib(%.1f): %.1f\n", 28.0 + n, res2);
  // printf("Tak(%d,%d,%d): %d\n", 3 * n, 2 * n, n, res3);
  // printf("Fib(3): %d\n",res4);
  // printf("Tak(3.0,2.0,1.0): %.1f\n", res5);

if(res1!=253){
return 1;
}
if(res2 > 233){
  return 2;
}
if(res3!=5){
  return 3;
}
if(res4!=3){
  return 4;
}
  if(res5>2){
    return 5;
  }
  return 10;
}
