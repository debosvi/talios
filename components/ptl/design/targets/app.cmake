
## generation profile name.
## mandatory (generates application)
set(COMP_SRC_PROFILE "application")

## COMP_SRC_APP_NAME var must be set to binary name.
## mandatory
set(COMP_SRC_APP_NAME "compute")

## LOCAL_SRC_DIR_SUFFIX is the relative path prefix to append to component files directory in order to find source files to compile.
## optional but recommended
set(LOCAL_SRC_DIR_SUFFIX app)

## LOCAL_SRC_FILES is the list of files to compile (do not use any absolute path, automatic appending is performed by complete makefiles scheme.
## mandatory
set(LOCAL_SRC_FILES 
	main.cpp
	)

## LOCAL_SRC_FILES_ADDED is the list of files to compile with absolute path (useful if generated files are somewhere).
## optional
# set(LOCAL_SRC_FILES_ADDED <somewhere absolute>)

## COMP_SRC_LIB_DEPS is the list of library dependencies (internal dependencies only).
## Build system will decide which static or shared is recommended.
## optional
# set(COMP_SRC_LIB_DEPS other_lib)

## COMP_SRC_LIB_DEPS_STATIC is the list of static library dependencies (internal dependencies only).
## Be careful about system compatibility between static and shared libraries
## optional
# set(COMP_SRC_LIB_DEPS_STATIC other_static_lib)

## COMP_SRC_LIB_DEPS_SHARED is the list of shared library dependencies (internal dependencies only).
## Be careful about system compatibility between static and shared libraries.
## optional
set(COMP_SRC_LIB_DEPS_SHARED talios_design)


## COMP_EXT_LIB_DEPS is the list of external library dependencies.
## optional
# set(COMP_EXT_LIB_DEPS external_lib)
