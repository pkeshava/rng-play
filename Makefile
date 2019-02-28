CC=gcc
CFLAGS=$(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
DEPS = config.h typedefinitions.h
OBJ = cdev.o typedefinitions.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cdev: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Reference http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# and
# http://www.gnu.org/software/make/manual/make.html


# So what if we want to start putting our .h files in an include directory, our
# source code in a src directory, and some local libraries in a lib directory?
# Also, can we somehow hide those annoying .o files that hang around all over
# the place? The answer, of course, is yes. The following makefile defines
# paths to the include and lib directories, and places the object files in an
# obj subdirectory within the src directory. It also has a macro defined for
# any libraries you want to include, such as the math library -lm. This
# makefile should be located in the src directory. Note that it also
# includes a rule for cleaning up your source and object directories if
# you type make clean. The .PHONY rule keeps make from doing something
# with a file named clean.
