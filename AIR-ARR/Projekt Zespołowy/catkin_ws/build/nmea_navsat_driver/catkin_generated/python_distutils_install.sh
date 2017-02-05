#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/perdziu/catkin_ws/src/nmea_navsat_driver"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/perdziu/catkin_ws/install/lib/python2.7/dist-packages:/home/perdziu/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/perdziu/catkin_ws/build" \
    "/usr/bin/python" \
    "/home/perdziu/catkin_ws/src/nmea_navsat_driver/setup.py" \
    build --build-base "/home/perdziu/catkin_ws/build/nmea_navsat_driver" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/perdziu/catkin_ws/install" --install-scripts="/home/perdziu/catkin_ws/install/bin"
