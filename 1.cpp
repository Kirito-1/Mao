#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
public:
    int _number;
    string _name, _class;
    double math, english, cs;
    Student(int tmp_num, string tmp_name, string tmp_class, double math, double english, double cs){
        this->_number = tmp_num;
        this->_name = tmp_name;
        this->_class = tmp_class;
        this->math = math;
        this->english = english;
        this->cs = cs;
    }
};

vector<Student*> v;

void insert(){
    int tmp_num;
    string tmp_name, tmp_class;
    double math, english, cs;
    cout << "输入学生的学号：" << endl;
    cin >> tmp_num;
    cout << "输入学生的姓名：" << endl;
    cin >> tmp_name;
    cout << "输入学生的班级：" << endl;
    cin >> tmp_class;
    cout << "输入学生的数学成绩：" << endl;
    cin >> math;
    cout << "输入学生的外语成绩：" << endl;
    cin >> english;
    cout << "输入学生的计算机成绩：" << endl;
    cin >> cs;
    Student* s = new Student(tmp_num, tmp_name, tmp_class, math, english, cs);
    v.push_back(s);
    cout << "录入学生信息成功" << endl;
}

void display(){
    for(int i=0; i<v.size(); ++i){
        Student* it = v[i];
        cout << " 学号：" << it->_number << " 姓名：" << it->_name << " 班级：" << it->_class;
        cout << " 数学成绩：" << it->math << " 外语成绩：" << it->english << " 计算机成绩：" << it->cs << endl;
    }
}

void query(){
    int tmp, flag = 0;
    cout << "输入要查询的学生的学号：" << endl;
    cin >> tmp;
    for(int i=0; i<v.size(); ++i){
        Student* it = v[i];
        if(it->_number == tmp){
            cout << " 学号：" << it->_number << " 姓名：" << it->_name << " 班级：" << it->_class;
            cout << " 数学成绩：" << it->math << " 外语成绩：" << it->english << " 计算机成绩：" << it->cs << endl;
            flag = 1;
        }
    }
    if(!flag){
        cout << "该学生不存在" << endl;
    }
}

void modify(){
    int tmp, flag = 0;
    cout << "输入要修改的学生的学号：" << endl;
    cin >> tmp;
    for(int i=0; i<v.size(); ++i){
        Student* it = v[i];
        if(it->_number == tmp){
            cout << "输入学生的姓名：" << endl;
            cin >> it->_name;
            cout << "输入学生的班级：" << endl;
            cin >> it->_class;
            cout << "输入学生的数学成绩：" << endl;
            cin >> it->math;
            cout << "输入学生的外语成绩：" << endl;
            cin >> it->english;
            cout << "输入学生的计算机成绩：" << endl;
            cin >> it->cs;
            flag = 1;
        }
    }
    if(!flag){
        cout << "该学生不存在" << endl;
    }
}

void add(){
    insert();
}

bool _sortByNum(Student* s1, Student* s2){
    return s1->_number < s2->_number;
}
bool _sortByTotalGrade(Student* s1, Student* s2){
    return s1->math + s1->english + s1->cs > s2->math + s2->english + s2->cs;
}
bool _sortByMath(Student* s1, Student* s2){
    return s1->math > s2->math;
}
bool _sortByForeign(Student* s1, Student* s2){
    return s1->english > s2->english;
}
bool _sortByCS(Student* s1, Student* s2){
    return s1->cs > s2->cs;
}
void _sort(){
    cout << "1 按照学号排序" << endl;
    cout << "2 按照总成绩/平均成绩排序" << endl;
    cout << "3 按照数学成绩排序" << endl;
    cout << "4 按照外语成绩排序" << endl;
    cout << "5 按照计算机成绩排序" << endl;
    cout << "你要输入的编号是（1-5）：" << endl;
    int choice = -1;
    cin >> choice;
    if(choice==1){
        sort(v.begin(), v.end(), _sortByNum);
    } else if(choice==2){
        sort(v.begin(), v.end(), _sortByTotalGrade);
    } else if(choice==3){
        sort(v.begin(), v.end(),_sortByMath);
    } else if(choice==4){
        sort(v.begin(), v.end(),_sortByForeign);
    } else if(choice==5){
        sort(v.begin(), v.end(),_sortByCS);
    } else{
        cout << "输入错误，请输入编号1-5" << endl;
    }
}

void del(){
    int tmp, flag = 0;
    cout << "输入要删除的学生的学号：" << endl;
    cin >> tmp;
    for(vector<Student*>::iterator it=v.begin(); it!=v.end(); ++it){
        if((*it)->_number == tmp){
            it = v.erase(it);
            if(it == v.end()) break;
            flag = 1;
        }
    }
    if(!flag){
        cout << "该学生不存在" << endl;
    }
}

int main() {
    while(1){
        cout << "******************欢迎使用******************" << endl;
        cout << "**************学生成绩管理系统**************" << endl;
        cout << "*----------------------------------------*" << endl;
        cout << "*            1--录入学生信息               *" << endl;
        cout << "*            2--显示学生信息               *" << endl;
        cout << "*            3--查询学生信息               *" << endl;
        cout << "*            4--修改学生信息               *" << endl;
        cout << "*            5--添加学生信息               *" << endl;
        cout << "*            6--排序学生信息               *" << endl;
        cout << "*            7--删除学生信息               *" << endl;
        cout << "*            0--退出                      *" << endl;
        cout << "*----------------------------------------*" << endl;
        cout << "你要输入的编号是（0-7）：" << endl;
        int choice = -1;
        cin >> choice;
        if(choice==1){
            insert();
        } else if(choice==2){
            display();
        } else if(choice==3){
            query();
        } else if(choice==4){
            modify();
        } else if(choice==5){
            add();
        } else if(choice==6){
            _sort();
        } else if(choice==7){
            del();
        } else if(choice==0){
            break;
        } else{
            cout << "输入错误，请输入编号0-7" << endl;
        }
    }
    return 0;
}