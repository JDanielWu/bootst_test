 
cmake_minimum_required(VERSION 3.2)
 
PROJECT(bot)
 
SET(CMAKE_CXX_FLAGS "-std=c++0x")
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")
SET (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
 
find_package(Boost COMPONENTS filesystem system date_time thread python3 REQUIRED)
# find_package(COMPONENTS REQUIRED)
message("Include dirs of boost: " ${Boost_INCLUDE_DIRS} )
message("Libs of boost: " ${Boost_LIBRARIES} )
 
# find_package(PythonLibs REQUIRED)
# 改为虚拟环境
set(PYTHON_INCLUDE_DIRS "/home/wudan/anaconda3/envs/paddle_env/include/python3.7m/")
set(PYTHON_LIBRARIES "/home/wudan/anaconda3/envs/paddle_env/lib/libpython3.7m.so")
message("Include dirs of Python: " ${PYTHON_INCLUDE_DIRS} )
message("Libs of Python: " ${PYTHON_LIBRARIES} )
 
 
INCLUDE_DIRECTORIES(
${PROJECT_INCLUDE_DIR}
${Boost_INCLUDE_DIRS}
${PYTHON_INCLUDE_DIRS}
)
 
link_directories(${Boost_LIBRARY_DIRS})
link_directories(${PYTHON_LIBRARIES})
 
SET(SRC bot.cpp
)
 
add_library(bot SHARED ${SRC}) 
 
target_link_libraries(bot
${Boost_LIBRARIES}
${PYTHON_LIBRARIES}
)