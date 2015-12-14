#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D {
public:
    Vector2D();
    Vector2D(float, float);

    Vector2D& operator+=(Vector2D);
    Vector2D& operator-=(Vector2D);
    Vector2D& operator*=(float);

    Vector2D operator-();

public:
    float x, y;
};
#endif // VECTOR2D_H_
