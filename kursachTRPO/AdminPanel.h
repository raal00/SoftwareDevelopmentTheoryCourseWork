#pragma once
#include "Point.h"
#include "SQLHandler.h"
#include "Transport.h"
#include "Сruise.h"

namespace kursachTRPO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Persist;

	/// <summary>
	/// Сводка для AdminPanel
	/// </summary>
	public ref class AdminPanel : public System::Windows::Forms::Form
	{
	public:
		AdminPanel(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AdminPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxCruises;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxId;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxselectId;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxStartDate;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxEndDate;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxPrice;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxIdTransport;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxPointId;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxSpace;
	private: System::Windows::Forms::Button^ btnAddNew;
	private: System::Windows::Forms::Button^ btnRemove;

	private: System::Windows::Forms::Button^ buttonbtncruiselist;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBoxCruises = (gcnew System::Windows::Forms::ListBox());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxselectId = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxStartDate = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxEndDate = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxIdTransport = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxPointId = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxSpace = (gcnew System::Windows::Forms::TextBox());
			this->btnAddNew = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->buttonbtncruiselist = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBoxCruises
			// 
			this->listBoxCruises->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBoxCruises->FormattingEnabled = true;
			this->listBoxCruises->Location = System::Drawing::Point(0, 0);
			this->listBoxCruises->Name = L"listBoxCruises";
			this->listBoxCruises->Size = System::Drawing::Size(1284, 368);
			this->listBoxCruises->TabIndex = 0;
			// 
			// textBoxId
			// 
			this->textBoxId->Location = System::Drawing::Point(141, 374);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->ReadOnly = true;
			this->textBoxId->Size = System::Drawing::Size(146, 20);
			this->textBoxId->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(117, 374);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Id";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(293, 374);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"select Id";
			// 
			// textBoxselectId
			// 
			this->textBoxselectId->Location = System::Drawing::Point(355, 374);
			this->textBoxselectId->Name = L"textBoxselectId";
			this->textBoxselectId->Size = System::Drawing::Size(146, 20);
			this->textBoxselectId->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(45, 403);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Дата отбытия";
			// 
			// textBoxStartDate
			// 
			this->textBoxStartDate->Location = System::Drawing::Point(141, 403);
			this->textBoxStartDate->Name = L"textBoxStartDate";
			this->textBoxStartDate->Size = System::Drawing::Size(146, 20);
			this->textBoxStartDate->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(37, 429);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(98, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Дата прибытия";
			// 
			// textBoxEndDate
			// 
			this->textBoxEndDate->Location = System::Drawing::Point(141, 429);
			this->textBoxEndDate->Name = L"textBoxEndDate";
			this->textBoxEndDate->Size = System::Drawing::Size(146, 20);
			this->textBoxEndDate->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(53, 455);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Цена билета";
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Location = System::Drawing::Point(141, 455);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(146, 20);
			this->textBoxPrice->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(45, 481);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Id транспорта";
			// 
			// textBoxIdTransport
			// 
			this->textBoxIdTransport->Location = System::Drawing::Point(141, 481);
			this->textBoxIdTransport->Name = L"textBoxIdTransport";
			this->textBoxIdTransport->Size = System::Drawing::Size(146, 20);
			this->textBoxIdTransport->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(16, 507);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Id места прибытия";
			// 
			// textBoxPointId
			// 
			this->textBoxPointId->Location = System::Drawing::Point(141, 507);
			this->textBoxPointId->Name = L"textBoxPointId";
			this->textBoxPointId->Size = System::Drawing::Size(146, 20);
			this->textBoxPointId->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(98, 533);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Мест";
			// 
			// textBoxSpace
			// 
			this->textBoxSpace->Location = System::Drawing::Point(141, 533);
			this->textBoxSpace->Name = L"textBoxSpace";
			this->textBoxSpace->Size = System::Drawing::Size(146, 20);
			this->textBoxSpace->TabIndex = 15;
			// 
			// btnAddNew
			// 
			this->btnAddNew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAddNew->Location = System::Drawing::Point(141, 559);
			this->btnAddNew->Name = L"btnAddNew";
			this->btnAddNew->Size = System::Drawing::Size(30, 26);
			this->btnAddNew->TabIndex = 17;
			this->btnAddNew->Text = L"+";
			this->btnAddNew->UseVisualStyleBackColor = true;
			this->btnAddNew->Click += gcnew System::EventHandler(this, &AdminPanel::btnAddNew_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(507, 374);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(75, 20);
			this->btnRemove->TabIndex = 18;
			this->btnRemove->Text = L"Удалить";
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &AdminPanel::btnRemove_Click);
			// 
			// buttonbtncruiselist
			// 
			this->buttonbtncruiselist->Location = System::Drawing::Point(1133, 609);
			this->buttonbtncruiselist->Name = L"buttonbtncruiselist";
			this->buttonbtncruiselist->Size = System::Drawing::Size(139, 60);
			this->buttonbtncruiselist->TabIndex = 20;
			this->buttonbtncruiselist->Text = L"Список рейсов";
			this->buttonbtncruiselist->UseVisualStyleBackColor = true;
			this->buttonbtncruiselist->Click += gcnew System::EventHandler(this, &AdminPanel::buttonbtncruiselist_Click);
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1284, 681);
			this->Controls->Add(this->buttonbtncruiselist);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnAddNew);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxSpace);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxPointId);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxIdTransport);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxPrice);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxEndDate);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxStartDate);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxselectId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->listBoxCruises);
			this->MaximumSize = System::Drawing::Size(1300, 720);
			this->MinimumSize = System::Drawing::Size(1300, 720);
			this->Name = L"AdminPanel";
			this->Text = L"AdminPanel";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRemove_Click(System::Object^ sender, System::EventArgs^ e) {
		Persist::SQLHandler handler;
		if (textBoxselectId->Text != "")
		{
			int id = Convert::ToInt32(textBoxselectId->Text);
			if (handler.RemoveCruise(id)) 
				MessageBox::Show("Готово");
			else
				MessageBox::Show("Ошибка");
		}
	}
	private: System::Void btnAddNew_Click(System::Object^ sender, System::EventArgs^ e) {
		Persist::Сruise^ cruise = gcnew Persist::Сruise();
		Persist::SQLHandler handler;
		cruise->Point = gcnew Persist::Point();
		cruise->Transport = gcnew Persist::Transport();
		//
		if (textBoxPrice->Text != "")
			cruise->Price = Convert::ToInt32(textBoxPrice->Text);
		else
			cruise->Price = 0;
		//
		if (textBoxStartDate->Text != "")
			cruise->StartDate = textBoxStartDate->Text;
		else
			cruise->StartDate = "0000.00.00";
		//
		if (textBoxEndDate->Text != "")
			cruise->EndDate = textBoxEndDate->Text;
		else
			cruise->EndDate = "0000.00.00";
		//
		if (textBoxIdTransport->Text != "")
			cruise->Transport->Id = Convert::ToInt32(textBoxIdTransport->Text);
		else
			cruise->Transport->Id = 0;
		//
		if (textBoxSpace->Text != "")
			cruise->Space = Convert::ToInt32(textBoxSpace->Text);
		else
			cruise->Space = 0;
		//
		if (textBoxPointId->Text != "")
			cruise->Point->Id = Convert::ToInt32(textBoxPointId->Text);
		else
			cruise->Point->Id = 0;
		if (handler.AddNewCruise(cruise))
			MessageBox::Show("Готово");
		else
			MessageBox::Show("Ошибка");
	}
	private: System::Void buttonbtncruiselist_Click(System::Object^ sender, System::EventArgs^ e) {
		Persist::SQLHandler handler;
		array<Persist::Сruise ^>^ result = handler.GetСruiseList();
		listBoxCruises->Items->Clear();

		if (result == nullptr) {
			MessageBox::Show("Нет рейсов", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			for (int i = 0; i < result->Length; i++) {

				listBoxCruises->Items->Add(result[i]->ToString());
			}
		}
	}
};
}
