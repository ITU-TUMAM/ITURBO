// ------------------------------------------------------------------------------
// Project: ITURBO
// Copyright(c) 2026, Onur Tuncer, PhD, Istanbul Technical University
//
// SPDX - License - Identifier: LGPL-2.1-only
// License - Filename: LICENSE
// ------------------------------------------------------------------------------

#pragma once

namespace ITURBO::Mesh{


    struct Face
{
    int node[4];
    int leftCell;
    int rightCell;
};
}