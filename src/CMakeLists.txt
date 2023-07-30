set(FileNameSrcFile
    js-regex.cpp
)
set(FileNameHFile
    ../include/

)
add_library(src_head STATIC ${FileNameSrcFile} ${FileNameHFile})
target_include_directories(src_head PUBLIC ../include)