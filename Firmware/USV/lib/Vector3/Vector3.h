#pragma once

template <typename T>
struct Vector3 {
    T x, y, z;
    Vector3(T c_x, T c_y, T c_z): x(c_x), y(c_y), z(c_z) {};
};
