/*
#include "calculator.h"

//default constructor
GradeCalc::GradeCalc(){
	hw_percent = 0.0;
	midterm_percent_A = 0.0;
	midterm_percent_B = 0.0;
	final_percent_A = 0.0;
	final_percent_B = 0.0;
	grade_A = 0.0;
	grade_B = 0.0;
	final_grade = 0.0;
}

void GradeCalc::compute_hw(int grade){
	const double MAX_SCORE = 20.0;
	const double HW_PERCENT = 25.0;
	const int HW_NUM = 7;
	double min = MAX_SCORE;
	double score, total = 0.0;
    score = 20;
	for (int i = 0; i< 8; i++){

		total += score;
		if (score < min)
			min = score;
	}

	this->hw_percent = ((total - min) * HW_PERCENT) / (HW_NUM * MAX_SCORE);
}


void GradeCalc::compute_midterms(ifstream& fin){
	const double MAX_SCORE = 100.0;
	const double MID_PERCENT_A = 40.0;
	const double MID_PERCENT_B = 30.0;
	const int MID_NUM = 2;
	double total, best = 0.0;
	double scores[2];
	fin >> scores[0] >> scores[1];
	total = scores[0] + scores[1];
	best = ((scores[0]>scores[1]) ? scores[0] : scores[1]);
	this-> midterm_percent_A = (total * MID_PERCENT_A) / (MID_NUM * MAX_SCORE);
	this->midterm_percent_B = (best * MID_PERCENT_B) / MAX_SCORE;
}

/*takes a file input stream as a parameter
changes the private variable to final percentage for scheme A
changes another private variable to final percentage for scheme B
*/
void GradeCalc::compute_final(ifstream& fin){
	const double MAX_SCORE = 100.0;
	const double FINAL_PERCENT_A = 35.0;
	const double FINAL_PERCENT_B = 44.0;
	double score = 0.0;
	fin >> score;
	this->final_percent_A = (score * FINAL_PERCENT_A) / MAX_SCORE;
	this->final_percent_B = (score * FINAL_PERCENT_B) / MAX_SCORE;
}

/*adds the component percentages for each scheme
changes a private variable to the higher scheme
*/
void GradeCalc::compare_grade_schemes(){
	grade_A = hw_percent + midterm_percent_A + final_percent_A;
	grade_B = hw_percent + midterm_percent_B + final_percent_B;
	this->final_grade = ((grade_A > grade_B) ? grade_A : grade_B);
}

/*takes two strings as parameters
reads the file provided by the first string and prints the final grades 
to the second file provides by the second string

Note: uses other functions for computations and comparisons
*/
/*
void compute_overall_score(const string& grades, const string& log){
	grade_calculator calculator;
	ifstream fin(grades);

	calculator.compute_hw(fin);
	calculator.compute_midterms(fin);
	calculator.compute_final(fin);

	fin.close();

	calculator.compare_grade_schemes();


	ofstream fout(log);
	fout << "Score A : " << calculator.grade_A << "%\nScore B : " << calculator.grade_B
		<< "%\nOverall Score : " << std::setprecision(4) << calculator.final_grade << "%";
	fout.close();
}
*/

