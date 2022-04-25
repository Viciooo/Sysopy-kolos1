#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dlfcn.h>

int main (int l_param, char * wparam[]){
  int i;
/*
1) otworz biblioteke
2) przypisz wskaznikom f1 i f2 adresy funkcji z biblioteki fun1 i fun2
3) stworz Makefile kompilujacy biblioteke 'bibl1' ladowana dynamicznie
   oraz kompilujacy ten program
*/



  for (i=0; i<10; i++)
    printf("wynik fun1(2,%d) to %d, a wynik fun2(2,%d) to %d\n", i, f1(2,i), i, f2(2,i));
  return 0;
}
