CC = g++
LD = g++
CFLAGS = -Wall -Wextra -O2
LDFLAGS = #-lpthread -lm
SRCS := $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.dep)
EXEC = $(SRCS:.c=)
RM = rm -f

all: QPwithFile

QPwithFile: QPwithFile.o QuadProg++.o
	$(LD) $(LDFLAGS) -o $@ $^

test: test.o QuadProg++.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(EXEC) *~

.PHONY:
	all clean