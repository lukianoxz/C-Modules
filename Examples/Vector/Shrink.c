#include "../../Modules/Vector.h"

int main(){
    Vector_int* Mv = New_Vector_int();

    Mv->Push(Mv, 1);
    Mv->Push(Mv, 2);
    Mv->Push(Mv, 21);
    Mv->Push(Mv, 73);
    Mv->Push(Mv, 9);
    Mv->Push(Mv, 1);
    Mv->Push(Mv, 34);
    Mv->Push(Mv, 1);
    Mv->Push(Mv, 4);
    Mv->Push(Mv, 7);

    printf("Vector current capacity before shrink: %zu\n", Mv->Capacity);
    Mv->Shrink(Mv);
    printf("Vector current capacity after shrink: %zu\n", Mv->Capacity);

    Mv->Destroy(Mv);

    return 0;
}