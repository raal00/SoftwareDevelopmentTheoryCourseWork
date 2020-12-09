#pragma once
using namespace System;


namespace Persist {
	ref class Point
	{
	public:
		int Id;
		String^ PointName;
		int LengthTo;

		String^ ToString() override {
			return "\tМесто назначения: " + PointName + "\tРасстояние: " + LengthTo;
		}
	};
}
