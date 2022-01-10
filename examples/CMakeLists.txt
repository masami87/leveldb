function(leveldb_example example_file)
    get_filename_component(example_name "${example_file}" NAME_WE)
    add_executable("${example_name}" "${example_file}")
    # target_sources("${test_target_name}"
    #   PRIVATE
    #     # "${PROJECT_BINARY_DIR}/${LEVELDB_PORT_CONFIG_DIR}/port_config.h"
    #     "${example_file}"
    # )

    target_link_libraries("${example_name}" leveldb)
endfunction(leveldb_example)

leveldb_example("open_db.cc")

