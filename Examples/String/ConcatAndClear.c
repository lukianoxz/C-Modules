#include "../../Modules/String.h"

int main(){
    String* MyStr = New_String();
    String* MyStr_2 = New_String();

    MyStr->Append(MyStr, "Hello, ");
    MyStr_2->Append(MyStr_2, "World!\n");

    MyStr->Concat(MyStr, MyStr_2);
    MyStr->Print(MyStr);

    MyStr->Clear(MyStr);
    MyStr->Append(MyStr, "The string it's clear\n");
    MyStr->Print(MyStr);

    MyStr->Destroy(MyStr);
    MyStr_2->Destroy(MyStr_2);

    return 0;
}