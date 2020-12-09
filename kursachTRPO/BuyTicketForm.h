#pragma once
#include "SQLHandler.h"
namespace kursachTRPO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для BuyTicketForm
	/// </summary>
	public ref class BuyTicketForm : public System::Windows::Forms::Form
	{
	public:
		BuyTicketForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		String^ data;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BuyTicketForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBoxInfo;
	protected:
	private: System::Windows::Forms::Button^ buttonPay;

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
			this->richTextBoxInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonPay = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBoxInfo
			// 
			this->richTextBoxInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxInfo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->richTextBoxInfo->Dock = System::Windows::Forms::DockStyle::Top;
			this->richTextBoxInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBoxInfo->ForeColor = System::Drawing::Color::ForestGreen;
			this->richTextBoxInfo->Location = System::Drawing::Point(0, 0);
			this->richTextBoxInfo->Name = L"richTextBoxInfo";
			this->richTextBoxInfo->Size = System::Drawing::Size(784, 188);
			this->richTextBoxInfo->TabIndex = 0;
			this->richTextBoxInfo->Text = L"";
			// 
			// buttonPay
			// 
			this->buttonPay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPay->Location = System::Drawing::Point(12, 195);
			this->buttonPay->Name = L"buttonPay";
			this->buttonPay->Size = System::Drawing::Size(760, 54);
			this->buttonPay->TabIndex = 1;
			this->buttonPay->Text = L"Оплатить";
			this->buttonPay->UseVisualStyleBackColor = true;
			this->buttonPay->Click += gcnew System::EventHandler(this, &BuyTicketForm::buttonPay_Click);
			// 
			// BuyTicketForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 261);
			this->Controls->Add(this->buttonPay);
			this->Controls->Add(this->richTextBoxInfo);
			this->MaximumSize = System::Drawing::Size(800, 300);
			this->MinimumSize = System::Drawing::Size(800, 300);
			this->Name = L"BuyTicketForm";
			this->Text = L"BuyTicketForm";
			this->Load += gcnew System::EventHandler(this, &BuyTicketForm::BuyTicketForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BuyTicketForm_Load(System::Object^ sender, System::EventArgs^ e) {
		richTextBoxInfo->Text = data;
	}
	private: System::Void buttonPay_Click(System::Object^ sender, System::EventArgs^ e) {
		int lenght =  data->IndexOf(" ") - 1;
		int id = Convert::ToInt32(data->Substring(1, lenght));
		Persist::SQLHandler handler;
		if (handler.BuyTicket(id))
			MessageBox::Show("Вы купили билет");
		else
			MessageBox::Show("Не удалось купить");
	}
	};
}
