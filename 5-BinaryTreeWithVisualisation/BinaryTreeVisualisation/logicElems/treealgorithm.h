#ifndef TREEALGORITHM_H
#define TREEALGORITHM_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QQueue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeAlgorithm : public QObject
{
    Q_OBJECT
public:
    // Функция для валидации и обрезки вектора
    QVector<int> validateAndTrimTreeVector(const QVector<int>& input) {
        if (input.isEmpty() || input[0] == NULL) return QVector<int>();

        QVector<int> result;
        QQueue<int> indexQueue;
        indexQueue.enqueue(0);
        result.append(input[0]);

        int i = 1;
        while (!indexQueue.isEmpty() && i < input.size()) {
            int parentIndex = indexQueue.dequeue();

            // Добавляем левого потомка (если есть)
            if (i < input.size()) {
                result.append(input[i]);
                if (input[i] != NULL) {
                    indexQueue.enqueue(i);
                }
                i++;
            }
            else {
                result.append(NULL); // Заполняем NULL если вышли за границы
            }

            // Добавляем правого потомка (если есть)
            if (i < input.size()) {
                result.append(input[i]);
                if (input[i] != NULL) {
                    indexQueue.enqueue(i);
                }
                i++;
            }
            else {
                result.append(NULL); // Заполняем NULL если вышли за границы
            }
        }

        // Удаляем все NULL в конце (если они есть)
        while (!result.isEmpty() && result.last() == NULL) {
            result.removeLast();
        }

        return result;
    }

    // Функция для построения дерева из QVector
    TreeNode* buildTree(const QVector<int>& vec) {
        QVector<int> trimmedVec = validateAndTrimTreeVector(vec);
        if (trimmedVec.isEmpty() || trimmedVec[0] == NULL) return nullptr;

        QQueue<TreeNode*> q;
        TreeNode* root = new TreeNode(trimmedVec[0]);
        q.enqueue(root);

        int i = 1;
        while (!q.isEmpty() && i < trimmedVec.size()) {
            TreeNode* node = q.dequeue();

            if (i < trimmedVec.size() && trimmedVec[i] != NULL) {
                node->left = new TreeNode(trimmedVec[i]);
                q.enqueue(node->left);
            }
            i++;

            if (i < trimmedVec.size() && trimmedVec[i] != NULL) {
                node->right = new TreeNode(trimmedVec[i]);
                q.enqueue(node->right);
            }
            i++;
        }

        return root;
    }

    // Основная функция для поиска путей максимальной глубины
    QVector<QVector<int>> findMaxDepthPaths(TreeNode* root) {
        QVector<QVector<int>> result;
        if (!root) return result;

        QVector<int> currentPath;
        int maxDepth = 0;

        dfs(root, currentPath, result, maxDepth);

        return result;
    }

private:
    // Вспомогательная функция для обхода дерева в глубину
    void dfs(TreeNode* node, QVector<int>& currentPath,
             QVector<QVector<int>>& result, int& maxDepth) {
        if (!node) return;

        currentPath.append(node->val);

        // Если это лист
        if (!node->left && !node->right) {
            int currentDepth = currentPath.size();

            if (currentDepth > maxDepth) {
                maxDepth = currentDepth;
                result.clear();
                result.append(currentPath);
            }
            else if (currentDepth == maxDepth) {
                result.append(currentPath);
            }
        }
        else {
            dfs(node->left, currentPath, result, maxDepth);
            dfs(node->right, currentPath, result, maxDepth);
        }

        currentPath.removeLast(); // backtracking
    }
};

#endif // TREEALGORITHM_H
