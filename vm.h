#ifndef turbo_vm_h
#define turbo_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk* chunk;
  uint8_t* ip; // represent virtual InstructionPointer
  Value stack[STACK_MAX];
  Value* stack_top;

  Obj* objects;
} VM;

typedef enum{
  INTERPRET_RESULT_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void init_vm();
void free_vm();

InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
