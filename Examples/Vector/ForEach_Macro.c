#include "../../Modules/Vector.h"

CREATE_FOREACH(Print_Int_Vector_ForEach, int){
    printf("%d", Value);
    if ((Index + 1) < Self->Size){
        printf(", ");
    } else {
        printf("\n");
    }
}

void Insert_Int_Elements(Vector_int* Vector, size_t Amount){
    for(size_t i = 0; i < Amount; i++){
        Vector->Push(Vector, (int)i);
    }
}

int main(){
    Vector_int* Mv = New_Vector_int();

    Insert_Int_Elements(Mv, 11);

    Mv->ForEach(Mv, Print_Int_Vector_ForEach);

    Mv->Destroy(Mv);

    return 0;
}