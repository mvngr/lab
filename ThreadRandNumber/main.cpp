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

const int randNumber = 1000; //Разброс

unsigned short int generateValue()
{
    return static_cast<unsigned short int>( ( rand() % randNumber + 1 ) );
}


void doGenerate(const unsigned int &inId, const unsigned short int &inInputValue, const unsigned int &inIterations, const unsigned int &inDelay, unsigned int &inResult)
{
    for(unsigned int i = 0; i < inIterations; i++)
    {
        if(inResult != inIterations + 1)
            break;

        auto v = generateValue();
        if(v == inInputValue)
        {
            m.lock();
            if(inResult == inIterations+1)
            {
                inResult = i;
            }
            m.unlock();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(inDelay));
        out.lock();
        std::cout << std::this_thread::get_id() << "#" << inId << ':' << i << '-' << v << std::endl;
        out.unlock();
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    unsigned short int inputValue;
    unsigned int iteration;
    unsigned int delay;



    std::cout << "Введите число в диапазоне от 1 до " << randNumber << ": ";
    std::cin >> inputValue;
    std::cout << "Введите общее количество итераций для всех потоков: ";
    std::cin >> iteration;
    std::cout << "Введите квант времени [ms]: ";
    std::cin >> delay;

    unsigned int result = iteration + 1;
    unsigned int threadCount = std::thread::hardware_concurrency();


    std::vector<std::shared_ptr<std::thread>> listThreads;

    for(unsigned int i = 0; i < threadCount; i++)
        listThreads.push_back( std::make_shared<std::thread>( doGenerate, i, std::cref(inputValue), std::cref(iteration), std::cref(delay), std::ref(result) ) );

    auto begin = std::chrono::high_resolution_clock::now();

    for(unsigned int i = 0; i < threadCount; i++)
        listThreads.at(i)->join();

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Время выполнения:" << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms" << std::endl;

    if(result < iteration)
        std::cout << "Победитель: " << result << std::endl;
    else
        std::cout << "Никто не выйграл" << std::endl;

    return 0;
}
