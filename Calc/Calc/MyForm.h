#pragma once
#include <cmath> // Для математических операций, таких как pow

namespace CalculatorApp {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class CalculatorForm : public Form {
    private:
        TextBox^ textBox1;
        TextBox^ textBox2;
        TextBox^ textBoxResult;
        Label^ labelOperation;
        Label^ label1;
        Label^ label2;
        Label^ labelResult;
        Button^ buttonAdd;
        Button^ buttonSubtract;
        Button^ buttonMultiply;
        Button^ buttonDivide;
        Button^ buttonPower;

        Button^ buttonMemoryStore;
        Button^ buttonMemoryAdd;
        Button^ buttonMemoryClear;
        Button^ buttonMemoryTo1;
        Button^ buttonMemoryTo2;

        double memory = 0;

        char currentOperation = '+'; // Текущая операция

    public:
        CalculatorForm() {
            InitializeComponent();
        }

    private:
        void InitializeComponent() {
            this->Text = "Калькулятор";
            this->Size = System::Drawing::Size(500, 300);
            this->StartPosition = FormStartPosition::CenterScreen;

            textBox1 = gcnew TextBox();
            textBox1->Location = System::Drawing::Point(20, 50);
            textBox1->Width = 80;

            textBox2 = gcnew TextBox();
            textBox2->Location = System::Drawing::Point(140, 50);
            textBox2->Width = 80;

            textBoxResult = gcnew TextBox();
            textBoxResult->Location = System::Drawing::Point(260, 50);
            textBoxResult->Width = 80;
            textBoxResult->ReadOnly = true;

            label1 = gcnew Label();
            label1->Text = "Первое число";
            label1->Location = System::Drawing::Point(20, 20);

            label2 = gcnew Label();
            label2->Text = "Второе число";
            label2->Location = System::Drawing::Point(140, 20);

            labelResult = gcnew Label();
            labelResult->Text = "Результат";
            labelResult->Location = System::Drawing::Point(260, 20);

            labelOperation = gcnew Label();
            labelOperation->Text = "+";
            labelOperation->Location = System::Drawing::Point(110, 55);
            labelOperation->Width = 20;

            buttonAdd = gcnew Button();
            buttonAdd->Text = "+";
            buttonAdd->Location = System::Drawing::Point(20, 100);
            buttonAdd->Click += gcnew EventHandler(this, &CalculatorForm::buttonAdd_Click);

            buttonSubtract = gcnew Button();
            buttonSubtract->Text = "-";
            buttonSubtract->Location = System::Drawing::Point(80, 100);
            buttonSubtract->Click += gcnew EventHandler(this, &CalculatorForm::buttonSubtract_Click);

            buttonMultiply = gcnew Button();
            buttonMultiply->Text = "*";
            buttonMultiply->Location = System::Drawing::Point(140, 100);
            buttonMultiply->Click += gcnew EventHandler(this, &CalculatorForm::buttonMultiply_Click);

            buttonDivide = gcnew Button();
            buttonDivide->Text = "/";
            buttonDivide->Location = System::Drawing::Point(200, 100);
            buttonDivide->Click += gcnew EventHandler(this, &CalculatorForm::buttonDivide_Click);

            buttonPower = gcnew Button();
            buttonPower->Text = "^";
            buttonPower->Location = System::Drawing::Point(260, 100);
            buttonPower->Click += gcnew EventHandler(this, &CalculatorForm::buttonPower_Click);

            buttonMemoryStore = gcnew Button();
            buttonMemoryStore->Text = "П";
            buttonMemoryStore->Location = System::Drawing::Point(20, 150);
            buttonMemoryStore->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryStore_Click);

            buttonMemoryAdd = gcnew Button();
            buttonMemoryAdd->Text = "П+";
            buttonMemoryAdd->Location = System::Drawing::Point(80, 150);
            buttonMemoryAdd->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryAdd_Click);

            buttonMemoryClear = gcnew Button();
            buttonMemoryClear->Text = "0П";
            buttonMemoryClear->Location = System::Drawing::Point(140, 150);
            buttonMemoryClear->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryClear_Click);

            buttonMemoryTo1 = gcnew Button();
            buttonMemoryTo1->Text = "П1";
            buttonMemoryTo1->Location = System::Drawing::Point(200, 150);
            buttonMemoryTo1->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryTo1_Click);

            buttonMemoryTo2 = gcnew Button();
            buttonMemoryTo2->Text = "П2";
            buttonMemoryTo2->Location = System::Drawing::Point(260, 150);
            buttonMemoryTo2->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryTo2_Click);

            this->Controls->Add(textBox1);
            this->Controls->Add(textBox2);
            this->Controls->Add(textBoxResult);
            this->Controls->Add(label1);
            this->Controls->Add(label2);
            this->Controls->Add(labelResult);
            this->Controls->Add(labelOperation);
            this->Controls->Add(buttonAdd);
            this->Controls->Add(buttonSubtract);
            this->Controls->Add(buttonMultiply);
            this->Controls->Add(buttonDivide);
            this->Controls->Add(buttonPower);
            this->Controls->Add(buttonMemoryStore);
            this->Controls->Add(buttonMemoryAdd);
            this->Controls->Add(buttonMemoryClear);
            this->Controls->Add(buttonMemoryTo1);
            this->Controls->Add(buttonMemoryTo2);
        }

        bool check(double& x1, double& x2) {
            try {
                x1 = Convert::ToDouble(textBox1->Text);
            }
            catch (...) {
                MessageBox::Show("Неверное значение первого операнда");
                return false;
            }

            try {
                x2 = Convert::ToDouble(textBox2->Text);
            }
            catch (...) {
                MessageBox::Show("Неверное значение второго операнда");
                return false;
            }

            return true;
        }

        void calculateResult() {
            double x1, x2, result = 0;
            if (!check(x1, x2)) return;

            switch (currentOperation) {
            case '+': result = x1 + x2; break;
            case '-': result = x1 - x2; break;
            case '*': result = x1 * x2; break;
            case '/': result = (x2 != 0) ? x1 / x2 : 0; break;
            case '^': result = pow(x1, x2); break;
            }

            textBoxResult->Text = Convert::ToString(result);
        }

        void buttonAdd_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '+';
            labelOperation->Text = "+";
            calculateResult();
        }

        void buttonSubtract_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '-';
            labelOperation->Text = "-";
            calculateResult();
        }

        void buttonMultiply_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '*';
            labelOperation->Text = "*";
            calculateResult();
        }

        void buttonDivide_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '/';
            labelOperation->Text = "/";
            calculateResult();
        }

        void buttonPower_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '^';
            labelOperation->Text = "^";
            calculateResult();
        }

        void buttonMemoryStore_Click(Object^ sender, EventArgs^ e) {
            try {
                memory = Convert::ToDouble(textBoxResult->Text);
            }
            catch (...) {
                MessageBox::Show("Ошибка сохранения в память");
            }
        }

        void buttonMemoryAdd_Click(Object^ sender, EventArgs^ e) {
            try {
                memory += Convert::ToDouble(textBoxResult->Text);
            }
            catch (...) {
                MessageBox::Show("Ошибка добавления в память");
            }
        }

        void buttonMemoryClear_Click(Object^ sender, EventArgs^ e) {
            memory = 0;
        }

        void buttonMemoryTo1_Click(Object^ sender, EventArgs^ e) {
            textBox1->Text = Convert::ToString(memory);
            calculateResult();
        }

        void buttonMemoryTo2_Click(Object^ sender, EventArgs^ e) {
            textBox2->Text = Convert::ToString(memory);
            calculateResult();
        }
    };
}
