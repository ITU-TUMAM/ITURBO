## ------------------------------------------------------------------------------
## Project: ITURBO
## Copyright(c) 2026, Onur Tuncer, PhD, Istanbul Technical University
##
## SPDX - License - Identifier: LGPL-2.1-only
## License - Filename: LICENSE
## ------------------------------------------------------------------------------

include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(catch2)