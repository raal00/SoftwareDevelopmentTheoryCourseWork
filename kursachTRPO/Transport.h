#pragma once
using namespace System;


namespace Persist {
	ref class Transport
	{
	public:
		int Id;
		String^ TransportName;
		int TransportSpeed;

		String^ ToString() override {
			return "\tНаименование: " + TransportName + "\tСкорость: " + TransportSpeed;
		}
	};
}
