CC = g++

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: ${OBJS}
	${CC} -o game ${OBJS}

%.o: %.cpp
	${CC} -c $<

clean:
	rm -rf *.o game