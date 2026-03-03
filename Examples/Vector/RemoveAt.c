#include "../../Modules/Vector.h"
#include "../../Modules/Utils.h"

int main(){
    Vector_int* Mv = New_Vector_int();

    Mv->Push(Mv, 2);
    Mv->Push(Mv, 7);
    Mv->Push(Mv, 14);
    Mv->Push(Mv, 1);
    Mv->Push(Mv, 9);

    printf("Size before: %zu\n", Mv->Size);
    Print_Int_Vector(Mv, 1);
    int Removed = Mv->RemoveAt(Mv, 2);
    printf("Size after: %zu\n", Mv->Size);
    Print_Int_Vector(Mv, 1);
    printf("Removed element: %d\n", Removed);

    Mv->Destroy(Mv);

    return 0;
}