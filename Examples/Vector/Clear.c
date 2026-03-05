#include "../../Modules/Vector.h"
#include "../../Modules/Utils.h"

int main(){
    Vector_int* Mv = New_Vector_int();

    Mv->Push(Mv, 2);
    Mv->Push(Mv, 9);
    Mv->Push(Mv, 1);

    Print_Int_Vector(Mv, 1);

    Mv->Clear(Mv);

    Mv->Push(Mv, 7);
    Mv->Push(Mv, 3);
    Mv->Push(Mv, 9);

    Print_Int_Vector(Mv, 1);

    Mv->Destroy(Mv);

    return 0;
}