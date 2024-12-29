#include <iostream>
#include <string>
using namespace std;

struct Course {
    int courseId;
    string courseName;
    Course* left;
    Course* right;
    Course(int id, string name) : courseId(id), courseName(name), left(nullptr), right(nullptr) {}
};

Course* insert(Course* root, int courseId, string courseName) {
    if (!root) return new Course(courseId, courseName);
    if (courseId < root->courseId) {
        root->left = insert(root->left, courseId, courseName);
    } else {
        root->right = insert(root->right, courseId, courseName);
    }
    return root;
}

void inorder(Course* root) {
    if (root) {
        inorder(root->left);
        cout << "Course ID: " << root->courseId << ", Course Name: " << root->courseName << endl;
        inorder(root->right);
    }
}

int main() {
    Course* root = nullptr;
    root = insert(root, 30, "Data Structures");
    insert(root, 20, "Algorithms");
    insert(root, 40, "Operating Systems");
    insert(root, 10, "Discrete Mathematics");
    insert(root, 25, "Computer Networks");

    cout << "Inorder traversal of the course schedule: " << endl;
    inorder(root);
    cout << endl;

    return 0;
}
