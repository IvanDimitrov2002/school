CC = g++

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: ${OBJS}
	${CC} -o server ${OBJS}

%.o: %.cpp
	${CC} -c $<

clean:
	rm -rf *.o server