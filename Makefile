# use gcc to compile source files
CC = g++
# the linker is also "gcc".  It might be something else with other compilers.
LD = g++
# compiler flags go here
CFLAGS = -g -Wall
# Linker flags go here.  
LDFLAGS = 
# Use this command to erase files
RM = /bin/rm -f
# list of generated object files
OBJS = lfsr.o
# program executable file name
PROG = lfsr 

# top level rule
all: $(PROG)

lfsr: $(OBJS)
	$(LD) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

lfsr.o: lfsr.cc
	$(LD) $(CFLAGS) -c lfsr.cc

clean:
	$(RM) $(PROG) $(OBJS)  

