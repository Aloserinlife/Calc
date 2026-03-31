#pragma once

// Подключение необходимых библиотек .NET
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

// Пространство имен приложения решения квадратного уравнения
namespace EquationSolverApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    // Главная форма приложения
    public ref class MyForm : public Form
    {
    private:
        // Метки (подписи для полей)
        Label^ labelA;
        Label^ labelB;
        Label^ labelC;
        Label^ labelResult;

        // Поля ввода коэффициентов
        TextBox^ textBoxA;
        TextBox^ textBoxB;
        TextBox^ textBoxC;

        // Поле вывода результата
        TextBox^ textBoxResult;

        // Кнопка запуска вычисления
        Button^ buttonSolve;

    public:
        // Конструктор формы
        MyForm()
        {
            InitializeComponent();
        }

    private:

        // Метод создания и настройки элементов интерфейса
        void InitializeComponent()
        {
            // Настройка формы
            this->Text = "Решение квадратного уравнения";
            this->Size = System::Drawing::Size(500, 300);
            this->StartPosition = FormStartPosition::CenterScreen;

            // Подпись коэффициента a
            labelA = gcnew Label();
            labelA->Text = "Коэффициент a";
            labelA->Location = Point(30, 30);
            labelA->AutoSize = true;

            // Поле ввода a
            textBoxA = gcnew TextBox();
            textBoxA->Location = Point(180, 30);
            textBoxA->Width = 120;

            // Подпись коэффициента b
            labelB = gcnew Label();
            labelB->Text = "Коэффициент b";
            labelB->Location = Point(30, 70);
            labelB->AutoSize = true;

            // Поле ввода b
            textBoxB = gcnew TextBox();
            textBoxB->Location = Point(180, 70);
            textBoxB->Width = 120;

            // Подпись коэффициента c
            labelC = gcnew Label();
            labelC->Text = "Коэффициент c";
            labelC->Location = Point(30, 110);
            labelC->AutoSize = true;

            // Поле ввода c
            textBoxC = gcnew TextBox();
            textBoxC->Location = Point(180, 110);
            textBoxC->Width = 120;

            // Кнопка запуска решения уравнения
            buttonSolve = gcnew Button();
            buttonSolve->Text = "Решить";
            buttonSolve->Location = Point(180, 150);
            buttonSolve->Width = 120;
            buttonSolve->Click += gcnew EventHandler(this, &MyForm::buttonSolve_Click);

            // Подпись результата
            labelResult = gcnew Label();
            labelResult->Text = "Результат";
            labelResult->Location = Point(30, 200);
            labelResult->AutoSize = true;

            // Поле вывода результата
            textBoxResult = gcnew TextBox();
            textBoxResult->Location = Point(110, 200);
            textBoxResult->Width = 320;
            textBoxResult->ReadOnly = true;

            // Добавление элементов на форму
            this->Controls->Add(labelA);
            this->Controls->Add(textBoxA);
            this->Controls->Add(labelB);
            this->Controls->Add(textBoxB);
            this->Controls->Add(labelC);
            this->Controls->Add(textBoxC);
            this->Controls->Add(buttonSolve);
            this->Controls->Add(labelResult);
            this->Controls->Add(textBoxResult);
        }

        // Функция проверки корректности введённых коэффициентов
        bool checkValues(double% a, double% b, double% c)
        {
            // Проверка коэффициента a
            if (!Double::TryParse(textBoxA->Text, a))
            {
                MessageBox::Show("Неверное значение коэффициента a");
                textBoxA->Focus();
                return false;
            }

            // Проверка коэффициента b
            if (!Double::TryParse(textBoxB->Text, b))
            {
                MessageBox::Show("Неверное значение коэффициента b");
                textBoxB->Focus();
                return false;
            }

            // Проверка коэффициента c
            if (!Double::TryParse(textBoxC->Text, c))
            {
                MessageBox::Show("Неверное значение коэффициента c");
                textBoxC->Focus();
                return false;
            }

            return true;
        }

        // Обработчик кнопки "Решить"
        void buttonSolve_Click(Object^ sender, EventArgs^ e)
        {
            double a, b, c;

            // Проверяем корректность ввода
            if (!checkValues(a, b, c))
                return;

            // Если a = 0, уравнение становится линейным
            if (a == 0)
            {
                // bx + c = 0
                if (b == 0)
                {
                    if (c == 0)
                        textBoxResult->Text = "Бесконечно много решений";
                    else
                        textBoxResult->Text = "Решений нет";
                }
                else
                {
                    // Решение линейного уравнения
                    double x = -c / b;
                    textBoxResult->Text = "Линейное уравнение. x = " + Convert::ToString(x);
                }

                return;
            }

            // Вычисление дискриминанта
            double D = b * b - 4 * a * c;

            // Если дискриминант положительный — два корня
            if (D > 0)
            {
                double x1 = (-b + Math::Sqrt(D)) / (2 * a);
                double x2 = (-b - Math::Sqrt(D)) / (2 * a);

                textBoxResult->Text =
                    "Два корня: x1 = " + Convert::ToString(x1) +
                    "; x2 = " + Convert::ToString(x2);
            }
            // Если дискриминант равен нулю — один корень
            else if (D == 0)
            {
                double x = -b / (2 * a);
                textBoxResult->Text = "Один корень: x = " + Convert::ToString(x);
            }
            // Если дискриминант отрицательный — действительных корней нет
            else
            {
                textBoxResult->Text = "Действительных корней нет";
            }
        }
    };
}