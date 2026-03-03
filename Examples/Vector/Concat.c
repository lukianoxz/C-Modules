#include "../../Modules/Vector.h"
#include "../../Modules/Utils.h"

int main(){
    Vector_int* MyIntList_1 = New_Vector_int();

    MyIntList_1->Push(MyIntList_1, 1);
    MyIntList_1->Push(MyIntList_1, 2);
    MyIntList_1->Push(MyIntList_1, 3);
    MyIntList_1->Push(MyIntList_1, 4);
    MyIntList_1->Push(MyIntList_1, 5);

    Vector_int* MyIntList_2 = New_Vector_int();

    MyIntList_2->Push(MyIntList_2, 6);
    MyIntList_2->Push(MyIntList_2, 7);
    MyIntList_2->Push(MyIntList_2, 8);
    MyIntList_2->Push(MyIntList_2, 9);
    MyIntList_2->Push(MyIntList_2, 10);

    Print_Int_Vector(MyIntList_1, 1);

    MyIntList_1->Concat(MyIntList_1, MyIntList_2);

    Print_Int_Vector(MyIntList_1, 1);

    MyIntList_1->Destroy(MyIntList_1);
    MyIntList_2->Destroy(MyIntList_2);

    return 0;
}