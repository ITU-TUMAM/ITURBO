// ------------------------------------------------------------------------------
// Project: ITURBO
// Copyright(c) 2026, Onur Tuncer, PhD, Istanbul Technical University
//
// SPDX - License - Identifier: LGPL-2.1-only
// License - Filename: LICENSE
// ------------------------------------------------------------------------------

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