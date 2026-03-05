#ifndef C_MODULES_STRING_H
#define C_MODULES_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

typedef struct String String;
struct String {
    Vector_char* Data;

    void (*Append)(String* Self, const char* C_String);
    void (*Print)(String* Self);
    void (*Read_Line)(String* Self);
    void (*Concat)(String* Self, String* Value);
    void (*Clear)(String* Self);
    void (*Destroy)(String* Self);
};

static void String_Append(String* Self, const char* C_String){
    size_t C_String_Index = 0;

    while(C_String[C_String_Index] != '\0'){
        Self->Data->Push(Self->Data, C_String[C_String_Index]);
        C_String_Index++;
    }
}

static void String_Print(String* Self){
    for(size_t i = 0; i < Self->Data->Size; i++){
        putchar(Self->Data->Data[i]);
    }
}

static void String_Read_Line(String* Self){
    int C;

    while((C = getchar()) != '\n' && C != EOF){
        Self->Data->Push(Self->Data, C);
    }
}

static void String_Concat(String* Self, String* Value){
    Self->Data->Concat(Self->Data, Value->Data);
}

static void String_Clear(String* Self){
    Self->Data->Clear(Self->Data);
}

static void Destroy_String(String* Self){
    Self->Data->Destroy(Self->Data);
    free(Self);
}

static String* New_String(){
    String* Temp = (String*)malloc(sizeof(String));

    Temp->Data = New_Vector_char();

    Temp->Append = String_Append;
    Temp->Print = String_Print;
    Temp->Read_Line = String_Read_Line;
    Temp->Concat = String_Concat;
    Temp->Clear = String_Clear;
    Temp->Destroy = Destroy_String;

    return Temp;
}

#endif