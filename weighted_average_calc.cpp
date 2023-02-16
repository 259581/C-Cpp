/* The purpose of this program is to calculate weighted average */

#include <iostream>
using namespace std;

class Values{
    public:
    float average = 0.0;
    int sumOfImportance = 0;
    float productOfMultiplication = 0.0;
    int *grade;
    int *importance;

    Values(int amount) {
        grade = new int(amount);
        importance = new int(amount);
    }


};

float counting(int amount, Values object){
    int x = 0;
    for (int i = 0; i<amount; i++){
        object.sumOfImportance += object.importance[i];
    }

    for (int i = 0; i<amount; i++){
        x = object.importance[i]*object.grade[i];
        object.productOfMultiplication += x;
    }
    object.average = object.productOfMultiplication/object.sumOfImportance;

    return object.average;
}

int main(){
    int courses_amount = 0;
    cout<<"How many courses you had?"<<endl;
    cin>>courses_amount;

    if(cin.fail()){
        cout<<"You passed wrong type, it supposed to be integer"<<endl;
        exit(2);
    }

    //creating an object
    Values course(courses_amount);

    for(int i=0; i<courses_amount; i++){
        float grade = 0;
        cout<<"Grade:";
        cin>>course.grade[i];
        if(grade>5.5){
            cout<<"You passed wrong value (grade can not be higher than 5.5)"<<endl;
            exit(1);
        }
        cout<<endl;
        cout<<"Weight:";
        cin>>course.importance[i];
        cout<<endl;
    }

    cout<<"This is your weighted average: "<<counting(courses_amount, course)<<endl;

    return 0;

}