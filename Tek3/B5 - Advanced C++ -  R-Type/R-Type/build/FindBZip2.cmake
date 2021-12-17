

function(conan_message MESSAGE_OUTPUT)
    if(NOT CONAN_CMAKE_SILENT_OUTPUT)
        message(${ARGV${0}})
    endif()
endfunction()


macro(conan_find_apple_frameworks FRAMEWORKS_FOUND FRAMEWORKS FRAMEWORKS_DIRS)
    if(APPLE)
        foreach(_FRAMEWORK ${FRAMEWORKS})
            # https://cmake.org/pipermail/cmake-developers/2017-August/030199.html
            find_library(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND NAME ${_FRAMEWORK} PATHS ${FRAMEWORKS_DIRS} CMAKE_FIND_ROOT_PATH_BOTH)
            if(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND)
                list(APPEND ${FRAMEWORKS_FOUND} ${CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND})
            else()
                message(FATAL_ERROR "Framework library ${_FRAMEWORK} not found in paths: ${FRAMEWORKS_DIRS}")
            endif()
        endforeach()
    endif()
endmacro()


function(conan_package_library_targets libraries package_libdir deps out_libraries out_libraries_target build_type package_name)
    unset(_CONAN_ACTUAL_TARGETS CACHE)
    unset(_CONAN_FOUND_SYSTEM_LIBS CACHE)
    foreach(_LIBRARY_NAME ${libraries})
        find_library(CONAN_FOUND_LIBRARY NAME ${_LIBRARY_NAME} PATHS ${package_libdir}
                     NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if(CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            list(APPEND _out_libraries ${CONAN_FOUND_LIBRARY})
            if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
                # Create a micro-target for each lib/a found
                string(REGEX REPLACE "[^A-Za-z0-9.+_-]" "_" _LIBRARY_NAME ${_LIBRARY_NAME})
                set(_LIB_NAME CONAN_LIB::${package_name}_${_LIBRARY_NAME}${build_type})
                if(NOT TARGET ${_LIB_NAME})
                    # Create a micro-target for each lib/a found
                    add_library(${_LIB_NAME} UNKNOWN IMPORTED)
                    set_target_properties(${_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CONAN_FOUND_LIBRARY})
                    set(_CONAN_ACTUAL_TARGETS ${_CONAN_ACTUAL_TARGETS} ${_LIB_NAME})
                else()
                    conan_message(STATUS "Skipping already existing target: ${_LIB_NAME}")
                endif()
                list(APPEND _out_libraries_target ${_LIB_NAME})
            endif()
            conan_message(STATUS "Found: ${CONAN_FOUND_LIBRARY}")
        else()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            list(APPEND _out_libraries_target ${_LIBRARY_NAME})
            list(APPEND _out_libraries ${_LIBRARY_NAME})
            set(_CONAN_FOUND_SYSTEM_LIBS "${_CONAN_FOUND_SYSTEM_LIBS};${_LIBRARY_NAME}")
        endif()
        unset(CONAN_FOUND_LIBRARY CACHE)
    endforeach()

    if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
        # Add all dependencies to all targets
        string(REPLACE " " ";" deps_list "${deps}")
        foreach(_CONAN_ACTUAL_TARGET ${_CONAN_ACTUAL_TARGETS})
            set_property(TARGET ${_CONAN_ACTUAL_TARGET} PROPERTY INTERFACE_LINK_LIBRARIES "${_CONAN_FOUND_SYSTEM_LIBS};${deps_list}")
        endforeach()
    endif()

    set(${out_libraries} ${_out_libraries} PARENT_SCOPE)
    set(${out_libraries_target} ${_out_libraries_target} PARENT_SCOPE)
endfunction()


include(FindPackageHandleStandardArgs)

conan_message(STATUS "Conan: Using autogenerated FindBZip2.cmake")
# Global approach
set(BZip2_FOUND 1)
set(BZip2_VERSION "1.0.8")

find_package_handle_standard_args(BZip2 REQUIRED_VARS
                                  BZip2_VERSION VERSION_VAR BZip2_VERSION)
mark_as_advanced(BZip2_FOUND BZip2_VERSION)


set(BZip2_INCLUDE_DIRS "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/include")
set(BZip2_INCLUDE_DIR "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/include")
set(BZip2_INCLUDES "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/include")
set(BZip2_RES_DIRS )
set(BZip2_DEFINITIONS )
set(BZip2_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)
set(BZip2_COMPILE_DEFINITIONS )
set(BZip2_COMPILE_OPTIONS_LIST "" "")
set(BZip2_COMPILE_OPTIONS_C "")
set(BZip2_COMPILE_OPTIONS_CXX "")
set(BZip2_LIBRARIES_TARGETS "") # Will be filled later, if CMake 3
set(BZip2_LIBRARIES "") # Will be filled later
set(BZip2_LIBS "") # Same as BZip2_LIBRARIES
set(BZip2_SYSTEM_LIBS )
set(BZip2_FRAMEWORK_DIRS )
set(BZip2_FRAMEWORKS )
set(BZip2_FRAMEWORKS_FOUND "") # Will be filled later
set(BZip2_BUILD_MODULES_PATHS "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/lib/cmake/conan-official-bzip2-variables.cmake")

conan_find_apple_frameworks(BZip2_FRAMEWORKS_FOUND "${BZip2_FRAMEWORKS}" "${BZip2_FRAMEWORK_DIRS}")

mark_as_advanced(BZip2_INCLUDE_DIRS
                 BZip2_INCLUDE_DIR
                 BZip2_INCLUDES
                 BZip2_DEFINITIONS
                 BZip2_LINKER_FLAGS_LIST
                 BZip2_COMPILE_DEFINITIONS
                 BZip2_COMPILE_OPTIONS_LIST
                 BZip2_LIBRARIES
                 BZip2_LIBS
                 BZip2_LIBRARIES_TARGETS)

# Find the real .lib/.a and add them to BZip2_LIBS and BZip2_LIBRARY_LIST
set(BZip2_LIBRARY_LIST bz2)
set(BZip2_LIB_DIRS "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/lib")

# Gather all the libraries that should be linked to the targets (do not touch existing variables):
set(_BZip2_DEPENDENCIES "${BZip2_FRAMEWORKS_FOUND} ${BZip2_SYSTEM_LIBS} ")

conan_package_library_targets("${BZip2_LIBRARY_LIST}"  # libraries
                              "${BZip2_LIB_DIRS}"      # package_libdir
                              "${_BZip2_DEPENDENCIES}"  # deps
                              BZip2_LIBRARIES            # out_libraries
                              BZip2_LIBRARIES_TARGETS    # out_libraries_targets
                              ""                          # build_type
                              "BZip2")                                      # package_name

set(BZip2_LIBS ${BZip2_LIBRARIES})

foreach(_FRAMEWORK ${BZip2_FRAMEWORKS_FOUND})
    list(APPEND BZip2_LIBRARIES_TARGETS ${_FRAMEWORK})
    list(APPEND BZip2_LIBRARIES ${_FRAMEWORK})
endforeach()

foreach(_SYSTEM_LIB ${BZip2_SYSTEM_LIBS})
    list(APPEND BZip2_LIBRARIES_TARGETS ${_SYSTEM_LIB})
    list(APPEND BZip2_LIBRARIES ${_SYSTEM_LIB})
endforeach()

# We need to add our requirements too
set(BZip2_LIBRARIES_TARGETS "${BZip2_LIBRARIES_TARGETS};")
set(BZip2_LIBRARIES "${BZip2_LIBRARIES};")

set(CMAKE_MODULE_PATH "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/"
			"/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/lib/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/"
			"/Users/pierrejeannin/.conan/data/bzip2/1.0.8/_/_/package/2b8e4ed96946ad0a4cd2c6e1e01636aa2a421589/lib/cmake" ${CMAKE_PREFIX_PATH})

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET BZip2::BZip2)
        add_library(BZip2::BZip2 INTERFACE IMPORTED)
        if(BZip2_INCLUDE_DIRS)
            set_target_properties(BZip2::BZip2 PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                  "${BZip2_INCLUDE_DIRS}")
        endif()
        set_property(TARGET BZip2::BZip2 PROPERTY INTERFACE_LINK_LIBRARIES
                     "${BZip2_LIBRARIES_TARGETS};${BZip2_LINKER_FLAGS_LIST}")
        set_property(TARGET BZip2::BZip2 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                     ${BZip2_COMPILE_DEFINITIONS})
        set_property(TARGET BZip2::BZip2 PROPERTY INTERFACE_COMPILE_OPTIONS
                     "${BZip2_COMPILE_OPTIONS_LIST}")
        
    endif()
endif()

foreach(_BUILD_MODULE_PATH ${BZip2_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
