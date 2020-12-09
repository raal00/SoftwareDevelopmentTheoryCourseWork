#pragma once
using namespace System;

#include "Point.h"
#include "Transport.h"


namespace Persist {
	ref class Сruise
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
			return "ID: " + Id + "\t|Отправка: " + StartDate + "\tПрибытие: " + EndDate 
						  + "\tВсего мест: " + Space + "\tЗанято: " + PrivateSpace
						  + " Цена: " + Price
						  + Point->ToString() 
						  + Transport->ToString();
		}
		String^ GetClientInfo() {
			int spc = Space - PrivateSpace;
			return "#" + Id + 
				" \tОтправка: " + StartDate + "  \tПрибытие: " + EndDate
				+ "  \tОсталось мест: " + spc
				+ "\t\tЦена: " + Price + "\t\t" 
				+ Point->PointName + " \t"
				+ Transport->TransportName;
		}
	};
}
