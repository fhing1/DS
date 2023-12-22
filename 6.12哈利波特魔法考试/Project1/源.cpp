#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Question {
    char correctAnswer;
    int weight;
};

struct Student {
    vector<char> answers;
};

// 计算两个字符串的汉明距离
// 计算两个字符串的汉明距离
int hammingDistance(const vector<char>& str1, const vector<char>& str2) {
    int distance = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            distance++;
        }
    }
    return distance;
}


// 计算学生的分数
int calculateScore(const Student& student, const vector<Question>& questions) {
    int score = 0;
    for (size_t i = 0; i < student.answers.size(); ++i) {
        if (student.answers[i] == questions[i].correctAnswer) {
            score += questions[i].weight;
        }
    }
    return score;
}

// 找到学生中与其他学生汉明距离最大的那个学生
int findMaxHammingDistanceStudent(const vector<Student>& students) {
    int maxDistance = -1;
    int maxDistanceStudent = -1;

    for (size_t i = 0; i < students.size(); ++i) {
        int totalDistance = 0;
        for (size_t j = 0; j < students.size(); ++j) {
            if (i != j) {
                totalDistance += hammingDistance(students[i].answers, students[j].answers);
            }
        }

        if (totalDistance > maxDistance) {
            maxDistance = totalDistance;
            maxDistanceStudent = i;
        }
    }

    return maxDistanceStudent;
}

int main() {
    // 设置数据（题目的正确答案和权重）
    cout << "完成人:22网工方喜健" << endl;
    vector<Question> questions = {
        {'A', 2},
        {'B', 3},
        {'C', 1},
        // ... 可以添加更多题目
    };

    // 设置学生的答案
    vector<Student> students = {
        {{'A', 'B', 'C'}},
        {{'A', 'B', 'D'}},
        {{'C', 'B', 'A'}},
        // ... 可以添加更多学生
    };

    // 计算每个学生的分数
    for (size_t i = 0; i < students.size(); ++i) {
        int score = calculateScore(students[i], questions);
        cout << "学生 " << i + 1 << " 的分数: " << score << endl;
    }

    // 找到汉明距离最大的学生
    int maxDistanceStudent = findMaxHammingDistanceStudent(students);
    cout << "与其他学生汉明距离最大的学生是学生 " << maxDistanceStudent + 1 << endl;

    return 0;
}
