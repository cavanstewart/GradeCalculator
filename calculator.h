
#ifndef CALCULATOR
#define CALCULATOR


#include <QWidget>
#include <QObject>
#include <QMainWindow>
namespace Ui{
class Calculator;
}

class Calculator : public QMainWindow{
    Q_OBJECT;
public:
	//constructor
    explicit Calculator(QWidget* parent);
    virtual ~Calculator();
private slots:
    void compute_hw(int grade);
    void compute_midterms(int grade);
    void compute_final(int grader);
	void compare_grade_schemes();

	friend void compute_overall_score(const string& grades, const string& log);
signals:
    void valueChanged(int newGrade);
	
private:
    double hw_percent;
    double midterm_percent_A;
    double midterm_percent_B;
    double final_percent_A;
    double final_percent_B;
    double grade_A;
    double grade_B;
    double final_grade;
    int hwGrade;
};
 

#endif
