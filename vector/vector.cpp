#include <iostream>
#include <vector>


class Student
{
public:
    int mNumber;
    std::string mName;
    int mScore;

    void Print() const
    {
        std::cout << "(" << mNumber << ")" << mName << " : " << mScore << std::endl;
    }
};

using Students = std::vector<Student>;

void AddStudent(Students& v)
{
    std::cout << "번호 이름 점수 : ";

    Student newStudent;
    if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
    {
        for (const auto& e : v)
        {
            if (e.mNumber == newStudent.mNumber)
            {
                std::cout << "중복된 번호입니다" << std::endl;
                return;
            }
        }
        v.push_back(newStudent);
    }
    else
    {
        std::cout << "잘못된입력입니다" << std::endl;
    }
}

void RemoveStudent(Students& v)
{
    std::cout << "삭제할 번호 : ";
    int num;
    if (std::cin >> num)
    {
        for (auto itr = v.begin(); itr != v.end(); ++itr)
        {
            if (itr->mNumber == num)
            {
                v.erase(itr);
                return;
            }
        }
    }
    else
    {
        std::cout << "잘못된 입력입니다 " << std::endl;
    }

}

void PrintStudent(const Students& v)
{
    for (const auto& e : v)
    {
        e.Print();
    }
}

void PrintScoreInfo(const Students& v)
{
    int total{};
    for (const auto& e : v)
    {
        total += e.mScore;
    }

    std::cout << "Tota : " << total
        << ", Average : " << static_cast<float>(total) / v.size()
        << std::endl;
}

void PrintOverScore(const Students& v)
{
    float average{};
    for (const auto& e : v)
    {
        average += e.mScore;
    }
    average /= v.size();

    for (const auto& e : v)
    {
        if (e.mScore >= average)
        {
            e.Print();
        }
    }
}

int main()
{
    std::vector<Student> students{
        {1,"kim",80},
        {2,"lee",20},
        {3,"park",50},
        {4,"choi",30}
    };

    int command{};

    while (command != 6)
    {
        std::cout << "1.학생추가" << std::endl;
        std::cout << "2.학생제거" << std::endl;
        std::cout << "3.전체학생출력" << std::endl;
        std::cout << "4.클래스 평균 및 총점" << std::endl;
        std::cout << "5.클래스 평균이상 학생 목록" << std::endl;
        std::cout << "6.종료" << std::endl;

        std::cout << " > ";
        std::cin >> command;
        switch (command)
        {
        case 1:
            AddStudent(students);

            break;
        case 2:
            RemoveStudent(students);
            break;
        case 3:
            PrintStudent(students);
            break;
        case 4:
            PrintScoreInfo(students);
            break;
        case 5:
            PrintOverScore(students);
            break;
        case 6:
            break;
        default:
            std::cout << "잘못된 명령어입니다." << std::endl;
            break;
        }
    }

}