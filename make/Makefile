# # program name
PROG = task1.out

# # define the compiler to use
CC = g++

# # define any compile-time flags
CFLAGS = -Wall -g -std=c++11

# # define any directories containing header files other than /usr/include
INCLUDES = -I../inc

# # define library paths in addition to /usr/lib
# #   if I wanted to include libraries not in /usr/lib I'd specify
# #   their path using -Lpath, something like:
LFLAGS = -L../lib

BUILDDIR = ./target/
OBJS = main.o vector_example.o

$(PROG) : $(OBJS)
	$(CC) $(LFLAGS) -o $(BUILDDIR)$(PROG) $(addprefix $(BUILDDIR), $(OBJS))

main.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c ../src/main.cpp -o $(BUILDDIR)main.o

vector_example.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c ../src/vector_example.cpp -o $(BUILDDIR)vector_example.o

clean:
	rm -f $(BUILDDIR)*
