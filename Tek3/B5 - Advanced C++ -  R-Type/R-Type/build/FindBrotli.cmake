########## MACROS ###########################################################################
#############################################################################################

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


########### FOUND PACKAGE ###################################################################
#############################################################################################

include(FindPackageHandleStandardArgs)

conan_message(STATUS "Conan: Using autogenerated FindBrotli.cmake")
set(Brotli_FOUND 1)
set(Brotli_VERSION "1.0.9")

find_package_handle_standard_args(Brotli REQUIRED_VARS
                                  Brotli_VERSION VERSION_VAR Brotli_VERSION)
mark_as_advanced(Brotli_FOUND Brotli_VERSION)

set(Brotli_COMPONENTS Brotli::brotlidec Brotli::brotlienc Brotli::brotlicommon)

if(Brotli_FIND_COMPONENTS)
    foreach(_FIND_COMPONENT ${Brotli_FIND_COMPONENTS})
        list(FIND Brotli_COMPONENTS "Brotli::${_FIND_COMPONENT}" _index)
        if(${_index} EQUAL -1)
            conan_message(FATAL_ERROR "Conan: Component '${_FIND_COMPONENT}' NOT found in package 'Brotli'")
        else()
            conan_message(STATUS "Conan: Component '${_FIND_COMPONENT}' found in package 'Brotli'")
        endif()
    endforeach()
endif()

########### VARIABLES #######################################################################
#############################################################################################


set(Brotli_INCLUDE_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_INCLUDE_DIR "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include;/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_INCLUDES "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_RES_DIRS )
set(Brotli_DEFINITIONS )
set(Brotli_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)
set(Brotli_COMPILE_DEFINITIONS )
set(Brotli_COMPILE_OPTIONS_LIST "" "")
set(Brotli_COMPILE_OPTIONS_C "")
set(Brotli_COMPILE_OPTIONS_CXX "")
set(Brotli_LIBRARIES_TARGETS "") # Will be filled later, if CMake 3
set(Brotli_LIBRARIES "") # Will be filled later
set(Brotli_LIBS "") # Same as Brotli_LIBRARIES
set(Brotli_SYSTEM_LIBS )
set(Brotli_FRAMEWORK_DIRS )
set(Brotli_FRAMEWORKS )
set(Brotli_FRAMEWORKS_FOUND "") # Will be filled later
set(Brotli_BUILD_MODULES_PATHS )

conan_find_apple_frameworks(Brotli_FRAMEWORKS_FOUND "${Brotli_FRAMEWORKS}" "${Brotli_FRAMEWORK_DIRS}")

mark_as_advanced(Brotli_INCLUDE_DIRS
                 Brotli_INCLUDE_DIR
                 Brotli_INCLUDES
                 Brotli_DEFINITIONS
                 Brotli_LINKER_FLAGS_LIST
                 Brotli_COMPILE_DEFINITIONS
                 Brotli_COMPILE_OPTIONS_LIST
                 Brotli_LIBRARIES
                 Brotli_LIBS
                 Brotli_LIBRARIES_TARGETS)

# Find the real .lib/.a and add them to Brotli_LIBS and Brotli_LIBRARY_LIST
set(Brotli_LIBRARY_LIST brotlidec-static brotlienc-static brotlicommon-static)
set(Brotli_LIB_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/lib")

# Gather all the libraries that should be linked to the targets (do not touch existing variables):
set(_Brotli_DEPENDENCIES "${Brotli_FRAMEWORKS_FOUND} ${Brotli_SYSTEM_LIBS} ")

conan_package_library_targets("${Brotli_LIBRARY_LIST}"  # libraries
                              "${Brotli_LIB_DIRS}"      # package_libdir
                              "${_Brotli_DEPENDENCIES}"  # deps
                              Brotli_LIBRARIES            # out_libraries
                              Brotli_LIBRARIES_TARGETS    # out_libraries_targets
                              ""                          # build_type
                              "Brotli")                                      # package_name

set(Brotli_LIBS ${Brotli_LIBRARIES})

foreach(_FRAMEWORK ${Brotli_FRAMEWORKS_FOUND})
    list(APPEND Brotli_LIBRARIES_TARGETS ${_FRAMEWORK})
    list(APPEND Brotli_LIBRARIES ${_FRAMEWORK})
endforeach()

foreach(_SYSTEM_LIB ${Brotli_SYSTEM_LIBS})
    list(APPEND Brotli_LIBRARIES_TARGETS ${_SYSTEM_LIB})
    list(APPEND Brotli_LIBRARIES ${_SYSTEM_LIB})
endforeach()

# We need to add our requirements too
set(Brotli_LIBRARIES_TARGETS "${Brotli_LIBRARIES_TARGETS};")
set(Brotli_LIBRARIES "${Brotli_LIBRARIES};")

set(CMAKE_MODULE_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_PREFIX_PATH})


########### COMPONENT brotlicommon VARIABLES #############################################

