if( WIN32 )
  set( DC1394V2_FOUND FALSE )
endif( WIN32 )

if( APPLE )
 set( DC1394V2_FOUND FALSE )
endif( APPLE )

if( UNIX )
  find_path( DC1394V2_INCLUDE_DIR NAMES dc1394/dc1394.h)
  find_path( RAW1394_INCLUDE_DIR NAMES libraw1394/raw1394.h)
  find_library( DC1394V2_LIBRARY NAMES dc1394)
  find_library( RAW1394_LIBRARY NAMES raw1394)

  if( DC1394V2_LIBRARY AND RAW1394_LIBRARY AND DC1394V2_INCLUDE_DIR AND RAW1394_INCLUDE_DIR )
    set( DC1394V2_LIBRARIES ${DC1394V2_LIBRARY} ${RAW1394_LIBRARY} )
    set( DC1394V2_INCLUDE_DIRS ${DC1394V2_INCLUDE_DIR} ${RAW1394_INCLUDE_DIR} )
    set( DC1394V2_FOUND TRUE )
  endif()

endif( UNIX )

include( FindPackageHandleStandardArgs )
find_package_handle_standard_args( DC1394V2 DEFAULT_MSG DC1394V2_LIBRARIES DC1394V2_INCLUDE_DIRS )

mark_as_advanced( DC1394V2_INCLUDE_DIRS DC1394V2_LIBRARIES )

