project(ompl_near_projection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

find_package(ompl REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
 include
 ${OMPL_INCLUDE_DIRS}
 ${EIGEN_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/NearProjectedStateSpace.cpp
  src/NearConstrainedSpaceInformation.cpp
  src/NearProblemDefinition.cpp
  src/NearGoalSpace.cpp
  src/NearKPIECE1.cpp
  src/NearEST.cpp
  src/pNearEST.cpp
  src/NearRRT.cpp
  src/pNearRRT.cpp
  src/pNearKPIECE1.cpp
  src/NearRRTConnect.cpp
  src/pNearRRTConnect.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OMPL_LIBRARIES}
  ${EIGEN_LIBRARIES}
  )

add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME})
