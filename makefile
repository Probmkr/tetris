PROGNAME := main
INCDIR := include
SRCDIR := src
LIBDIR := lib
OUTDIR := obj
BINDIR := build
TARGET := $(PROGNAME)
SRCS := $(wildcard $(SRCDIR)/**.cpp) $(wildcard $(SRCDIR)/$(LIBDIR)/**.cpp)
OBJS := $(addprefix $(OUTDIR)/, $(patsubst src/%.cpp, %.o, $(SRCS)))
$(warning $(SRCS))
$(warning $(OBJS))
$(warning $(OUTDIR)/%.o,%.cpp)

CC = g++
CFLAGS = -Wall -O2 -I $(SRCDIR)/$(LIBDIR)

.PHONY: all clean
all: clean $(TARGET)

$(TARGET): $(OBJS)
	@if [ ! -e $(BINDIR) ]; then mkdir -p $(BINDIR); fi
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

$(OUTDIR)/%.o:src/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OUTDIR)
	rm -rf $(BINDIR)
