#include "../../Modules/Vector.h"
#include "../../Modules/Utils.h"

int main(){
    Vector_int* Mv = New_Vector_int();
    Mv->Push(Mv, 2);
    Mv->Push(Mv, 9);
    Mv->Push(Mv, 7);

    Print_Int_Vector(Mv, 1);
    int Pop_Element = Mv->Pop(Mv);
    Print_Int_Vector(Mv, 1);

    printf("Removed element: %d\n", Pop_Element);

    Mv->Destroy(Mv);

    return 0;
}