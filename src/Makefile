########################################
#
# build exectable object Makefile
########################################
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET  := test

CC      := g++
LIBS    := -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
LDFLAGS := -L../lib -Wl,-rpath=../lib
DEFINES :=
INCLUDE := -I../include

CFLAGS  := -Wall $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS)


# do not change the following objects below before you understand it's use
.PHONY : everything objs rebuild clean veryclean

everything : $(TARGET)

objs : $(OBJS)

rebuild: veryclean everything

clean :
	rm -fr *.o

veryclean : clean
	rm -fr $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
