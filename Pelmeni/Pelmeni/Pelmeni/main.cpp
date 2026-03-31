#include "MyForm.h"   // подключение заголовочного файла с описанием формы приложения

using namespace System;
using namespace System::Windows::Forms;

// Атрибут, указывающий, что приложение работает в однопоточном режиме.
// Это требуется для корректной работы Windows Forms.
[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Включение стандартного визуального стиля Windows
    // (кнопки, поля и другие элементы будут выглядеть как в системе)
    Application::EnableVisualStyles();

    // Настройка совместимого режима отображения текста
    Application::SetCompatibleTextRenderingDefault(false);

    // Создание и запуск главной формы программы
    // В данном случае запускается форма решения квадратного уравнения
    Application::Run(gcnew EquationSolverApp::MyForm());

    // Завершение программы
    return 0;
}