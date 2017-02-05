# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "drrobot_jaguar4x4_player: 8 messages, 2 services")

set(MSG_I_FLAGS "-Idrrobot_jaguar4x4_player:/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/indigo/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeographic_msgs:/home/perdziu/catkin_ws/src/geographic_msgs/msg;-Iactionlib_msgs:/opt/ros/indigo/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(drrobot_jaguar4x4_player_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg" "drrobot_jaguar4x4_player/MotorInfo:std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv" "geometry_msgs/Point:geometry_msgs/PoseWithCovariance:geometry_msgs/PoseWithCovarianceStamped:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg" "drrobot_jaguar4x4_player/Range:std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv" "geographic_msgs/GeoPose:geographic_msgs/GeoPoint:geometry_msgs/Quaternion"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg" NAME_WE)
add_custom_target(_drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_jaguar4x4_player" "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)

### Generating Services
_generate_srv_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/geographic_msgs/msg/GeoPose.msg;/home/perdziu/catkin_ws/src/geographic_msgs/msg/GeoPoint.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_srv_cpp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
)

### Generating Module File
_generate_module_cpp(drrobot_jaguar4x4_player
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(drrobot_jaguar4x4_player_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(drrobot_jaguar4x4_player_generate_messages drrobot_jaguar4x4_player_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(drrobot_jaguar4x4_player_gencpp)
add_dependencies(drrobot_jaguar4x4_player_gencpp drrobot_jaguar4x4_player_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS drrobot_jaguar4x4_player_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)

### Generating Services
_generate_srv_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/geographic_msgs/msg/GeoPose.msg;/home/perdziu/catkin_ws/src/geographic_msgs/msg/GeoPoint.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_srv_lisp(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
)

### Generating Module File
_generate_module_lisp(drrobot_jaguar4x4_player
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(drrobot_jaguar4x4_player_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(drrobot_jaguar4x4_player_generate_messages drrobot_jaguar4x4_player_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(drrobot_jaguar4x4_player_genlisp)
add_dependencies(drrobot_jaguar4x4_player_genlisp drrobot_jaguar4x4_player_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS drrobot_jaguar4x4_player_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_msg_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)

### Generating Services
_generate_srv_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/home/perdziu/catkin_ws/src/geographic_msgs/msg/GeoPose.msg;/home/perdziu/catkin_ws/src/geographic_msgs/msg/GeoPoint.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)
_generate_srv_py(drrobot_jaguar4x4_player
  "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
)

### Generating Module File
_generate_module_py(drrobot_jaguar4x4_player
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(drrobot_jaguar4x4_player_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(drrobot_jaguar4x4_player_generate_messages drrobot_jaguar4x4_player_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/MotorInfoArray.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/CustomSensor.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetPose.srv" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/PowerInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/Range.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/RangeArray.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/srv/SetDatum.srv" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/IMUInfo.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/perdziu/catkin_ws/src/drrobot_jaguar4x4_player/msg/StandardSensor.msg" NAME_WE)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py _drrobot_jaguar4x4_player_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(drrobot_jaguar4x4_player_genpy)
add_dependencies(drrobot_jaguar4x4_player_genpy drrobot_jaguar4x4_player_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS drrobot_jaguar4x4_player_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_jaguar4x4_player
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp nav_msgs_generate_messages_cpp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp sensor_msgs_generate_messages_cpp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_cpp geographic_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_jaguar4x4_player
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp nav_msgs_generate_messages_lisp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp sensor_msgs_generate_messages_lisp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_lisp geographic_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_jaguar4x4_player
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py nav_msgs_generate_messages_py)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py sensor_msgs_generate_messages_py)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(drrobot_jaguar4x4_player_generate_messages_py geographic_msgs_generate_messages_py)
