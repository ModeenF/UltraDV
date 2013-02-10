//main of test routines

#include "testclass.h"

main(){
test *testme = new test();
testme->testprint();

test *testme2 = new test(2, 2.0);
testme2->testprint();

}


