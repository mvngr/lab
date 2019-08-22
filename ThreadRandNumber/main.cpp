#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <mutex>
#include <chrono>

static std::mutex m; //мьютекс для записи результата
static std::mutex out; //мьютекс для вывода в паралельных действиях

const int maxNumber = 100000; //Разброс

unsigned int generateValue()
{
    return static_cast<unsigned int>( ( rand() % maxNumber + 1 ) );
}

void doGenerate(const unsigned int &inId, const unsigned int &inInputValue, const unsigned int &inIterations, const unsigned int &inDelay, unsigned int &inResult)
{
    for(unsigned int i = 0; i < inIterations; i++)
    {
        if(inResult != maxNumber + 1) //когда число найдено - прекращаем цикл
            break;

        unsigned int v = generateValue(); //генерируем число
        if(v == inInputValue) //если числа совпадают
        {
            m.lock(); //лочим для записи
            if(inResult == maxNumber+1) //еще раз проверяем, ибо пока шли до lock'а могли уже поступить записи
            {
                inResult = i; //пишем
            }
            m.unlock(); //отпускаем мьютекс
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(inDelay)); //спим
        out.lock(); //лочим для коректного вывода в консоль
        std::cout << std::this_thread::get_id() << "#" << inId << ':' << i << '-' << v << std::endl;
        out.unlock();
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    unsigned int inputValue;
    unsigned int iteration;
    unsigned int delay;



    std::cout << "Введите число в диапазоне от 1 до " << maxNumber << ": ";
    std::cin >> inputValue;
    std::cout << "Введите общее количество итераций для всех потоков: ";
    std::cin >> iteration;
    std::cout << "Введите квант времени [ms]: ";
    std::cin >> delay;

    unsigned int result = maxNumber + 1; //делаем изначальный результат недостижимым. Можно было сделать при помощи bool делать проверку, но тогда на один параметр больше бы стало
    unsigned int threadCount = std::thread::hardware_concurrency(); //можно и запрашивать количество, но удобнее использовать количество тредов, доступных железу

    std::vector<std::shared_ptr<std::thread>> listThreads; //хранитель тредов

    for(unsigned int i = 0; i < threadCount; i++) //заполняем треды
        listThreads.push_back( std::make_shared<std::thread>( doGenerate, i, std::cref(inputValue), std::cref(iteration), std::cref(delay), std::ref(result) ) );

    auto begin = std::chrono::high_resolution_clock::now(); //замечаем начало

    for(unsigned int i = 0; i < threadCount; i++) //запускаем все треды
        listThreads.at(i)->join();

    auto end = std::chrono::high_resolution_clock::now(); //замечаем конец
    std::cout << "Время выполнения:" << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms" << std::endl;

    if(result < maxNumber) //проверка на корректное нахождение результата
        std::cout << "Победитель: " << result << std::endl;
    else
        std::cout << "Никто не выйграл" << std::endl;

    return 0;
}
