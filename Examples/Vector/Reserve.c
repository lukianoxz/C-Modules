#include "../../Modules/Vector.h"

int main(){
    Vector_int* Mv = New_Vector_int();

    printf("Current capacity: %zu\n", Mv->Capacity);
    Mv->Reserve(Mv, 100);
    printf("New capacity: %zu\n", Mv->Capacity);
    
    Mv->Destroy(Mv);

    return 0;
}