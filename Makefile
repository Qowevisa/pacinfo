include config.mk
OBJ_F = obj
SRC_F = src
INC_F = inc
TEST_F = tests
TEST_BIN_F = tbin
inc_dir = /usr/local/include

project_name = pacfo
sources = pacfo util str
tests = $(shell ls $(TEST_F) | grep .c | cut -d '.' -f 1)

def: test_all
	@

$(inc_dir):
	sudo mkdir -p $@

$(INC_F):
	mkdir $(INC_F)

$(inc_dir)/%.h : $(INC_F)/%.h
	cp $< $@

$(TEST_BIN_F):
	mkdir ./$@

$(TEST_F):
	mkdir ./$@

$(TEST_BIN_F)/% : $(TEST_F)/%.c $(lib_name).a
	$(CC) $< -o $@ $(lib_name).a $(CFLAGS)

rem_tests:
	$(tests:%=rm ./$(TEST_BIN_F)/%;)

retest: rem_tests test_all
	@

test_all: $(project_name) $(TEST_BIN_F) $(TEST_F) $(tests:%=$(TEST_BIN_F)/%) $(copy_incs)
	$(tests:%=./$(TEST_BIN_F)/%;)

$(OBJ_F):
	mkdir -p ./$(OBJ_F)

$(OBJ_F)/%.o : $(SRC_F)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(project_name): $(OBJ_F) $(sources:%=$(OBJ_F)/%.o)
	gcc -o $(project_name) $(sources:%=$(OBJ_F)/%.o)

build: $(project_name)
	@

clean: 
	-rm $(sources:%=$(OBJ_F)/%.o) 2> /dev/null
	-rm $(project_name) 2> /dev/null

full: build clean

.PHONY: def build clean full
