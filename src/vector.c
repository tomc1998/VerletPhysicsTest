#include "vector.h"

void vecAdd(Vector2f* a, const Vector2f* b) {
  a->x += b->x;
  a->y += b->y;
}

void vecSub(Vector2f* a, const Vector2f* b) {
  a->x -= b->x;
  a->y -= b->y;
}

void vecScl(Vector2f* a, const float fac) {
  a->x *= fac;
  a->y *= fac;
}
