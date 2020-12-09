#pragma once
using namespace System;

#include "Point.h"
#include "Transport.h"


namespace Persist {
	ref class �ruise
	{
	public:
		int Id;
		String^ StartDate;
		String^ EndDate;

		Point^ Point;
		Transport^ Transport;

		int Space;
		int PrivateSpace;
		int Price;

		String^ ToString() override {
			return "ID: " + Id + "\t|��������: " + StartDate + "\t��������: " + EndDate 
						  + "\t����� ����: " + Space + "\t������: " + PrivateSpace
						  + " ����: " + Price
						  + Point->ToString() 
						  + Transport->ToString();
		}
		String^ GetClientInfo() {
			int spc = Space - PrivateSpace;
			return "#" + Id + 
				" \t��������: " + StartDate + "  \t��������: " + EndDate
				+ "  \t�������� ����: " + spc
				+ "\t\t����: " + Price + "\t\t" 
				+ Point->PointName + " \t"
				+ Transport->TransportName;
		}
	};
}
