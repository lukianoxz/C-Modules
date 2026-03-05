#include "../../Modules/String.h"

int main(){
    String* Greeting = New_String();

    printf("Say your name: ");

    Greeting->Append(Greeting, "Hello, ");
    Greeting->Read_Line(Greeting);
    Greeting->Append(Greeting, ", Nice to meet you!\n");
    Greeting->Print(Greeting);

    Greeting->Destroy(Greeting);

    return 0;
}