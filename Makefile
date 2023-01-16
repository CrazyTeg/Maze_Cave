BD=../build/
QMAKE=$(BD)
CFLAGS=-c#-Wall -Werror -lstdc++ -std=c++17
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest -I./ -L./
SRC= cave.cc matrix.cc maze.cc pacman.cc maze_gegerator.cc
OBJ=$(addprefix $(BD),$(SRC:.cc=.o))
EXE=$(QMAKE)Maze.app/Contents/MacOS/Maze
APP=$(QMAKE)Maze.app
APPDIR=$(HOME)/Applications/Maze/
APP_EXE=$(APPDIR)Maze.app/Contents/MacOS/Maze
CC=g++
TEST_EXE=main_test.out
TFLAGS=-lgtest -lpthread -lgtest_main


all: install
	$(APP_EXE)

build: $(BD) $(BD)qmake.pro
	cd $(QMAKE); qmake qmake.pro
	make -C $(QMAKE)

./$(BD):
	mkdir $(BD)

./$(BD)qmake.pro:
	cp qmake.pro $(QMAKE)

./$(BD)%.o: */%.cc
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: %.cc
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: */%.cpp
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

install: build 
	@mkdir $(APPDIR) || echo "Directory already exists. Skip."
	cp -rf data/ $(APPDIR)data/
	cp -rf $(APP) $(APPDIR)
	make clean

uninstall:
	rm -rf $(APPDIR)
	rm -rf $(HOME)/Applications/Maze.tar.gz

dvi:
	open dokumentation.html

dist:
	tar -cvf $(APPDIR)../Maze.tar $(APPDIR)
	gzip $(APPDIR)../Maze.tar

test: clean $(TEST_EXE)
	./$(TEST_EXE)

./$(TEST_EXE): $(OBJ) main_test.o
	$(CC) $(LDFLAGS) $^ -o $@ $(TFLAGS)

gcov_report: gcov_build $(BD)main_test.o
	$(CC) $(LDFLAGS) $(LCOVFLAGS) $(OBJ) $(BD)main_test.o -o $(BD)main_gcov_exe $(TFLAGS)
	./$(BD)main_gcov_exe
	# mv *.gcda *.gcno ./$(BD)
	lcov -t "gcov_report" -o $(BD)gcov_report.info -c -d ./$(BD)
	genhtml -o $(BD)report $(BD)gcov_report.info
	open $(BD)report/index.html

gcov_build:
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/matrix.cc -o $(BD)matrix.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/maze.cc -o $(BD)maze.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/maze_gegerator.cc -o $(BD)maze_gegerator.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/cave.cc -o $(BD)cave.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) model/pacman.cc -o $(BD)pacman.o

clean:
	rm -rf *.o *.a *.out *.gcno *.gcda *.info *out.txt *.cfg $(TEST_EXE)
	test -f $(QMAKE)Makefile && make distclean -C $(QMAKE) || printf ""
	rm -rf ./$(BD)*

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ../src/

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n model/*.h
	rm -f .clang-format

leaks:
	leaks --atExit -- ./$(TEST_EXE)

valgrind:
	valgrind --undef-value-errors=no --log-file=valgrind-out.txt ./$(TEST_EXE)
