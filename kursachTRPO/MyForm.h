#pragma once
#include "SQLHandler.h"
#include "AdminPanel.h"
#include "ClientPanel.h"

namespace kursachTRPO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClientStart;
	protected:
	private: System::Windows::Forms::Button^ btnAdminStart;
	private: System::Windows::Forms::Button^ btnExit;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnClientStart = (gcnew System::Windows::Forms::Button());
			this->btnAdminStart = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnClientStart
			// 
			this->btnClientStart->BackColor = System::Drawing::Color::DarkSlateGray;
			this->btnClientStart->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnClientStart->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnClientStart->ForeColor = System::Drawing::Color::Magenta;
			this->btnClientStart->Location = System::Drawing::Point(328, 12);
			this->btnClientStart->Name = L"btnClientStart";
			this->btnClientStart->Size = System::Drawing::Size(155, 65);
			this->btnClientStart->TabIndex = 0;
			this->btnClientStart->Text = L"Выбрать рейс";
			this->btnClientStart->UseVisualStyleBackColor = false;
			this->btnClientStart->Click += gcnew System::EventHandler(this, &MyForm::btnClientStart_Click);
			// 
			// btnAdminStart
			// 
			this->btnAdminStart->BackColor = System::Drawing::Color::DarkSlateGray;
			this->btnAdminStart->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAdminStart->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAdminStart->ForeColor = System::Drawing::Color::Magenta;
			this->btnAdminStart->Location = System::Drawing::Point(328, 83);
			this->btnAdminStart->Name = L"btnAdminStart";
			this->btnAdminStart->Size = System::Drawing::Size(155, 65);
			this->btnAdminStart->TabIndex = 1;
			this->btnAdminStart->Text = L"Панель админа";
			this->btnAdminStart->UseVisualStyleBackColor = false;
			this->btnAdminStart->Click += gcnew System::EventHandler(this, &MyForm::btnAdminStart_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::DarkSlateGray;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Gothic3", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->ForeColor = System::Drawing::Color::Magenta;
			this->btnExit->Location = System::Drawing::Point(328, 154);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(155, 65);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkViolet;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(807, 455);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnAdminStart);
			this->Controls->Add(this->btnClientStart);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximumSize = System::Drawing::Size(807, 455);
			this->MinimumSize = System::Drawing::Size(807, 455);
			this->Name = L"MyForm";
			this->Text = L"Транспортная система";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnClientStart_Click(System::Object^ sender, System::EventArgs^ e) {
		ClientPanel form;
		form.ShowDialog();
	}
	private: System::Void btnAdminStart_Click(System::Object^ sender, System::EventArgs^ e) {
		AdminPanel form;
		form.ShowDialog();
	}
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
