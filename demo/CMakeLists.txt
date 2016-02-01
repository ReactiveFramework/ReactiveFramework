

add_executable (
    demo-server
    server/server.cpp
)
target_link_libraries (demo-server ReactiveShared)
