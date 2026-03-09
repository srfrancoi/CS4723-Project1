set(cs4723-project1_SRCS
    cs4723-project1.cpp
)

ecm_qt_declare_logging_category(cs4723-project1_SRCS
    HEADER debug.h
    IDENTIFIER PLUGIN_CS4723_PROJECT1
    CATEGORY_NAME "kdevelop.plugins.cs4723-project1"
    DESCRIPTION "KDevelop plugin: CS4723-Project1"
    EXPORT CS4723_PROJECT1
)

kdevplatform_add_plugin(cs4723-project1
    SOURCES ${cs4723-project1_SRCS}
)

target_link_libraries(cs4723-project1
    KDev::Interfaces
)
