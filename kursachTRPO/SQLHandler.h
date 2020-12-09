#pragma once
using namespace System;
using namespace Data;
using namespace Data::SqlClient;

#include "Ñruise.h"
#include "Transport.h"
#include "Point.h"
namespace Persist {
	ref class SQLHandler
	{
	private:
		bool isConnected = false;
		SqlConnectionStringBuilder^ connectionString;
		SqlConnection^ connection;

		void connect() {
			connectionString = gcnew SqlConnectionStringBuilder();

			connectionString->DataSource = "PERSONAL-PC\\SQLEXPRESS";
			connectionString->InitialCatalog = "TRPOcourse";
			connectionString->IntegratedSecurity = true;


			connection = gcnew SqlConnection(Convert::ToString(connectionString));
			connection->Open();
			if (connection->State == ConnectionState::Open) {
				isConnected = true;
			}
			connection->StateChange += gcnew System::Data::StateChangeEventHandler(this, &SQLHandler::OnStateChange);
		}
		void SQLHandler::OnStateChange(System::Object^ sender, System::Data::StateChangeEventArgs^ e)
		{
			if (e->CurrentState == ConnectionState::Open) {
				isConnected = true;
			}
			else if (e->CurrentState == ConnectionState::Closed) {
				isConnected = false;
			}
		}
	public:
		Transport^ GetTransportById(int id) {
			if (!isConnected) connect();

			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "SELECT * FROM dbo.[Transport] WHERE Id = " + id;
			command->Connection = connection;
			Transport^ result = gcnew Transport();
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read()) {
				result->Id = Convert::ToInt32(reader["Id"]->ToString());
				result->TransportName = reader["TransportName"]->ToString();
				result->TransportSpeed = Convert::ToInt32(reader["TransportSpeed"]->ToString());
			}
			reader->Close();
			return result;
		}
		Point^ GetPointById(int id) {
			if (!isConnected) connect();

			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "SELECT * FROM dbo.[Point] WHERE Id = " + id;
			command->Connection = connection;
			Point^ result = gcnew Point();
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read()) {
				result->Id = Convert::ToInt32(reader["Id"]->ToString());
				result->LengthTo = Convert::ToInt32(reader["LengthTo"]->ToString());
				result->PointName = reader["PointName"]->ToString();
			}
			reader->Close();
			return result;
		}
		int GetWayLenghtByPointId(int id) {
			if (!isConnected) connect();

			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "SELECT LengthTo FROM dbo.[Point] WHERE id = " + id;
			command->Connection = connection;
			return Convert::ToInt32(command->ExecuteScalar()->ToString());
		}

		int GetTableLength(String^ tableName) {
			if (!isConnected) connect();

			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "SELECT count(*) FROM " + tableName;
			command->Connection = connection;
			return Convert::ToInt32(command->ExecuteScalar()->ToString());
		}
		bool RemoveCruise(int id) {
			if (isConnected == false) connect();
			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "DELETE FROM dbo.Ñruise WHERE Id = " + id;

			command->Connection = connection;
			int compleate = command->ExecuteNonQuery();
			return compleate == 1;
		}
		Ñruise^ GetBestWay(String^ point) {
			if (!isConnected) connect();

			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "SELECT TOP 1 * FROM dbo.[Ñruise] JOIN dbo.[Point] ON [Ñruise].PointId = [Point].Id WHERE [Point].[PointName] = '" + point + "' ORDER BY [Ñruise].[EndDate]";
			command->Connection = connection;
			Ñruise^ result = gcnew Ñruise();
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read()) {
				result = gcnew Ñruise();
				result->Id = Convert::ToInt32(reader["Id"]->ToString());
				result->EndDate = reader["EndDate"]->ToString();
				result->StartDate = reader["StartDate"]->ToString();
				result->Price = Convert::ToInt32(reader["Price"]->ToString());
				result->Point = gcnew Point();
				result->Transport = gcnew Transport();
				result->Point->Id = Convert::ToInt32(reader["PointId"]->ToString());
				result->Transport->Id = Convert::ToInt32(reader["TransportId"]->ToString());
				result->PrivateSpace = Convert::ToInt32(reader["PrivateSpace"]->ToString());
				result->Space = Convert::ToInt32(reader["Space"]->ToString());
			}
			reader->Close();
			if (result->Point == nullptr) return nullptr;
			result->Point = GetPointById(result->Point->Id);
			result->Transport = GetTransportById(result->Transport->Id);
			return result;
		}

		bool AddNewCruise(Ñruise^ cruise) {
			if (isConnected == false) connect();
			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "INSERT INTO dbo.[Ñruise] ([StartDate], [EndDate], [PointId], [TransportId], [Space], [PrivateSpace], [Price])"
				+ " VALUES ('" + cruise->StartDate + "','" + cruise->EndDate + "'," + cruise->Point->Id 
				+ "," + cruise->Transport->Id + "," + cruise->Space + "," + cruise->PrivateSpace + "," + cruise->Price + ");";

			command->Connection = connection;
			int compleate = command->ExecuteNonQuery();
			return compleate == 1;
		}
		bool BuyTicket(int cruiseid) {
			if (isConnected == false) connect();
			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "UPDATE dbo.[Ñruise] SET [Ñruise].PrivateSpace = [Ñruise].PrivateSpace + 1 WHERE Id = "+ cruiseid;
			command->Connection = connection;

			int compleate = command->ExecuteNonQuery();
			return compleate == 1;
		}

		array<Ñruise^>^ GetÑruiseList() {

			int studentsCount = GetTableLength("dbo.Ñruise");
			if (studentsCount <= 0) return nullptr;

			array<Ñruise^>^ result = gcnew array<Ñruise^>(studentsCount);
			int index = 0;

			SqlCommand^ command = gcnew SqlCommand();
			command->CommandText = "SELECT * FROM dbo.Ñruise";
			command->Connection = connection;

			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read()) {
				result[index] = gcnew Ñruise();
				result[index]->Id = Convert::ToInt32(reader["Id"]->ToString());
				result[index]->EndDate = reader["EndDate"]->ToString();
				result[index]->StartDate = reader["StartDate"]->ToString();
				result[index]->Price = Convert::ToInt32(reader["Price"]->ToString());
				result[index]->Point = gcnew Point();
				result[index]->Transport = gcnew Transport();
				result[index]->Point->Id = Convert::ToInt32(reader["PointId"]->ToString());
				result[index]->Transport->Id = Convert::ToInt32(reader["TransportId"]->ToString());
				result[index]->PrivateSpace = Convert::ToInt32(reader["PrivateSpace"]->ToString());
				result[index]->Space = Convert::ToInt32(reader["Space"]->ToString());
				index++;
			}
			reader->Close();
			for (int i = 0; i < index; i++) {
				result[i]->Point = GetPointById(result[i]->Point->Id);
				result[i]->Transport = GetTransportById(result[i]->Transport->Id);
			}
			return result;
		}
	};
}
