#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do
    {
        try
        {
            int max = 44;
            int div = 0;

            qInfo() << "Enter a number to devide by (Or Zero for issue!)";
            cin >> div;

            if (div == 0)
            {
                throw std::invalid_argument("div must be non-zero");
            } else if (div > 5)
            {
                throw std::out_of_range("the div value should be lower than 5 !!!");
            }

            double answer = max / div;
            qInfo() << answer;
        } catch (const std::exception& e) // implicit conversion from std::invalid_argument to std::exception (safe in UpCasting)
        {
            std::cout << "Caught: " << e.what() << '\n';
        } catch (...) // catch all promte (!!! carefull it always does not catch all exeptions !!!)
        {
            qInfo() << "Other Exeption happened!!!";
            return 0; // will exit the code
        }

    } while(true);

    return QCoreApplication::exec();
}
