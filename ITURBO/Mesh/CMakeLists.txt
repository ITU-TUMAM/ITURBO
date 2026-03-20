file(GLOB ITURBO_MESH_PUBLIC_HEADERS
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/include/ITURBO/Mesh/*.h"
)

file(GLOB ITURBO_MESH_PRIVATE_HEADERS
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

file(GLOB TURBOCFD_MESH_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(turbocfd_mesh
    ${ITURBO_MESH_PUBLIC_HEADERS}
    ${ITURBO_MESH_PRIVATE_HEADERS}
    ${ITURBO_MESH_SOURCES}
)

add_library(ITurbo::Mesh ALIAS iturbo_mesh)

target_link_libraries(iturbo_mesh
    PUBLIC
        Turbo::ProjectOptions
        Turbo::Warnings
        Turbo::Sanitizers
        Turbo::Core
)

target_include_directories(turbocfd_mesh
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/generated>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(iturbo_mesh PUBLIC cxx_std_23)

target_compile_definitions(iturbo_mesh
    PRIVATE
        ITURBO_MESH_BUILD
)

set_target_properties(iturbo_mesh PROPERTIES
    OUTPUT_NAME iturbo_mesh
    EXPORT_NAME Mesh
    WINDOWS_EXPORT_ALL_SYMBOLS ON
    FOLDER "src/Mesh"
)

source_group(
    TREE "${CMAKE_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${TURBOCFD_MESH_PUBLIC_HEADERS}
)

source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    PREFIX "Source Files"
    FILES
        ${TURBOCFD_MESH_PRIVATE_HEADERS}
        ${TURBOCFD_MESH_SOURCES}
)

install(
    TARGETS turbo_mesh
    EXPORT TurboCFDTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY "${CMAKE_SOURCE_DIR}/include/TurboCFD/Mesh/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/TurboCFD/Mesh"
    FILES_MATCHING PATTERN "*.h"
)