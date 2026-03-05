#ifndef C_MODULES_VECTOR_H
#define C_MODULES_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define DEFINE_VECTOR(TYPE) \
typedef struct Vector_##TYPE Vector_##TYPE; \
struct Vector_##TYPE { \
    TYPE* Data; \
    size_t Size; \
    size_t Type_Size; \
    size_t Capacity; \
\
    void (*Push)(Vector_##TYPE* Self, TYPE Value); \
    TYPE (*At)(Vector_##TYPE* Self, size_t Value); \
    void (*Concat)(Vector_##TYPE* Self, Vector_##TYPE* Value); \
    TYPE (*Pop)(Vector_##TYPE* Self); \
    void (*ForEach)(Vector_##TYPE* Self, void (*Callback)(Vector_##TYPE* Self, size_t Index, TYPE Value)); \
    TYPE (*RemoveAt)(Vector_##TYPE* Self, size_t Index); \
    void (*Reserve)(Vector_##TYPE* Self, size_t New_Capacity); \
    int (*IsEmpty)(Vector_##TYPE* Self); \
    void (*Shrink)(Vector_##TYPE* Self); \
    void (*Clear)(Vector_##TYPE* Self); \
    void (*Destroy)(Vector_##TYPE* Self); \
}; \
\
static void Vector_##TYPE##_Push(Vector_##TYPE* Self, TYPE Value){ \
    if (Self->Size == Self->Capacity){ \
        Self->Capacity *= 2; \
        Self->Data = (TYPE*)realloc(Self->Data, Self->Type_Size * Self->Capacity); \
    } \
\
    Self->Data[Self->Size] = Value; \
    Self->Size++; \
} \
static TYPE Vector_##TYPE##_At(Vector_##TYPE* Self, size_t Value){ \
    if (Self->Size == 0){ \
        fprintf(stderr, "Erro [C-Modules]: tentativa de acessar um vetor sem elementos\n"); \
        exit(1); \
    } \
    if (Value >= Self->Size){ \
        fprintf(stderr, "Erro [C-Modules]: tentativa de acessar o indice (%zu) fora do limite do vetor (%zu)\n", Value, Self->Size - 1); \
        exit(1); \
    } \
    return Self->Data[Value]; \
} \
static void Vector_##TYPE##_Concat(Vector_##TYPE* Self, Vector_##TYPE* Value){ \
    for(size_t i = 0; i < Value->Size; i++){ \
        Self->Push(Self, Value->At(Value, i)); \
    } \
} \
static TYPE Vector_##TYPE##_Pop(Vector_##TYPE* Self){ \
    TYPE Last_Element = Self->At(Self, Self->Size - 1); \
    Self->Size--; \
    return Last_Element; \
} \
static void Vector_##TYPE##_ForEach(Vector_##TYPE* Self, void (*Callback)(Vector_##TYPE* Self, size_t Index, TYPE Value)){ \
    for(size_t i = 0; i < Self->Size; i++){ \
        Callback(Self, i, Self->At(Self, i)); \
    } \
} \
static TYPE Vector_##TYPE##_RemoveAt(Vector_##TYPE* Self, size_t Index){ \
    TYPE Removed_Element = Self->At(Self, Index); \
    for(size_t i = Index; i < (Self->Size - 1); i++){ \
        Self->Data[i] = Self->Data[i + 1]; \
    } \
    Self->Size--; \
    return Removed_Element; \
} \
static void Vector_##TYPE##_Reserve(Vector_##TYPE* Self, size_t New_Capacity){ \
    if (Self->Capacity >= New_Capacity) return; \
\
    Self->Capacity = New_Capacity; \
    Self->Data = (TYPE*)realloc(Self->Data, Self->Type_Size * Self->Capacity); \
} \
static int Vector_##TYPE##_IsEmpty(Vector_##TYPE* Self){ \
    return !Self->Size; \
} \
static void Vector_##TYPE##_Shrink(Vector_##TYPE* Self){ \
    Self->Capacity = (Self->Size < 16) ? 16 : Self->Size; \
    Self->Data = (TYPE*)realloc(Self->Data, Self->Type_Size * Self->Capacity); \
} \
static void Vector_##TYPE##_Clear(Vector_##TYPE* Self){ \
    Self->Size = 0; \
} \
static void Destroy_Vector_##TYPE(Vector_##TYPE* Self){ \
    free(Self->Data); \
    free(Self); \
} \
\
static Vector_##TYPE* New_Vector_##TYPE(){ \
    Vector_##TYPE* Temp; \
    Temp = (Vector_##TYPE*)malloc(sizeof(Vector_##TYPE)); \
\
    Temp->Size = 0; \
    Temp->Type_Size = sizeof(TYPE); \
    Temp->Capacity = 16; \
\
    Temp->Data = (TYPE*)malloc(Temp->Type_Size * Temp->Capacity); \
\
    Temp->Push = Vector_##TYPE##_Push; \
    Temp->At = Vector_##TYPE##_At; \
    Temp->Concat = Vector_##TYPE##_Concat; \
    Temp->Pop = Vector_##TYPE##_Pop; \
    Temp->ForEach = Vector_##TYPE##_ForEach; \
    Temp->RemoveAt = Vector_##TYPE##_RemoveAt;\
    Temp->Reserve = Vector_##TYPE##_Reserve; \
    Temp->IsEmpty = Vector_##TYPE##_IsEmpty; \
    Temp->Shrink = Vector_##TYPE##_Shrink; \
    Temp->Clear = Vector_##TYPE##_Clear; \
    Temp->Destroy = Destroy_Vector_##TYPE; \
\
    return Temp; \
}

#define CREATE_FOREACH(NAME, TYPE) static void NAME(Vector_##TYPE* Self, size_t Index, TYPE Value)

DEFINE_VECTOR(int);
DEFINE_VECTOR(char);

#endif