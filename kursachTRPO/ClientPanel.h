#pragma once
#include "Point.h"
#include "SQLHandler.h"
#include "Сruise.h"
#include "Transport.h"
#include "BuyTicketForm.h"
namespace kursachTRPO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ClientPanel
	/// </summary>
	public ref class ClientPanel : public System::Windows::Forms::Form
	{
	public:
		ClientPanel(void)
		{
			InitializeComponent();
		}

	protected:
		~ClientPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxCruises;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ btnShowAll;
	private: System::Windows::Forms::Button^ btnShowBest;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnShowAll = (gcnew System::Windows::Forms::Button());
			this->btnShowBest = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBoxCruises
			// 
			this->listBoxCruises->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBoxCruises->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxCruises->FormattingEnabled = true;
			this->listBoxCruises->Location = System::Drawing::Point(0, 0);
			this->listBoxCruises->Name = L"listBoxCruises";
			this->listBoxCruises->Size = System::Drawing::Size(1284, 446);
			this->listBoxCruises->TabIndex = 0;
			this->listBoxCruises->SelectedIndexChanged += gcnew System::EventHandler(this, &ClientPanel::listBoxCruises_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Moscow", L"Tver", L"Tula", L"NewYork", L"Tokio" });
			this->comboBox1->Location = System::Drawing::Point(12, 452);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(218, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// btnShowAll
			// 
			this->btnShowAll->Location = System::Drawing::Point(1081, 592);
			this->btnShowAll->Name = L"btnShowAll";
			this->btnShowAll->Size = System::Drawing::Size(191, 35);
			this->btnShowAll->TabIndex = 2;
			this->btnShowAll->Text = L"Все рейсы";
			this->btnShowAll->UseVisualStyleBackColor = true;
			this->btnShowAll->Click += gcnew System::EventHandler(this, &ClientPanel::btnShowAll_Click);
			// 
			// btnShowBest
			// 
			this->btnShowBest->Location = System::Drawing::Point(1081, 633);
			this->btnShowBest->Name = L"btnShowBest";
			this->btnShowBest->Size = System::Drawing::Size(191, 35);
			this->btnShowBest->TabIndex = 3;
			this->btnShowBest->Text = L"Оптимальные рейсы";
			this->btnShowBest->UseVisualStyleBackColor = true;
			this->btnShowBest->Click += gcnew System::EventHandler(this, &ClientPanel::btnShowBest_Click);
			// 
			// ClientPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1284, 681);
			this->Controls->Add(this->btnShowBest);
			this->Controls->Add(this->btnShowAll);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listBoxCruises);
			this->MaximumSize = System::Drawing::Size(1300, 720);
			this->MinimumSize = System::Drawing::Size(1300, 720);
			this->Name = L"ClientPanel";
			this->Text = L"Панель клиента";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
		Persist::SQLHandler handler;
		array<Persist::Сruise^>^ result = handler.GetСruiseList();
		listBoxCruises->Items->Clear();

		if (result == nullptr) {
			MessageBox::Show("Нет рейсов", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			for (int i = 0; i < result->Length; i++) {

				listBoxCruises->Items->Add(result[i]->GetClientInfo());
			}
		}
	}
	private: System::Void btnShowBest_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedItem != nullptr &&
			comboBox1->SelectedItem->ToString() != "") {
			String^ point = comboBox1->SelectedItem->ToString();
			Persist::SQLHandler handler;
			Persist::Сruise^ result = handler.GetBestWay(point);
			listBoxCruises->Items->Clear();

			if (result == nullptr) 
				MessageBox::Show("Нет рейсов", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			else 
				listBoxCruises->Items->Add(result->GetClientInfo());
		}
	}
	private: System::Void listBoxCruises_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		BuyTicketForm form;
		if (listBoxCruises->SelectedItem != nullptr) {
			form.data = listBoxCruises->SelectedItem->ToString();
			form.ShowDialog();
		}
	}
};
}
