#include "customboard.h"

CustomBoard::CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    Q_UNUSED(N)
    this->setRect(rectBoard);
}

QVector<CustomBlock *> CustomBoard::getVecBlocks() const
{
    return _vecBlocks;
}

void CustomBoard::initVecBlocks(int N)
{
    this->setPos(0, 0);

    //очистка доски и вектора для новых данных
    if(_vecBlocks.size() > 0){
        for(auto& elem : _vecBlocks)
            this->scene()->removeItem(elem);

        _vecBlocks.clear();
    }

    //заполнение доски
    N++;
    _vecBlocks.resize(N);
    int iterX = 0;
    int iterY = 0;
    for(int i = 0; i < N; i++){
        CustomBlock* block = new CustomBlock(iterX, iterY, i, this);
        iterX++;
        if(iterX == 10){
            iterX = 0;
            iterY++;
        }
        _vecBlocks[i] = block;
    }

    // Создаем массив для отметки простых чисел
    QVector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    //исключительная ситуация 0 - простое число
    if(_vecBlocks[0] != nullptr){
        _vecBlocks[0]->changeColor(Qt::blue);
        _vecBlocks[0]->setPrimeStatus(false);
    }
    //исключительная ситуация
    if(_vecBlocks[1] != nullptr){
        _vecBlocks[1]->changeColor(Qt::blue);
        _vecBlocks[1]->setPrimeStatus(false);
    }

    // Алгоритм Решета Эратосфена: https://ru.wikipedia.org/wiki/Решето_Эратосфена
    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            // Вычеркиваем все кратные p, начиная с p^2
            for (int i = p * p; i <= N; i += p) {
                for(auto& elem : _vecBlocks){
                    if(elem->getNumber() == i){
                        if(_isTimerOn){
                            TimerForAnimation(25);
                        }
                        elem->changeColor(Qt::red);
                        elem->setPrimeStatus(false);
                    }

                }
                isPrime[i] = false;
            }
        }
    }

    for(auto& elem : _vecBlocks){
        if(elem->getPrimeStatus()){
            if(_isTimerOn){
                TimerForAnimation(50);
            }
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

void CustomBoard::changePosUp()
{
    qreal newY = this->pos().y() - 40;
    qreal maxY = this->rect().height();

    if (newY > maxY){
        newY = maxY;
    }

    this->setPos(0, newY);
}

void CustomBoard::changePosReturn()
{
    this->setPos(0, 0);
}

void CustomBoard::changeIsTimerOn()
{
    _isTimerOn = !_isTimerOn;
}
