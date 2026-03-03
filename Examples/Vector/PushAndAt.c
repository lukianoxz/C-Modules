#include <stdio.h>
#include "../../Modules/Vector.h"

int main(){
    Vector_int* MyVec = New_Vector_int();

    MyVec->Push(MyVec, 2);

    printf("%d\n", MyVec->At(MyVec, 0));

    MyVec->Destroy(MyVec);

    return 0;
}