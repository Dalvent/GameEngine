#pragma once

class FrameTime
{
public:
	FrameTime()
	{
	}

	FrameTime(float nowTime)
		: _lastFrameTime(nowTime), _deltaTime(0)
	{
	}

	void NextFrame(float nowTime)
	{
		_deltaTime = nowTime - _lastFrameTime;
		_lastFrameTime = nowTime;
	}

	float GetDeltaTime() { return _deltaTime; }
private:
	float _lastFrameTime;
	float _deltaTime;
};

class TimeStep
{
public:
	TimeStep(float seconds = 0.0f)
		: _seconds(seconds)
	{
	}

	const float GetMiliSeconds() const { return _seconds * 1000.0f; }
	const float GetSeconds() const { return _seconds; }
	const float GetMinutes() const { return _seconds / 60.0f; }
	const float GetHours() const { return _seconds / 360.0f; }
	const float GetDays() const { return _seconds / 8640.0f; }
private:
	float _seconds;
};