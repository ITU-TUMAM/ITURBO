

#pragma once

#include "Node.h"

namespace ITURBO::Mesh{

    template<typename Scalar>
Scalar tetVolume(
    const Node<Scalar>& a,
    const Node<Scalar>& b,
    const Node<Scalar>& c,
    const Node<Scalar>& d)
{
    Scalar ax = b.x - a.x;
    Scalar ay = b.y - a.y;
    Scalar az = b.z - a.z;

    Scalar bx = c.x - a.x;
    Scalar by = c.y - a.y;
    Scalar bz = c.z - a.z;

    Scalar cx = d.x - a.x;
    Scalar cy = d.y - a.y;
    Scalar cz = d.z - a.z;

    Scalar det =
        ax*(by*cz - bz*cy)
      - ay*(bx*cz - bz*cx)
      + az*(bx*cy - by*cx);

    return det / 6.0;
}



} // namspace ITURBO::Mesh