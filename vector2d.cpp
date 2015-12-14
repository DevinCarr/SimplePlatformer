#include "vector2d.h"

Vector2D::Vector2D() {
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {};

Vector2D& Vector2D::operator+=(Vector2D arg1) {
    x += arg1.x;
    y += arg1.y;
    return (*this);
}

Vector2D& Vector2D::operator-=(Vector2D arg1) {
    x -= arg1.x;
    y -= arg1.y;
    return (*this);
}

Vector2D& Vector2D::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return (*this);
}

Vector2D Vector2D::operator-() {
    return(Vector2D(-x, -y));
}
