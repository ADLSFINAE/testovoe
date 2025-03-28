#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    scene = new CustomScene(nullptr);
    view = new CustomView(scene, nullptr);
    view->show();

    visualController = new TreeVisualController(nullptr);
    scene->addItem(visualController);

    TreeAlgorithm* algo = new TreeAlgorithm();

    QVector<int> vec = shitParser({1, 2, 3, 3, 4, NULL, NULL, 5,6,7,8,NULL,5,8,9});

    visualController->setVecNums(algo->validateAndTrimTreeVector(vec));
    for(auto& elem : algo->validateAndTrimTreeVector({1, 2, NULL, 3, 4, 5, 6})){
        qDebug()<<elem;
    }

    visualController->buildTree();
    /*TreeAlgorithm* algo = new TreeAlgorithm();
#define null NULL
    QVector<int> vec = {5,1,null,1,1,null,5,13,84,15,null,null,null,null,null,5};

    TreeNode* root = algo->buildTree(vec);

    QVector<QVector<int>> maxDepthPaths = algo->findMaxDepthPaths(root);


    for (const auto& path : maxDepthPaths) {
        for (int val : path) {
            qDebug() << val << " ";
        }
        qDebug() << "\n";
    }*/
}

unsigned int GeneralAdapter::findMinK(unsigned int N)
{
    if (N == 0) return 0;  // 2^0 = 1 >= 0
    if (N == 1) return 0;  // 2^0 = 1 >= 1

    unsigned int k = 0;
    unsigned int power = 1;  // 2^0 = 1

    while (power < N) {
        power <<= 1;  // Multiply by 2
        k++;
    }

    return k;
}

QVector<int> GeneralAdapter::getVec(const QVector<QPair<int, int>>& vec)
{
    QVector<int> temp;
    temp.reserve(vec.size() * 2);

    for (const auto& pair : vec) {
        temp.append(pair.first);
        temp.append(pair.second);
    }

    return temp;
}

QVector<int> GeneralAdapter::shitParser(QVector<int> vec)
{
    int k = findMinK(vec.size());
    qDebug() << k;

    int limit = 1;
    for (int i = 1; i <= k; i++) {
        limit += pow(2, i);
    }

    while (vec.size() != limit) {
        vec.append(0);
    }

    qDebug() << vec;

    if (vec[0] == 0) {
        vec.clear();
        return vec;
    }

    QVector<QVector<QPair<int, int>>> vec2(k + 1);
    vec2[0].resize(1);

    for (int i = 1; i <= k; i++) {
        vec2[i].resize(pow(2, i) / 2);
    }

    vec2[0][0] = qMakePair(vec[0], vec[0]);
    int iter = 1;

    for (int i = 1; i < vec2.size(); i++) {
        for (int j = 0; j < vec2[i].size(); j++) {
            vec2[i][j].first = vec[iter++];
            vec2[i][j].second = vec[iter++];
            qDebug() << vec2[i][j].first << vec2[i][j].second << "|";
        }
        qDebug() << i << "\n";
    }

    for (int i = 0; i < k; i++) {
        auto currentVec = getVec(vec2[i]);
        for (int j = 0; j < currentVec.size(); j++) {
            if (currentVec[j] == 0) {
                vec2[i + 1][j].first = -1;
                vec2[i + 1][j].second = -1;
            }
        }
    }

    for (const auto& subvec : vec2) {
        for (const auto& pair : subvec) {
            qDebug() << pair.first << pair.second << "|";
        }
        qDebug();
    }

    for (int i = 0; i < k; i++) {
        if (i == 0) {
            if (vec2[1][0].first == 0) {
                vec2[1][0].first = -1;
            }
            if (vec2[1][0].second == 0) {
                vec2[1][0].second = -1;
            }
        }

        for (int j = 0; j < vec2[i].size(); j++) {
            if (vec2[i][j].first == 0) {
                vec2[i + 1][j + 1].first = -1;
                vec2[i + 1][j + 1].second = -1;
            }
            if (vec2[i][j].second == 0) {
                vec2[i + 1][j + 1].first = -1;
                vec2[i + 1][j + 1].second = -1;
            }
        }
    }

    for (auto& elem : vec2[k]) {
        if (elem.first == 0) elem.first = -1;
        if (elem.second == 0) elem.second = -1;
    }

    QVector<int> ans = {vec[0]};
    for (int i = 1; i <= k; i++) {
        auto currentVec = getVec(vec2[i]);
        for (auto& elem : currentVec) {
            if (elem == 0) elem = -1;
            ans.append(elem);
        }
    }

    qDebug() << ans;
    return ans;
}
