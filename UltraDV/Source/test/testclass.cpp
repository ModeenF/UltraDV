// code for testclass
#include <stdio.h>

#include "testclass.h"


test::test(){
	a = 1;
	b = 1.0;
	c = (bool)1;
}

test::test(int a1, float b1){
	a = a1;
	b = b1;
}

test::~test(){
} 

void test::testprint(){
	printf("testprint: a=%d, b=%f\n",a,b);
}
