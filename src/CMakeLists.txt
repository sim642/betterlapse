find_package(Boost REQUIRED COMPONENTS filesystem system)
find_package(OpenCV REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
set(SOURCE_FILES betterlapse.cpp IndividualTransformer.cpp WhiteBalanceTransformer.cpp Transformer.cpp UnsharpMaskTransformer.cpp CropTransformer.cpp)

add_executable(betterlapse ${SOURCE_FILES})
target_link_libraries(betterlapse ${Boost_LIBRARIES})
target_link_libraries(betterlapse ${OpenCV_LIBRARIES})