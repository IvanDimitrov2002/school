CC = g++

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: ${OBJS}
	${CC} -o main ${OBJS}

%.o: %.cpp
	${CC} -c $<

clean:
	rm -rf *.o main