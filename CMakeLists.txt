cmake_minimum_required (VERSION 3.8)

project ("FoxLab")

# copy FLTK headers and libs into your computer
aux_source_directory("./src" SRC_FILES)
include_directories("./include")
include_directories("./fltk/include")
link_directories("./fltk/lib")

link_libraries(debug	fltkd.lib)
link_libraries(debug	fltkformsd.lib)
link_libraries(debug	fltkgld.lib)
link_libraries(debug	fltkimagesd.lib)
link_libraries(debug	fltkjpegd.lib)
link_libraries(debug	fltkpngd.lib)
link_libraries(debug	fltkzlibd.lib)

link_libraries(optimized	fltk.lib)
link_libraries(optimized	fltkforms.lib)
link_libraries(optimized	fltkgl.lib)
link_libraries(optimized	fltkimages.lib)
link_libraries(optimized	fltkjpeg.lib)
link_libraries(optimized	fltkpng.lib)
link_libraries(optimized	fltkzlib.lib)

add_executable(FoxLab_demo "example/demo.cpp")
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})