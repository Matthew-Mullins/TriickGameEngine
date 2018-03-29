#pragma once

class Time {
public:
	Time() : timeValueSeconds(0.0f) { }
	Time(double _timeValueSeconds) : timeValueSeconds((float)_timeValueSeconds) { }
	
	inline float GetTimeSeconds() { return timeValueSeconds; };
	inline float GetTimeMilliseconds() { return timeValueSeconds * 1000; };

	inline float operator+(Time _timeValue) { return timeValueSeconds + _timeValue.GetTimeSeconds(); }
	inline float operator-(Time _timeValue) { return timeValueSeconds - _timeValue.GetTimeSeconds(); }
	inline void operator+=(Time _timeValue) { timeValueSeconds += _timeValue.GetTimeSeconds(); }
	inline void operator-=(Time _timeValue) { timeValueSeconds -= _timeValue.GetTimeSeconds(); }

private:
	float timeValueSeconds;
};