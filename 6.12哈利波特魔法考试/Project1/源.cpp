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

// ���������ַ����ĺ�������
// ���������ַ����ĺ�������
int hammingDistance(const vector<char>& str1, const vector<char>& str2) {
    int distance = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            distance++;
        }
    }
    return distance;
}


// ����ѧ���ķ���
int calculateScore(const Student& student, const vector<Question>& questions) {
    int score = 0;
    for (size_t i = 0; i < student.answers.size(); ++i) {
        if (student.answers[i] == questions[i].correctAnswer) {
            score += questions[i].weight;
        }
    }
    return score;
}

// �ҵ�ѧ����������ѧ���������������Ǹ�ѧ��
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
    // �������ݣ���Ŀ����ȷ�𰸺�Ȩ�أ�
    cout << "�����:22������ϲ��" << endl;
    vector<Question> questions = {
        {'A', 2},
        {'B', 3},
        {'C', 1},
        // ... ������Ӹ�����Ŀ
    };

    // ����ѧ���Ĵ�
    vector<Student> students = {
        {{'A', 'B', 'C'}},
        {{'A', 'B', 'D'}},
        {{'C', 'B', 'A'}},
        // ... ������Ӹ���ѧ��
    };

    // ����ÿ��ѧ���ķ���
    for (size_t i = 0; i < students.size(); ++i) {
        int score = calculateScore(students[i], questions);
        cout << "ѧ�� " << i + 1 << " �ķ���: " << score << endl;
    }

    // �ҵ�������������ѧ��
    int maxDistanceStudent = findMaxHammingDistanceStudent(students);
    cout << "������ѧ��������������ѧ����ѧ�� " << maxDistanceStudent + 1 << endl;

    return 0;
}
