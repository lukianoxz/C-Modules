#include "../../Modules/String.h"

int main(){
    String* MyStr = New_String();

    MyStr->Append(MyStr, "Hello, World!\n");
    MyStr->Print(MyStr);

    MyStr->Destroy(MyStr);

    return 0;
}