bin_PROGRAMS=interp4robotface
interp4robotface_SOURCES = main.cpp \
                     module1.cpp \
                     module2.cpp
interp4robotface_CXXFLAGS = -I../inc -I../../../inc
interp4robotface_LDFLAGS = -Wl,-rpath='$(libdir)' ${LIB_DLOPEN} -lxerces-c
