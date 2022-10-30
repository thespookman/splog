CC = g++

COMPILER_FLAGS = -std=c++17 -Wall

INCLUDES = -Iinclude -I.

OUTPUT = libsplog.a

.PHONY: all
all: $(OUTPUT)

OBJS = splog.o

$(OUTPUT): $(OBJS)
	ar r $@ $^
	ranlib $@

-include $(OBJS:.o=.d)

%.o: source/%.cpp
	$(CC) $(COMPILER_FLAGS) -c $<  $(INCLUDES)
	$(CC) -M $(COMPILER_FLAGS) $<  $(INCLUDES) > $*.d

.PHONY: clean
clean:
	rm $(OBJS) $(OBJS:.o=.d) $(OUTPUT)
