#pragma once
#include <chrono>
using namespace std;
using namespace chrono;
class HQ
{
public:
	HQ();
	~HQ();
	void StartTiming() {
		start_time = system_clock::now();
	}
	void PrintTiming() {
		end_time = system_clock::now();
		auto inteval = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
		printf("Runtime : %lldms\n", inteval);
	}
private:
	time_point<system_clock> start_time;
	time_point<system_clock> end_time;
};

HQ::HQ()
{
}

HQ::~HQ()
{
}