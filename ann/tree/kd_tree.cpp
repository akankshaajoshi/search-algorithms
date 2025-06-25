#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "./../../utils/my_limits.hpp"

using namespace std;

using Point = vector<double>;

struct KDNode
{
    Point point;
    unique_ptr<KDNode> left, right;

    KDNode(Point pt) : point(move(pt)) {}
};

class KDTree
{
    unique_ptr<KDNode> root;
    // define k unique dimensions for any point in space
    int k;

public:
    KDTree(int dimensions) : k(dimensions), root(nullptr) {}

    void insert(const Point &point)
    {
        if (point.size() != k)
        {
            throw invalid_argument("Point dimensions do not match!");
        }
        root = insertRec(move(root), point, 0);
    }

    Point nearest(const Point &target)
    {
        if (target.size() != k)
        {
            throw invalid_argument("Point dimensions do not match!");
        }
        KDNode *best = nullptr;
        double best_dist = custom::my_limits<double>::max();
        nearestRec(root.get(), target, 0, best, best_dist);
        return best ? best->point : Point();
    }

private:
    unique_ptr<KDNode> insertRec(unique_ptr<KDNode> node, const Point &pt, int depth)
    {
        if (!node)
            return make_unique<KDNode>(pt);

        int axis = depth % k;

        if (pt[axis] < node->point[axis])
        {
            node->left = insertRec(move(node->left), pt, depth + 1);
        }
        else
        {
            node->right = insertRec(move(node->right), pt, depth + 1);
        }

        return node;
    }

    void nearestRec(KDNode *node, const Point &target, int depth, KDNode *&best, double &best_dist)
    {
        if (!node)
            return;

        double d = euclideanDist(node->point, target);

        if (d < best_dist)
        {
            best_dist = d;
            best = node;
        }

        int axis = depth % k;
        KDNode *near = (target[axis] < node->point[axis]) ? node->left.get() : node->right.get();
        KDNode *far = (target[axis] < node->point[axis]) ? node->right.get() : node->left.get();

        nearestRec(near, target, depth + 1, best, best_dist);

        if (abs(node->point[axis] - target[axis]) < best_dist)
        {
            nearestRec(far, target, depth + 1, best, best_dist);
        }
    }

    double euclideanDist(const Point &a, const Point &b)
    {
        double sum = 0.0;
        for (int i = 0; i < k; ++i)
        {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return sqrt(sum);
    }
};

int main()
{
    KDTree tree(3);

    vector<Point> pts = {
        {2.0, 3.0, 4.5},
        {5.0, 4.0, 2.1},
        {9.0, 6.0, 7.0},
        {4.0, 7.0, 9.0},
        {8.0, 1.0, 5.5}};

    for (auto &p : pts)
        tree.insert(p);

    Point query = {6.0, 2.0, 5.0};
    Point nearest = tree.nearest(query);

    cout << "Nearest to (" << query[0] << ", " << query[1] << ", " << query[2] << ") is:\n";
    cout << "(";
    for (int i = 0; i < nearest.size(); ++i)
        cout << nearest[i] << (i + 1 < nearest.size() ? ", " : "");
    cout << ")" << endl;

    return 0;
}
