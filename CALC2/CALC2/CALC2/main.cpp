#include "MyForm.h"   // подключение заголовочного файла с описанием формы калькулятора

using namespace System;
using namespace System::Windows::Forms;

// Атрибут, указывающий, что приложение работает в однопоточном режиме
// Это необходимо для корректной работы Windows Forms
[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Включение стандартного визуального стиля Windows для элементов формы
    Application::EnableVisualStyles();

    // Установка параметров отображения текста в элементах управления
    Application::SetCompatibleTextRenderingDefault(false);

    // Создание и запуск главной формы приложения
    Application::Run(gcnew CalculatorApp::CalculatorForm());

    // Успешное завершение программы
    return 0;
}