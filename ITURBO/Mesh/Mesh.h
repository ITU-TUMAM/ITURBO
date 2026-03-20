
#pragma once

namespace ITURBO::Mesh{

template<typename Scalar>
struct Mesh
{
    std::vector<Node<Scalar>> nodes;
    std::vector<Face> faces;
    std::vector<Cell> cells;
};

} //namespace ITURBO::Mesh