

#pragma once

namespace ITURBO::Mesh{


    struct Face
{
    int node[4];
    int leftCell;
    int rightCell;
};
}