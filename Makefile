all: demo test

demo: demo.cpp emailNotifier.cpp smsNotifier.cpp
	g++ demo.cpp emailNotifier.cpp smsNotifier.cpp -std=c++17 -lcurl -o demo.exe

test: test.cpp MessageSender.hpp FakeNotifier.cpp notifier.hpp
	g++ test.cpp -std=c++17 -lcurl -o test.exe

rundemo: demo
	./demo.exe

runtest: test
	./test.exe

clean:
	rm demo.exe test.exe > nul || rm -f demo.exe test.exe
