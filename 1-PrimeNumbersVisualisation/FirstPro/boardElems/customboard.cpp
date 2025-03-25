#include "customboard.h"
#include "guiElems/customscene.h"
#include "logicElems/sieveeratosthenes.h"
#include <QTimer>
#include <QEventLoop>

CustomBoard::CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    Q_UNUSED(N)
    this->setRect(rectBoard);
}

void CustomBoard::initVecBlocks(int N)
{
    //очистка доски и вектора для новых данных
    if(vecBlocks.size() > 0){
        for(auto& elem : vecBlocks)
            this->scene()->removeItem(elem);

        vecBlocks.clear();
    }

    //заполнение доски
    N++;
    vecBlocks.resize(N);
    int iterX = 0;
    int iterY = 0;
    for(int i = 0; i < N; i++){
        CustomBlock* block = new CustomBlock(iterX, iterY, i, this);
        iterX++;
        if(iterX == 10){
            iterX = 0;
            iterY++;
        }
        vecBlocks[i] = block;
    }
    //исключительная ситуация
    if(vecBlocks[0] != nullptr){
        vecBlocks[0]->changeColor(Qt::blue);
        vecBlocks[0]->setPrimeStatus(false);
    }
    //исключительная ситуация
    if(vecBlocks[1] != nullptr){
        vecBlocks[1]->changeColor(Qt::blue);
        vecBlocks[1]->setPrimeStatus(false);
    }


    // Создаем массив для отметки простых чисел
    QVector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Алгоритм Решета Эратосфена
    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            // Вычеркиваем все кратные p, начиная с p²
            for (int i = p * p; i <= N; i += p) {
                for(auto& elem : vecBlocks){
                    if(elem->getNumber() == i){
                        // Задержка 1 секунда с обработкой событий
                        QTimer timer;
                        QEventLoop loop;
                        timer.setSingleShot(true);
                        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                        timer.start(10); // 1000 мс = 1 секунда
                        loop.exec(); // Ожидаем завершения таймера
                        QObject::disconnect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                        elem->changeColor(Qt::red);
                        elem->setPrimeStatus(false);
                    }

                }
                isPrime[i] = false;
            }
        }
    }

    for(auto& elem : vecBlocks){
        if(elem->getPrimeStatus()){
            QTimer timer;
            QEventLoop loop;
            timer.setSingleShot(true);
            QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
            timer.start(40); // 1000 мс = 1 секунда
            loop.exec(); // Ожидаем завершения таймера
            QObject::disconnect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
            elem->changeColor(Qt::green);
            emit signalToSendPrimeNumber(QString::number(elem->getNumber()));
        }
    }

    // Собираем все простые числа в результат
    QVector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }




}
