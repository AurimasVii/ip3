CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS = -lcurl

CLASS_OBJ = MessageSender.o emailNotifier.o smsNotifier.o
CLASS_SRC = MessageSender.cpp emailNotifier.cpp smsNotifier.cpp
CLASS_HEADER = MessageSender.h emailNotifier.h smsNotifier.h
DEMO_SRC = demo.cpp
TEST_SRC = test.cpp

DEMO_BIN = demo
TEST_BIN = test

TEST_LOG = log.txt

all: build_class build_demo build_test

build_class: $(CLASS_SRC) $(CLASS_HEADER)
	$(CXX) $(CXXFLAGS) -c $(CLASS_SRC)

build_demo: build_class $(DEMO_SRC)
	$(CXX) $(CXXFLAGS) $(CLASS_OBJ) $(DEMO_SRC) -o $(DEMO_BIN) $(LDFLAGS)

FileAndConsoleNotifier.o: FileAndConsoleNotifier.cpp FileAndConsoleNotifier.h
	$(CXX) $(CXXFLAGS) -c FileAndConsoleNotifier.cpp

build_test: build_class FileAndConsoleNotifier.o $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(CLASS_OBJ) FileAndConsoleNotifier.o $(TEST_SRC) -o $(TEST_BIN) $(LDFLAGS)

run_demo: build_demo
	./$(DEMO_BIN)

run_test: build_test
	./$(TEST_BIN)

clean:
	rm -f $(DEMO_BIN) $(TEST_BIN) $(CLASS_OBJ) $(TEST_LOG) *.exe

run_all: run_demo run_test