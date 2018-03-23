#pragma once
#include <iostream>
#include <ctime> 
#include <cstdlib> 

namespace RandomNumbers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  amount;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  small;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  large;
	private: System::Windows::Forms::Button^  gene;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ListBox^  results;
	private: System::Windows::Forms::Button^  reset;

	private: System::Windows::Forms::Button^  button2;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->amount = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->small = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->large = (gcnew System::Windows::Forms::TextBox());
			this->gene = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->results = (gcnew System::Windows::Forms::ListBox());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Location = System::Drawing::Point(59, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(228, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Random Numbers";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(38, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Generate";
			// 
			// amount
			// 
			this->amount->Location = System::Drawing::Point(108, 92);
			this->amount->Name = L"amount";
			this->amount->Size = System::Drawing::Size(31, 20);
			this->amount->TabIndex = 2;
			this->amount->Text = L"100";
			this->amount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(145, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"random numbers.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(38, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(179, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Numbers should be between";
			// 
			// small
			// 
			this->small->Location = System::Drawing::Point(216, 159);
			this->small->Name = L"small";
			this->small->Size = System::Drawing::Size(31, 20);
			this->small->TabIndex = 5;
			this->small->Text = L"1";
			this->small->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(253, 163);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"and";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// large
			// 
			this->large->Location = System::Drawing::Point(290, 159);
			this->large->Name = L"large";
			this->large->Size = System::Drawing::Size(30, 20);
			this->large->TabIndex = 7;
			this->large->Text = L"100";
			this->large->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// gene
			// 
			this->gene->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gene->Location = System::Drawing::Point(176, 251);
			this->gene->Name = L"gene";
			this->gene->Size = System::Drawing::Size(183, 44);
			this->gene->TabIndex = 8;
			this->gene->Text = L"Generate!";
			this->gene->UseVisualStyleBackColor = true;
			this->gene->Click += gcnew System::EventHandler(this, &MyForm::gene_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(448, 23);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 31);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Results";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// results
			// 
			this->results->FormattingEnabled = true;
			this->results->Location = System::Drawing::Point(454, 57);
			this->results->Name = L"results";
			this->results->Size = System::Drawing::Size(107, 290);
			this->results->TabIndex = 10;
			this->results->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// reset
			// 
			this->reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reset->Location = System::Drawing::Point(12, 224);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(104, 44);
			this->reset->TabIndex = 11;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 290);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 44);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 358);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->results);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->gene);
			this->Controls->Add(this->large);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->small);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->amount);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Random Number Generator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int i;

	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	}

	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	}

	private: System::Void results_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
	}

	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
	
	}

	 private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		 //clear the result box
		 results->Items->Clear();

		 //clear the users input numbers
		 amount->Text = "";
		 small->Text = "";
		 large->Text = "";

		 i = 0;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Application::Exit();
	}
	
	private: System::Void gene_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//CODE
		results->Items->Clear();

		int Rnum;
		String ^ Numbers;
		srand(time(0));

		//User amount
		String ^ size = amount->Text;
		int sizei = System::Convert::ToInt16(size);

		//Smallest number
		String ^ low = small->Text;
		int lowi = System::Convert::ToInt16(low);

		//Largest number
		String ^ high = large->Text;
		int highi = System::Convert::ToInt16(high);


		if (lowi > highi)
		{
			MessageBox::Show("Dumbass, lowest number cant be greater than the biggest number!", "ERROR!");
			results->Items->Clear();

			//clear the users input numbers
			amount->Text = "";
			small->Text = "";
			large->Text = "";
			highi = 69; //aren't I so funny...
		}

		for (i = 0; i < sizei; i++)
		{
			Rnum = lowi + (rand() % highi);
			Numbers = System::Convert::ToString(Rnum);
			results->Items->Add(Numbers);
		}
	}
};
}
