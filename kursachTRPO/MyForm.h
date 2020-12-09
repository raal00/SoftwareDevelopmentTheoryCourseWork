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
			this->btnClientStart = (gcnew System::Windows::Forms::Button());
			this->btnAdminStart = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnClientStart
			// 
			this->btnClientStart->Location = System::Drawing::Point(328, 64);
			this->btnClientStart->Name = L"btnClientStart";
			this->btnClientStart->Size = System::Drawing::Size(155, 65);
			this->btnClientStart->TabIndex = 0;
			this->btnClientStart->Text = L"Выбрать рейс";
			this->btnClientStart->UseVisualStyleBackColor = true;
			this->btnClientStart->Click += gcnew System::EventHandler(this, &MyForm::btnClientStart_Click);
			// 
			// btnAdminStart
			// 
			this->btnAdminStart->Location = System::Drawing::Point(328, 135);
			this->btnAdminStart->Name = L"btnAdminStart";
			this->btnAdminStart->Size = System::Drawing::Size(155, 65);
			this->btnAdminStart->TabIndex = 1;
			this->btnAdminStart->Text = L"Панель администратора";
			this->btnAdminStart->UseVisualStyleBackColor = true;
			this->btnAdminStart->Click += gcnew System::EventHandler(this, &MyForm::btnAdminStart_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(328, 206);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(155, 65);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 501);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnAdminStart);
			this->Controls->Add(this->btnClientStart);
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
