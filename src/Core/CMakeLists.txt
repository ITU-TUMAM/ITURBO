## ------------------------------------------------------------------------------
## Project: ITURBO
## Copyright(c) 2026, Onur Tuncer, PhD, Istanbul Technical University
##
## SPDX - License - Identifier: LGPL-2.1-only
## License - Filename: LICENSE
## ------------------------------------------------------------------------------

# src/Core/CMakeLists.txt

file(GLOB ITURBO_CORE_PUBLIC_HEADERS
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/ITURBO/Core/*.h"
)

file(GLOB ITURBO_CORE_PRIVATE_HEADERS
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

file(GLOB ITURBO_CORE_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(iturbo_core
    ${ITURBO_CORE_PUBLIC_HEADERS}
    ${ITURBO_CORE_PRIVATE_HEADERS}
    ${ITURBO_CORE_SOURCES}
)

add_library(ITURBO::Core ALIAS iturbo_core)

target_link_libraries(iturbo_core
    PUBLIC
        ITURBO::ProjectOptions
        ITURBO::Warnings
        ITURBO::Sanitizers
)

target_include_directories(iturbo_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/generated>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(iturbo_core PUBLIC cxx_std_23)

set_target_properties(iturbo_core PROPERTIES
    OUTPUT_NAME iturbo_core
    EXPORT_NAME Core
)

install(
    TARGETS iturbo_core
    EXPORT ITURBOTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY "${CMAKE_SOURCE_DIR}/ITURBO/Core/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/ITURBO/Core"
    FILES_MATCHING PATTERN "*.h"
)

install(
    FILES
        "${CMAKE_BINARY_DIR}/generated/ITURBO/Core/Version.h"
    DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/ITURBO/Core"
)
