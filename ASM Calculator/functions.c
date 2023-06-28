#include "head.h"

int main(int argc, char argv[]) {
  printf(">>>>>>>>>>>>>>>>>>>>>>>\n");
  while ( iterate() != 0 ) { printf("\n>>>>>>>>>>>>>>>>>>>>>>>\n"); }
}  // main():

int iterate() {
  int cmd; printf("1.add 2.min 3.mul 4.div\ncmd> ");
  if ( 0 == scanf("%d", &cmd) ) { return -1; }

  int num1; printf("num1 > ");
  if ( 0 == scanf("%d", &num1) ) { return -1; }
  int num2; printf("num2 > ");
  if ( 0 == scanf("%d", &num2) ) { return -1; }

  switch ( cmd ) {
  default: printf("wrong typped\n"); break;
  case 1: printf("result: %d", cal_add(num1, num2)); break;
  case 2: printf("result: %d", cal_min(num1, num2)); break;
  case 3: printf("result: %d", cal_mul(num1, num2)); break;
  case 4:
    int rmd; int inq = cal_div(num1, num2, &rmd);
    printf("result: %d , %d", inq, rmd); break;
  case 5: return 0;
  }  // switch
}  // main():

int cal_add(int num1, int num2) {
  int sum;

  __asm__ (
	   "movl %1, %%eax\n\t"
	   "addl %2, %%eax\n\t"
	   "movl %%eax, %0\n\t"
	   : "=r" (sum)
	   : "r" (num1), "r" (num2)
	   : "%eax"
	   );
  return sum;
}  // cal_add():
int cal_mul(int num1, int num2) {
  int product;
  __asm__ (
        "movl %1, %%eax\n\t"
        "imull %2, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=r" (product)
        : "r" (num1), "r" (num2)
        : "%eax"
    );
  return product;
}  // cal_min():
int cal_min(int num1, int num2) {
  int difference;
  __asm__ (
        "movl %1, %%eax\n\t"
        "subl %2, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=r" (difference)
        : "r" (num1), "r" (num2)
        : "%eax"
    );

  return difference;
}  // cal_min():
int cal_div(int num1, int num2, int *rmd) {
  __asm__ (
        "movl %1, %%eax\n\t"
        "cdq\n\t"         // sign-extend %eax to %edx:%eax
        "idivl %2\n\t"     // divide %edx:%eax by num2
        "movl %%edx, %0\n\t"
        : "=r" (*rmd)
        : "r" (num1), "r" (num2)
        : "%eax", "%edx"
    );
  
  int quotient;
  __asm__ (
        "movl %1, %%eax\n\t"
        "cdq\n\t"
        "idivl %2\n\t"
        "movl %%eax, %0\n\t"
        : "=r" (quotient)
        : "r" (num1), "r" (num2)
        : "%eax", "%edx"
    );
  return quotient;
}  // cal_div():
