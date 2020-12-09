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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminPanel::typeid));
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
			this->listBoxCruises->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->listBoxCruises->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBoxCruises->Font = (gcnew System::Drawing::Font(L"Gothic3", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxCruises->ForeColor = System::Drawing::Color::Cyan;
			this->listBoxCruises->FormattingEnabled = true;
			this->listBoxCruises->ItemHeight = 14;
			this->listBoxCruises->Location = System::Drawing::Point(0, 0);
			this->listBoxCruises->Name = L"listBoxCruises";
			this->listBoxCruises->Size = System::Drawing::Size(1264, 354);
			this->listBoxCruises->TabIndex = 0;
			// 
			// textBoxId
			// 
			this->textBoxId->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxId->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxId->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxId->Location = System::Drawing::Point(211, 370);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->ReadOnly = true;
			this->textBoxId->Size = System::Drawing::Size(146, 28);
			this->textBoxId->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(167, 376);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Id";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(540, 377);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"select Id";
			// 
			// textBoxselectId
			// 
			this->textBoxselectId->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxselectId->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxselectId->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxselectId->Location = System::Drawing::Point(657, 371);
			this->textBoxselectId->Name = L"textBoxselectId";
			this->textBoxselectId->Size = System::Drawing::Size(146, 28);
			this->textBoxselectId->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Cyan;
			this->label3->Location = System::Drawing::Point(29, 410);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 22);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Дата отбытия";
			// 
			// textBoxStartDate
			// 
			this->textBoxStartDate->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxStartDate->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxStartDate->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxStartDate->Location = System::Drawing::Point(211, 404);
			this->textBoxStartDate->Name = L"textBoxStartDate";
			this->textBoxStartDate->Size = System::Drawing::Size(146, 28);
			this->textBoxStartDate->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Cyan;
			this->label4->Location = System::Drawing::Point(22, 443);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(183, 22);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Дата прибытия";
			// 
			// textBoxEndDate
			// 
			this->textBoxEndDate->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxEndDate->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxEndDate->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxEndDate->Location = System::Drawing::Point(211, 437);
			this->textBoxEndDate->Name = L"textBoxEndDate";
			this->textBoxEndDate->Size = System::Drawing::Size(146, 28);
			this->textBoxEndDate->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Cyan;
			this->label5->Location = System::Drawing::Point(56, 477);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(149, 22);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Цена билета";
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxPrice->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPrice->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxPrice->Location = System::Drawing::Point(211, 471);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(146, 28);
			this->textBoxPrice->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Cyan;
			this->label6->Location = System::Drawing::Point(51, 514);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 19);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Id транспорта";
			// 
			// textBoxIdTransport
			// 
			this->textBoxIdTransport->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxIdTransport->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxIdTransport->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxIdTransport->Location = System::Drawing::Point(211, 505);
			this->textBoxIdTransport->Name = L"textBoxIdTransport";
			this->textBoxIdTransport->Size = System::Drawing::Size(146, 28);
			this->textBoxIdTransport->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::Cyan;
			this->label7->Location = System::Drawing::Point(111, 545);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 22);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Id м. н.";
			// 
			// textBoxPointId
			// 
			this->textBoxPointId->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxPointId->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPointId->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxPointId->Location = System::Drawing::Point(211, 539);
			this->textBoxPointId->Name = L"textBoxPointId";
			this->textBoxPointId->Size = System::Drawing::Size(146, 28);
			this->textBoxPointId->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Cyan;
			this->label8->Location = System::Drawing::Point(130, 579);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 22);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Мест";
			// 
			// textBoxSpace
			// 
			this->textBoxSpace->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->textBoxSpace->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSpace->ForeColor = System::Drawing::Color::Cyan;
			this->textBoxSpace->Location = System::Drawing::Point(211, 573);
			this->textBoxSpace->Name = L"textBoxSpace";
			this->textBoxSpace->Size = System::Drawing::Size(146, 28);
			this->textBoxSpace->TabIndex = 15;
			// 
			// btnAddNew
			// 
			this->btnAddNew->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->btnAddNew->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddNew->Font = (gcnew System::Drawing::Font(L"Gothic3", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAddNew->ForeColor = System::Drawing::Color::Cyan;
			this->btnAddNew->Location = System::Drawing::Point(211, 607);
			this->btnAddNew->Name = L"btnAddNew";
			this->btnAddNew->Size = System::Drawing::Size(46, 36);
			this->btnAddNew->TabIndex = 17;
			this->btnAddNew->Text = L"+";
			this->btnAddNew->UseVisualStyleBackColor = false;
			this->btnAddNew->Click += gcnew System::EventHandler(this, &AdminPanel::btnAddNew_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->btnRemove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRemove->Font = (gcnew System::Drawing::Font(L"Gothic3", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRemove->ForeColor = System::Drawing::Color::Cyan;
			this->btnRemove->Location = System::Drawing::Point(809, 371);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(91, 28);
			this->btnRemove->TabIndex = 18;
			this->btnRemove->Text = L"Удалить";
			this->btnRemove->UseVisualStyleBackColor = false;
			this->btnRemove->Click += gcnew System::EventHandler(this, &AdminPanel::btnRemove_Click);
			// 
			// buttonbtncruiselist
			// 
			this->buttonbtncruiselist->BackColor = System::Drawing::Color::Cyan;
			this->buttonbtncruiselist->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonbtncruiselist->Font = (gcnew System::Drawing::Font(L"Gothic3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonbtncruiselist->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->buttonbtncruiselist->Location = System::Drawing::Point(544, 420);
			this->buttonbtncruiselist->Name = L"buttonbtncruiselist";
			this->buttonbtncruiselist->Size = System::Drawing::Size(107, 60);
			this->buttonbtncruiselist->TabIndex = 20;
			this->buttonbtncruiselist->Text = L"Список рейсов";
			this->buttonbtncruiselist->UseVisualStyleBackColor = false;
			this->buttonbtncruiselist->Click += gcnew System::EventHandler(this, &AdminPanel::buttonbtncruiselist_Click);
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1264, 681);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->MaximumSize = System::Drawing::Size(1280, 720);
			this->MinimumSize = System::Drawing::Size(1280, 720);
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
