#ifndef turbo_chunk_h
#define turbo_chunk_h

#include "common.h"
#include "value.h"

typedef enum{
  OP_CONSTANT,
  OP_NIL,
  OP_TRUE,
  OP_FALSE,
  OP_EQUAL,
  OP_GREATER,
  OP_LESS,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_NOT,
  OP_NEGATE,
  OP_RETURN
} OpCode;

typedef unsigned int LineValue;

typedef struct {
  LineValue* lines;
  int capacity;
  int count;
} CompressedLines;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  CompressedLines lines;
  ValueArray constants;
} Chunk;

void init_chunk(Chunk* chunk);
void free_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte, int line);
int add_constant(Chunk* chunk, Value value);
int get_line(Chunk* chunk, int offset);

#endif
