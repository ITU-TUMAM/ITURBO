

#pragma once

#include "Node.h"

namespace ITURBO::Mesh{
    
template<typename Scalar>
struct FaceGeom
{
    Scalar nx;
    Scalar ny;
    Scalar nz;
    Scalar area;
};

template<typename Scalar>
FaceGeom<Scalar> computeFaceGeom(
    const Node<Scalar>& a,
    const Node<Scalar>& b,
    const Node<Scalar>& c)
{
    Scalar ax = b.x - a.x;
    Scalar ay = b.y - a.y;
    Scalar az = b.z - a.z;

    Scalar bx = c.x - a.x;
    Scalar by = c.y - a.y;
    Scalar bz = c.z - a.z;

    Scalar nx = ay*bz - az*by;
    Scalar ny = az*bx - ax*bz;
    Scalar nz = ax*by - ay*bx;

    Scalar area = CppAD::sqrt(nx*nx + ny*ny + nz*nz);

    return {nx, ny, nz, area};
}

}