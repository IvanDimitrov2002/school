CC = clang++ -Wall -Wextra -pedantic -O2

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: ${OBJS}
	${CC} -lpthread -o starcraft3 ${OBJS}

%.o: %.cpp
	${CC} -c $<

clean:
	rm -rf *.o starcraft3