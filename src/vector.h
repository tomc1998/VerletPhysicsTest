#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  float x, y;
} Vector2f;

// Adds a to b and places the result in a.
void vecAdd(Vector2f* a, const Vector2f* b);

// Subtracts a from b and places the result in a.
void vecSub(Vector2f* a, const Vector2f* b);

// Scales a by fac
void vecScl(Vector2f* a, const float fac);

#endif
