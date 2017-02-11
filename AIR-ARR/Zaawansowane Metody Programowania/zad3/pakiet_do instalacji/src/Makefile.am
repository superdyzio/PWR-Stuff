bin_PROGRAMS=interp4robotface
interp4robotface_SOURCES = main.cpp \
                     Biblioteka.cpp \
                     lacze_do_gnuplota.cpp \
                     ListaBibliotek.cpp \
                     menu.cpp \
                     RobotMobilny.cpp
interp4robotface_CXXFLAGS = -iquote ../inc -iquote ../../../inc -std=c++11
interp4robotface_LDFLAGS = -Wl,-rpath='$(libdir)' ${LIB_DLOPEN} -lxerces-c
