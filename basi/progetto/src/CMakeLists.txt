cmake_minimum_required(VERSION 3.15)
project(ConnessioneDB C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR})

find_package(PostgreSQL QUIET)

if (NOT PostgreSQL_FOUND)
  find_program(PG_CONFIG_EXECUTABLE
    NAMES pg_config
    HINTS
      /Applications/Postgres.app/Contents/Versions/17/bin
      /opt/homebrew/opt/postgresql@17/bin
      /usr/local/opt/postgresql@17/bin
  )
  if (NOT PG_CONFIG_EXECUTABLE)
    message(FATAL_ERROR "pg_config non trovato. Installa PostgreSQL o aggiungi Postgres.app al PATH.")
  endif()
  execute_process(COMMAND ${PG_CONFIG_EXECUTABLE} --includedir
                  OUTPUT_VARIABLE PG_INCLUDEDIR
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  execute_process(COMMAND ${PG_CONFIG_EXECUTABLE} --libdir
                  OUTPUT_VARIABLE PG_LIBDIR
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(PostgreSQL_FOUND TRUE)
  set(PostgreSQL_INCLUDE_DIRS ${PG_INCLUDEDIR})
  find_library(_PQ_LIB pq HINTS ${PG_LIBDIR})
  if (NOT _PQ_LIB)
    message(FATAL_ERROR "libpq non trovato in ${PG_LIBDIR}")
  endif()
  set(PostgreSQL_LIBRARIES ${_PQ_LIB})
endif()

add_executable(connessione_db
  main.c
)

target_include_directories(connessione_db PRIVATE
  ${PostgreSQL_INCLUDE_DIRS}
)

target_link_libraries(connessione_db PRIVATE
  ${PostgreSQL_LIBRARIES}
)

add_custom_target(run
  COMMAND $<TARGET_FILE:connessione_db>
  DEPENDS connessione_db
  WORKING_DIRECTORY ${BUILD_DIR}
  USES_TERMINAL
  COMMENT "Esecuzione di connessione_db"
)

install(TARGETS connessione_db RUNTIME DESTINATION bin)