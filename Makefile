all:

	g++ -Wall -Wextra -I interface include include/monitor-indicators -o cnc_test src/Cnc_monitor.cpp test/cnc_test.cpp -lgtest -lpthread -std=c++11