set(Brotli_brotlicommon_INCLUDE_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlicommon_INCLUDE_DIR "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include;/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlicommon_INCLUDES "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlicommon_LIB_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/lib")
set(Brotli_brotlicommon_RES_DIRS )
set(Brotli_brotlicommon_DEFINITIONS )
set(Brotli_brotlicommon_COMPILE_DEFINITIONS )
set(Brotli_brotlicommon_COMPILE_OPTIONS_C "")
set(Brotli_brotlicommon_COMPILE_OPTIONS_CXX "")
set(Brotli_brotlicommon_LIBS brotlicommon-static)
set(Brotli_brotlicommon_SYSTEM_LIBS )
set(Brotli_brotlicommon_FRAMEWORK_DIRS )
set(Brotli_brotlicommon_FRAMEWORKS )
set(Brotli_brotlicommon_BUILD_MODULES_PATHS )
set(Brotli_brotlicommon_DEPENDENCIES )
set(Brotli_brotlicommon_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)

########### COMPONENT brotlienc VARIABLES #############################################

set(Brotli_brotlienc_INCLUDE_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlienc_INCLUDE_DIR "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include;/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlienc_INCLUDES "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlienc_LIB_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/lib")
set(Brotli_brotlienc_RES_DIRS )
set(Brotli_brotlienc_DEFINITIONS )
set(Brotli_brotlienc_COMPILE_DEFINITIONS )
set(Brotli_brotlienc_COMPILE_OPTIONS_C "")
set(Brotli_brotlienc_COMPILE_OPTIONS_CXX "")
set(Brotli_brotlienc_LIBS brotlienc-static)
set(Brotli_brotlienc_SYSTEM_LIBS )
set(Brotli_brotlienc_FRAMEWORK_DIRS )
set(Brotli_brotlienc_FRAMEWORKS )
set(Brotli_brotlienc_BUILD_MODULES_PATHS )
set(Brotli_brotlienc_DEPENDENCIES Brotli::brotlicommon)
set(Brotli_brotlienc_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)

########### COMPONENT brotlidec VARIABLES #############################################

set(Brotli_brotlidec_INCLUDE_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlidec_INCLUDE_DIR "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include;/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlidec_INCLUDES "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include"
			"/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/include/brotli")
set(Brotli_brotlidec_LIB_DIRS "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/lib")
set(Brotli_brotlidec_RES_DIRS )
set(Brotli_brotlidec_DEFINITIONS )
set(Brotli_brotlidec_COMPILE_DEFINITIONS )
set(Brotli_brotlidec_COMPILE_OPTIONS_C "")
set(Brotli_brotlidec_COMPILE_OPTIONS_CXX "")
set(Brotli_brotlidec_LIBS brotlidec-static)
set(Brotli_brotlidec_SYSTEM_LIBS )
set(Brotli_brotlidec_FRAMEWORK_DIRS )
set(Brotli_brotlidec_FRAMEWORKS )
set(Brotli_brotlidec_BUILD_MODULES_PATHS )
set(Brotli_brotlidec_DEPENDENCIES Brotli::brotlicommon)
set(Brotli_brotlidec_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)


########## FIND PACKAGE DEPENDENCY ##########################################################
#############################################################################################

include(CMakeFindDependencyMacro)


########## FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #######################################
#############################################################################################

########## COMPONENT brotlicommon FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Brotli_brotlicommon_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Brotli_brotlicommon_FRAMEWORKS_FOUND "${Brotli_brotlicommon_FRAMEWORKS}" "${Brotli_brotlicommon_FRAMEWORK_DIRS}")

set(Brotli_brotlicommon_LIB_TARGETS "")
set(Brotli_brotlicommon_NOT_USED "")
set(Brotli_brotlicommon_LIBS_FRAMEWORKS_DEPS ${Brotli_brotlicommon_FRAMEWORKS_FOUND} ${Brotli_brotlicommon_SYSTEM_LIBS} ${Brotli_brotlicommon_DEPENDENCIES})
conan_package_library_targets("${Brotli_brotlicommon_LIBS}"
                              "${Brotli_brotlicommon_LIB_DIRS}"
                              "${Brotli_brotlicommon_LIBS_FRAMEWORKS_DEPS}"
                              Brotli_brotlicommon_NOT_USED
                              Brotli_brotlicommon_LIB_TARGETS
                              ""
                              "Brotli_brotlicommon")

set(Brotli_brotlicommon_LINK_LIBS ${Brotli_brotlicommon_LIB_TARGETS} ${Brotli_brotlicommon_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_PREFIX_PATH})

########## COMPONENT brotlienc FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Brotli_brotlienc_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Brotli_brotlienc_FRAMEWORKS_FOUND "${Brotli_brotlienc_FRAMEWORKS}" "${Brotli_brotlienc_FRAMEWORK_DIRS}")

set(Brotli_brotlienc_LIB_TARGETS "")
set(Brotli_brotlienc_NOT_USED "")
set(Brotli_brotlienc_LIBS_FRAMEWORKS_DEPS ${Brotli_brotlienc_FRAMEWORKS_FOUND} ${Brotli_brotlienc_SYSTEM_LIBS} ${Brotli_brotlienc_DEPENDENCIES})
conan_package_library_targets("${Brotli_brotlienc_LIBS}"
                              "${Brotli_brotlienc_LIB_DIRS}"
                              "${Brotli_brotlienc_LIBS_FRAMEWORKS_DEPS}"
                              Brotli_brotlienc_NOT_USED
                              Brotli_brotlienc_LIB_TARGETS
                              ""
                              "Brotli_brotlienc")

set(Brotli_brotlienc_LINK_LIBS ${Brotli_brotlienc_LIB_TARGETS} ${Brotli_brotlienc_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_PREFIX_PATH})

########## COMPONENT brotlidec FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Brotli_brotlidec_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Brotli_brotlidec_FRAMEWORKS_FOUND "${Brotli_brotlidec_FRAMEWORKS}" "${Brotli_brotlidec_FRAMEWORK_DIRS}")

set(Brotli_brotlidec_LIB_TARGETS "")
set(Brotli_brotlidec_NOT_USED "")
set(Brotli_brotlidec_LIBS_FRAMEWORKS_DEPS ${Brotli_brotlidec_FRAMEWORKS_FOUND} ${Brotli_brotlidec_SYSTEM_LIBS} ${Brotli_brotlidec_DEPENDENCIES})
conan_package_library_targets("${Brotli_brotlidec_LIBS}"
                              "${Brotli_brotlidec_LIB_DIRS}"
                              "${Brotli_brotlidec_LIBS_FRAMEWORKS_DEPS}"
                              Brotli_brotlidec_NOT_USED
                              Brotli_brotlidec_LIB_TARGETS
                              ""
                              "Brotli_brotlidec")

set(Brotli_brotlidec_LINK_LIBS ${Brotli_brotlidec_LIB_TARGETS} ${Brotli_brotlidec_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/Users/pierrejeannin/.conan/data/brotli/1.0.9/_/_/package/095512ed878f14a09dd732e9f6868729dd437529/" ${CMAKE_PREFIX_PATH})


########## TARGETS ##########################################################################
#############################################################################################

########## COMPONENT brotlicommon TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Brotli::brotlicommon)
        add_library(Brotli::brotlicommon INTERFACE IMPORTED)
        set_target_properties(Brotli::brotlicommon PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Brotli_brotlicommon_INCLUDE_DIRS}")
        set_target_properties(Brotli::brotlicommon PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Brotli_brotlicommon_LIB_DIRS}")
        set_target_properties(Brotli::brotlicommon PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Brotli_brotlicommon_LINK_LIBS};${Brotli_brotlicommon_LINKER_FLAGS_LIST}")
        set_target_properties(Brotli::brotlicommon PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Brotli_brotlicommon_COMPILE_DEFINITIONS}")
        set_target_properties(Brotli::brotlicommon PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Brotli_brotlicommon_COMPILE_OPTIONS_C};${Brotli_brotlicommon_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## COMPONENT brotlienc TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Brotli::brotlienc)
        add_library(Brotli::brotlienc INTERFACE IMPORTED)
        set_target_properties(Brotli::brotlienc PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Brotli_brotlienc_INCLUDE_DIRS}")
        set_target_properties(Brotli::brotlienc PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Brotli_brotlienc_LIB_DIRS}")
        set_target_properties(Brotli::brotlienc PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Brotli_brotlienc_LINK_LIBS};${Brotli_brotlienc_LINKER_FLAGS_LIST}")
        set_target_properties(Brotli::brotlienc PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Brotli_brotlienc_COMPILE_DEFINITIONS}")
        set_target_properties(Brotli::brotlienc PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Brotli_brotlienc_COMPILE_OPTIONS_C};${Brotli_brotlienc_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## COMPONENT brotlidec TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Brotli::brotlidec)
        add_library(Brotli::brotlidec INTERFACE IMPORTED)
        set_target_properties(Brotli::brotlidec PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Brotli_brotlidec_INCLUDE_DIRS}")
        set_target_properties(Brotli::brotlidec PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Brotli_brotlidec_LIB_DIRS}")
        set_target_properties(Brotli::brotlidec PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Brotli_brotlidec_LINK_LIBS};${Brotli_brotlidec_LINKER_FLAGS_LIST}")
        set_target_properties(Brotli::brotlidec PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Brotli_brotlidec_COMPILE_DEFINITIONS}")
        set_target_properties(Brotli::brotlidec PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Brotli_brotlidec_COMPILE_OPTIONS_C};${Brotli_brotlidec_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## GLOBAL TARGET ####################################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    if(NOT TARGET Brotli::Brotli)
        add_library(Brotli::Brotli INTERFACE IMPORTED)
    endif()
    set_property(TARGET Brotli::Brotli APPEND PROPERTY
                 INTERFACE_LINK_LIBRARIES "${Brotli_COMPONENTS}")
endif()

########## BUILD MODULES ####################################################################
#############################################################################################
########## COMPONENT brotlicommon BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Brotli_brotlicommon_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
########## COMPONENT brotlienc BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Brotli_brotlienc_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
########## COMPONENT brotlidec BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Brotli_brotlidec_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
