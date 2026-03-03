#include "../../Modules/Vector.h"

int main(){
    Vector_int* Mv = New_Vector_int();

    if (Mv->IsEmpty(Mv)){
        printf("The vector is empty\n");
    } else {
        printf("The vector not is empty\n");
    }

    Mv->Push(Mv, 3);
    printf("Pushed one element in the vector trying the test again\n");

    if (Mv->IsEmpty(Mv)){
        printf("The vector is empty\n");
    } else {
        printf("The vector not is empty\n");
    }

    Mv->Destroy(Mv);

    return 0;
}