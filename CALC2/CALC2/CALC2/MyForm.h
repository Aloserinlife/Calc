#pragma once
#include <cmath>

// Подключение необходимых .NET-библиотек для Windows Forms
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

namespace CalculatorApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    // Главный класс формы калькулятора
    public ref class CalculatorForm : public Form {
    private:
        // Поля ввода и вывода
        TextBox^ textBox1;          // поле для ввода первого числа
        TextBox^ textBox2;          // поле для ввода второго числа
        TextBox^ textBoxResult;     // поле для вывода результата

        // Текстовые метки
        Label^ labelOperation;      // метка для отображения текущей операции
        Label^ label1;              // подпись к первому числу
        Label^ label2;              // подпись ко второму числу
        Label^ labelResult;         // подпись к результату

        // Кнопки арифметических операций
        Button^ buttonAdd;          // кнопка сложения
        Button^ buttonSubtract;     // кнопка вычитания
        Button^ buttonMultiply;     // кнопка умножения
        Button^ buttonDivide;       // кнопка деления
        Button^ buttonPower;        // кнопка возведения в степень

        // Кнопки работы с памятью
        Button^ buttonMemoryStore;  // сохранить результат в память
        Button^ buttonMemoryAdd;    // добавить результат к памяти
        Button^ buttonMemoryClear;  // очистить память
        Button^ buttonMemoryTo1;    // поместить память в первое поле
        Button^ buttonMemoryTo2;    // поместить память во второе поле

        // Переменная памяти калькулятора
        double memory = 0;

        // Переменная для хранения текущей операции
        char currentOperation = '+';

    public:
        // Конструктор формы
        // При создании формы вызывается метод инициализации компонентов
        CalculatorForm() {
            InitializeComponent();
        }

    private:
        // Метод создания и настройки всех элементов интерфейса
        void InitializeComponent() {
            // Настройка главной формы
            this->Text = "Калькулятор";
            this->Size = System::Drawing::Size(560, 320);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->BackColor = Color::WhiteSmoke;

            // Создание шрифтов для элементов формы
            System::Drawing::Font^ mainFont = gcnew System::Drawing::Font("Segoe UI", 10);
            System::Drawing::Font^ buttonFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            System::Drawing::Font^ resultFont = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Bold);
            System::Drawing::Font^ opFont = gcnew System::Drawing::Font("Segoe UI", 14, FontStyle::Bold);

            // Поле ввода первого числа
            textBox1 = gcnew TextBox();
            textBox1->Location = System::Drawing::Point(30, 55);
            textBox1->Size = System::Drawing::Size(120, 30);
            textBox1->Font = mainFont;

            // Поле ввода второго числа
            textBox2 = gcnew TextBox();
            textBox2->Location = System::Drawing::Point(210, 55);
            textBox2->Size = System::Drawing::Size(120, 30);
            textBox2->Font = mainFont;

            // Поле вывода результата
            textBoxResult = gcnew TextBox();
            textBoxResult->Location = System::Drawing::Point(390, 55);
            textBoxResult->Size = System::Drawing::Size(130, 32);
            textBoxResult->Font = resultFont;
            textBoxResult->ReadOnly = true;      // пользователь не может вводить сюда данные
            textBoxResult->BackColor = Color::White;
            textBoxResult->ForeColor = Color::DarkBlue;

            // Подпись к первому числу
            label1 = gcnew Label();
            label1->Text = "Первое число";
            label1->Location = System::Drawing::Point(30, 25);
            label1->AutoSize = true;
            label1->Font = mainFont;

            // Подпись ко второму числу
            label2 = gcnew Label();
            label2->Text = "Второе число";
            label2->Location = System::Drawing::Point(210, 25);
            label2->AutoSize = true;
            label2->Font = mainFont;

            // Подпись к результату
            labelResult = gcnew Label();
            labelResult->Text = "Результат";
            labelResult->Location = System::Drawing::Point(390, 25);
            labelResult->AutoSize = true;
            labelResult->Font = mainFont;

            // Метка текущей операции между двумя числами
            labelOperation = gcnew Label();
            labelOperation->Text = "+";
            labelOperation->Location = System::Drawing::Point(165, 53);
            labelOperation->Size = System::Drawing::Size(30, 30);
            labelOperation->Font = opFont;
            labelOperation->TextAlign = ContentAlignment::MiddleCenter;

            // Координаты и размеры для кнопок
            int btnY = 115;      // строка арифметических операций
            int memY = 180;      // строка кнопок памяти
            int btnW = 70;       // ширина кнопок операций
            int btnH = 38;       // высота кнопок
            int gap = 15;        // расстояние между кнопками
            int startX = 30;     // начальная координата X

            // Кнопка сложения
            buttonAdd = gcnew Button();
            buttonAdd->Text = "+";
            buttonAdd->Location = System::Drawing::Point(startX, btnY);
            buttonAdd->Size = System::Drawing::Size(btnW, btnH);
            buttonAdd->Font = buttonFont;
            buttonAdd->BackColor = Color::LightSteelBlue;
            buttonAdd->Click += gcnew EventHandler(this, &CalculatorForm::buttonAdd_Click);

            // Кнопка вычитания
            buttonSubtract = gcnew Button();
            buttonSubtract->Text = "-";
            buttonSubtract->Location = System::Drawing::Point(startX + (btnW + gap), btnY);
            buttonSubtract->Size = System::Drawing::Size(btnW, btnH);
            buttonSubtract->Font = buttonFont;
            buttonSubtract->BackColor = Color::LightSteelBlue;
            buttonSubtract->Click += gcnew EventHandler(this, &CalculatorForm::buttonSubtract_Click);

            // Кнопка умножения
            buttonMultiply = gcnew Button();
            buttonMultiply->Text = "*";
            buttonMultiply->Location = System::Drawing::Point(startX + 2 * (btnW + gap), btnY);
            buttonMultiply->Size = System::Drawing::Size(btnW, btnH);
            buttonMultiply->Font = buttonFont;
            buttonMultiply->BackColor = Color::LightSteelBlue;
            buttonMultiply->Click += gcnew EventHandler(this, &CalculatorForm::buttonMultiply_Click);

            // Кнопка деления
            buttonDivide = gcnew Button();
            buttonDivide->Text = "/";
            buttonDivide->Location = System::Drawing::Point(startX + 3 * (btnW + gap), btnY);
            buttonDivide->Size = System::Drawing::Size(btnW, btnH);
            buttonDivide->Font = buttonFont;
            buttonDivide->BackColor = Color::LightSteelBlue;
            buttonDivide->Click += gcnew EventHandler(this, &CalculatorForm::buttonDivide_Click);

            // Кнопка возведения в степень
            buttonPower = gcnew Button();
            buttonPower->Text = "^";
            buttonPower->Location = System::Drawing::Point(startX + 4 * (btnW + gap), btnY);
            buttonPower->Size = System::Drawing::Size(btnW, btnH);
            buttonPower->Font = buttonFont;
            buttonPower->BackColor = Color::LightSteelBlue;
            buttonPower->Click += gcnew EventHandler(this, &CalculatorForm::buttonPower_Click);

            // Кнопка сохранения результата в память
            buttonMemoryStore = gcnew Button();
            buttonMemoryStore->Text = "П";
            buttonMemoryStore->Location = System::Drawing::Point(startX, memY);
            buttonMemoryStore->Size = System::Drawing::Size(85, btnH);
            buttonMemoryStore->Font = buttonFont;
            buttonMemoryStore->BackColor = Color::MistyRose;
            buttonMemoryStore->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryStore_Click);

            // Кнопка прибавления результата к памяти
            buttonMemoryAdd = gcnew Button();
            buttonMemoryAdd->Text = "П+";
            buttonMemoryAdd->Location = System::Drawing::Point(startX + 95, memY);
            buttonMemoryAdd->Size = System::Drawing::Size(85, btnH);
            buttonMemoryAdd->Font = buttonFont;
            buttonMemoryAdd->BackColor = Color::MistyRose;
            buttonMemoryAdd->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryAdd_Click);

            // Кнопка очистки памяти
            buttonMemoryClear = gcnew Button();
            buttonMemoryClear->Text = "0->П";
            buttonMemoryClear->Location = System::Drawing::Point(startX + 190, memY);
            buttonMemoryClear->Size = System::Drawing::Size(85, btnH);
            buttonMemoryClear->Font = buttonFont;
            buttonMemoryClear->BackColor = Color::MistyRose;
            buttonMemoryClear->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryClear_Click);

            // Кнопка переноса значения памяти в первое поле
            buttonMemoryTo1 = gcnew Button();
            buttonMemoryTo1->Text = "П->1";
            buttonMemoryTo1->Location = System::Drawing::Point(startX + 285, memY);
            buttonMemoryTo1->Size = System::Drawing::Size(85, btnH);
            buttonMemoryTo1->Font = buttonFont;
            buttonMemoryTo1->BackColor = Color::MistyRose;
            buttonMemoryTo1->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryTo1_Click);

            // Кнопка переноса значения памяти во второе поле
            buttonMemoryTo2 = gcnew Button();
            buttonMemoryTo2->Text = "П->2";
            buttonMemoryTo2->Location = System::Drawing::Point(startX + 380, memY);
            buttonMemoryTo2->Size = System::Drawing::Size(85, btnH);
            buttonMemoryTo2->Font = buttonFont;
            buttonMemoryTo2->BackColor = Color::MistyRose;
            buttonMemoryTo2->Click += gcnew EventHandler(this, &CalculatorForm::buttonMemoryTo2_Click);

            // Добавление всех элементов на форму
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

        // Функция проверки правильности ввода двух чисел
        // Если число введено неверно, показывается сообщение об ошибке
        bool check(double& x1, double& x2) {
            double tx1 = 0, tx2 = 0;

            if (!Double::TryParse(textBox1->Text, tx1)) {
                MessageBox::Show("Неверное значение первого числа");
                textBox1->Focus();
                return false;
            }

            if (!Double::TryParse(textBox2->Text, tx2)) {
                MessageBox::Show("Неверное значение второго числа");
                textBox2->Focus();
                return false;
            }

            x1 = tx1;
            x2 = tx2;
            return true;
        }

        // Функция вычисления результата
        // В зависимости от выбранной операции выполняется нужное действие
        void calculateResult() {
            double x1, x2, result = 0;

            // Если ввод некорректный, вычисление не выполняется
            if (!check(x1, x2))
                return;

            switch (currentOperation) {
            case '+':
                result = x1 + x2;
                break;
            case '-':
                result = x1 - x2;
                break;
            case '*':
                result = x1 * x2;
                break;
            case '/':
                // Проверка деления на ноль
                if (x2 == 0) {
                    MessageBox::Show("Деление на ноль невозможно");
                    return;
                }
                result = x1 / x2;
                break;
            case '^':
                // Возведение первого числа во степень второго
                result = System::Math::Pow(x1, x2);
                break;
            }

            // Вывод результата в поле результата
            textBoxResult->Text = Convert::ToString(result);
        }

        // Обработчик кнопки сложения
        void buttonAdd_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '+';
            labelOperation->Text = "+";
            calculateResult();
        }

        // Обработчик кнопки вычитания
        void buttonSubtract_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '-';
            labelOperation->Text = "-";
            calculateResult();
        }

        // Обработчик кнопки умножения
        void buttonMultiply_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '*';
            labelOperation->Text = "*";
            calculateResult();
        }

        // Обработчик кнопки деления
        void buttonDivide_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '/';
            labelOperation->Text = "/";
            calculateResult();
        }

        // Обработчик кнопки возведения в степень
        void buttonPower_Click(Object^ sender, EventArgs^ e) {
            currentOperation = '^';
            labelOperation->Text = "^";
            calculateResult();
        }

        // Сохранение текущего результата в память
        void buttonMemoryStore_Click(Object^ sender, EventArgs^ e) {
            double v = 0;
            if (Double::TryParse(textBoxResult->Text, v))
                memory = v;
            else
                MessageBox::Show("Невозможно сохранить результат в память");
        }

        // Добавление текущего результата к памяти
        void buttonMemoryAdd_Click(Object^ sender, EventArgs^ e) {
            double v = 0;
            if (Double::TryParse(textBoxResult->Text, v))
                memory += v;
            else
                MessageBox::Show("Невозможно добавить результат в память");
        }

        // Очистка памяти
        void buttonMemoryClear_Click(Object^ sender, EventArgs^ e) {
            memory = 0;
            MessageBox::Show("Память очищена");
        }

        // Помещение значения памяти в первое поле
        void buttonMemoryTo1_Click(Object^ sender, EventArgs^ e) {
            textBox1->Text = Convert::ToString(memory);
        }

        // Помещение значения памяти во второе поле
        void buttonMemoryTo2_Click(Object^ sender, EventArgs^ e) {
            textBox2->Text = Convert::ToString(memory);
        }
    };
}