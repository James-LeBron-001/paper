//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <gsl/gsl_sf_bessel.h>
//#include <gsl/gsl_randist.h>
//#include <gsl/gsl_rng.h>
//#include <ctime>
//#include <cmath>
//#include <fstream>
//#include <sstream>
//using namespace std;
//
//gsl_rng* R_GLOBAL;
//
////����
//void read_file(string path, double m[18][18]);//���ļ�
//void init_matrix_population();//��ʼ���˿ںͽӴ�����
//void air_move();//����Ǩ��
//void select_E1_A(int flag, int age_group, int num);//��ѡA��E1̬,flag:0��ʾ����,1��ʾ����
//void select_E1_B(int flag, int age_group, int num);//��ѡB��E1̬,flag:0��ʾ����,1��ʾ����
//void select_E2_A(int flag, int age_group, int num);//��ѡA��E2̬,flag:0��ʾ����,1��ʾ����
//void select_E2_B(int flag, int age_group, int num);//��ѡB��E2̬,flag:0��ʾ����,1��ʾ����
//void select_Ia_A(int flag, int age_group, int num);//��ѡA��Ia̬,flag:0��ʾ����,1��ʾ����
//void select_Ia_B(int flag, int age_group, int num);//��ѡB��Ia̬,flag:0��ʾ����,1��ʾ����
//void transition_A();//����·˹���������в�����
//void transition_B();//¬ɭ�����������в�����
//void getnum();//��ø�Ⱦ����
//
////����
//double A_matrix[18][18];//�Ӵ�����
//double B_matrix[18][18];//
//double A_S[18] = { 0 };//�������Ҹ�״̬��Ⱥ
//double A_E1[18][70000] = { 0 };//���69999��¼������������Ϊ����
//double A_E2[18][70000] = { 0 };//���69999��¼������������Ϊ����
//double A_flag[18][70000] = { 0 };//Ϊ1��ʾ�����E2̬��Ϊ0��ʾ�������,-1��ʾû��������
//double A_Ia[18][70000] = { 0 };
//double A_I[18][70000] = { 0 };
//double A_R[18] = { 0 };
//double B_S[18] = { 0 };
//double B_E1[18][70000] = { 0 };//���69999��¼������������Ϊ���߱�ź�Ǳ������
//double B_E2[18][70000] = { 0 };//���69999��¼������������Ϊ���߱�ź�Ǳ������
//double B_flag[18][70000] = { 0 };//Ϊ1��ʾ�����E2̬��Ϊ0��ʾ�������,-1��ʾû��������
//double B_Ia[18][70000] = { 0 };
//double B_I[18][70000] = { 0 };
//double B_R[18] = { 0 };
//int age_distribution_B[18] = { 0 };//���������˿�
//int age_distribution_A[18] = { 0 }; 
//int day = 1;//ʱ�䲽------ÿһ��
//vector<int> A_out_id;//A����ȥ���˱��
//vector<int> A_out_day;//A����ȥ����Ǳ��ʣ������
//vector<int> B_out_id;//B����ȥ���˱��
//vector<int> B_out_day;//B����ȥ����Ǳ��ʣ������
////����
//double TS = 0;//���������̶ȣ��������ƣ�
//double beta_B = 0;//������
//double beta_A = 0;//������
//double gammaa = 0.2;//�ָ���
//double Probability_asy = 0;//��֢״��(�����䷢���仯) 
//double gamma_Ia = 0.5;//��֢״̬����׸���
//double gamma_E2 = 1;//֢ǰ��������׸���
//double Exposed_period = 3;//ƽ��Ǳ��ʱ��
//double Psy_period = 2;//ƽ��Ǳ��ʱ��
//
//double sum_I_A = 0;
//double sum_I_B = 0;
//double newcase_A = 0;
//double newcase_B = 0;
//double sum_A[30][365] = {0};//A���ܸ�Ⱦ����
//double sum_B[30][365] = {0};//B���ܸ�Ⱦ����
//double sum_all[30][365] = { 0 };//�ܸ�Ⱦ����
//double A_sum_S[30][365] = { 0 };
//double A_sum_E1[30][365] = { 0 };
//double A_sum_E2[30][365] = { 0 };
//double A_sum_Ia[30][365] = { 0 };
//double A_sum_I[30][365] = { 0 };
//double A_sum_R[30][365] = { 0 };
//double B_sum_S[30][365] = { 0 };
//double B_sum_E1[30][365] = { 0 };
//double B_sum_E2[30][365] = { 0 };
//double B_sum_Ia[30][365] = { 0 };
//double B_sum_I[30][365] = { 0 };
//double B_sum_R[30][365] = { 0 };
//double new_A[30][365] = { 0 };//Aÿ����������
//double new_B[30][365] = { 0 };//Bÿ���� ������
//int epoch = 0;//�ִ�
//
//int main()
//{
//	init_matrix_population();//��ʼ�� 
//	R_GLOBAL = gsl_rng_alloc(gsl_rng_taus);
//	for (int i = 1; i <=30; i++)
//	{
//		gsl_rng_set(R_GLOBAL, time(NULL)+i);
//		getnum();
//		cout << "step:" << i << endl;
//		cout << sum_I_A << "   " << sum_I_B << endl;
//	}
//	gsl_rng_free(R_GLOBAL);
//	ofstream outFile0, outFile1, outFile2, outFile3, outFile4, outFile5, outFile6, outFile7, outFile8,outFile9, outFile10, outFile11, outFile12, outFile13, outFile14, outFile15, outFile16; // ����������
//	outFile0.open("res/sum_A.csv", ios::app); // ���ļ�
//	outFile1.open("res/sum_B.csv", ios::app); // ���ļ�
//	outFile2.open("res/sum_all.csv", ios::app); // ���ļ�
//	outFile3.open("res/A_S.csv", ios::app); // ���ļ�
//	outFile4.open("res/A_E1.csv", ios::app); // ���ļ�
//	outFile5.open("res/A_E2.csv", ios::app); // ���ļ�
//	outFile6.open("res/A_I.csv", ios::app); // ���ļ�
//	outFile7.open("res/A_Ia.csv", ios::app); // ���ļ�
//	outFile8.open("res/A_R.csv", ios::app); // ���ļ�
//	outFile9.open("res/B_S.csv", ios::app); // ���ļ�
//	outFile10.open("res/B_E1.csv", ios::app); // ���ļ�
//	outFile11.open("res/B_E2.csv", ios::app); // ���ļ�
//	outFile12.open("res/B_I.csv", ios::app); // ���ļ�
//	outFile13.open("res/B_Ia.csv", ios::app); // ���ļ�
//	outFile14.open("res/B_R.csv", ios::app); // ���ļ�
//	outFile15.open("res/new_A.csv", ios::app); // ���ļ�
//	outFile16.open("res/new_B.csv", ios::app); // ���ļ�
//	for (int e = 0; e < 30; e++)
//	{
//		for (int i = 0; i < 365; i++)
//		{
//			outFile0 << sum_A[e][i] << ",";
//			outFile1 << sum_B[e][i] << ",";
//			outFile2 << sum_all[e][i] << ",";
//			outFile3 << A_sum_S[e][i] << ",";
//			outFile4 << A_sum_E1[e][i] << ",";
//			outFile5 << A_sum_E2[e][i] << ",";
//			outFile6 << A_sum_I[e][i] << ",";
//			outFile7 << A_sum_Ia[e][i] << ",";
//			outFile8 << A_sum_R[e][i] << ",";
//			outFile9 << B_sum_S[e][i] << ",";
//			outFile10 << B_sum_E1[e][i] << ",";
//			outFile11 << B_sum_E2[e][i] << ",";
//			outFile12 << B_sum_I[e][i] << ",";
//			outFile13 << B_sum_Ia[e][i] << ",";
//			outFile14 << B_sum_R[e][i] << ",";
//			outFile15 <<new_A[e][i] << ",";
//			outFile16 << new_B[e][i] << ",";
//		}
//		outFile0 << endl;
//		outFile1 << endl;
//		outFile2 << endl;
//		outFile3 << endl;
//		outFile4 << endl;
//		outFile5 << endl;
//		outFile6 << endl;
//		outFile7 << endl;
//		outFile8 << endl;
//		outFile9 << endl;
//		outFile10 << endl;
//		outFile11 << endl;
//		outFile12 << endl;
//		outFile13 << endl;
//		outFile14 << endl;
//		outFile15 << endl;
//		outFile16 << endl;
//	}
//	outFile0.close(); // �ر��ļ�
//	outFile1.close(); // �ر��ļ�
//	outFile2.close(); // �ر��ļ�
//	outFile3.close(); // �ر��ļ�
//	outFile4.close(); // �ر��ļ�
//	outFile5.close(); // �ر��ļ�
//	outFile6.close(); // �ر��ļ�
//	outFile7.close(); // �ر��ļ�
//	outFile8.close(); // �ر��ļ�
//	outFile9.close(); // �ر��ļ�
//	outFile10.close(); // �ر��ļ�
//	outFile11.close(); // �ر��ļ�
//	outFile12.close(); // �ر��ļ�
//	outFile13.close(); // �ر��ļ�
//	outFile14.close(); // �ر��ļ�
//
//	return 0;
//}
//void getnum()
//{
//	day = 1;
//	sum_I_A = 0;
//	sum_I_B = 0;
//	//ȫΪS̬
//	for (int i = 0; i < 18; i++)
//	{
//		A_S[i] = age_distribution_A[i];
//		B_S[i] = age_distribution_B[i];
//		A_R[i] = 0;
//		B_R[i] = 0;
//		for (int j = 0; j < 70000; j++)
//		{
//			A_E1[i][j] = 0;
//			A_E2[i][j] = 0;
//			B_E1[i][j] = 0;
//			B_E2[i][j] = 0;
//			A_flag[i][j] = -1;
//			B_flag[i][j] = -1;
//			A_Ia[i][j] = 0;
//			A_I[i][j] = 0;
//			B_Ia[i][j] = 0;
//			B_I[i][j] = 0;
//		}
//	}
//	//������ʼʱÿ��������5��E1̬�ڵ�
//	A_E1[4][2000] = 5;
//	A_flag[4][2000] = 0;
//	A_E1[3][1000] = 4;
//	A_flag[3][1000] = 0;
//	A_E1[2][0] = 2;
//	A_flag[2][0] = 1;
//	A_E1[5][999] = 2;
//	A_flag[5][999] = 1;
//	A_E1[6][1] = 1;
//	A_flag[5][1] = 1;
//	A_S[4] -= 1;
//	A_S[3] -= 1;
//	A_S[2] -= 1;
//	A_S[5] -= 1;
//	A_S[6] -= 1;
//	B_E1[4][2000] = 4;
//	B_flag[4][2000] = 0;
//	B_E1[3][1000] = 5;
//	B_flag[3][1000] = 0;
//	B_E1[2][0] = 1;
//	B_flag[2][0] = 1;
//	B_E1[5][999] = 3;
//	B_flag[5][999] = 1;
//	B_E1[6][3] = 2;
//	B_flag[6][3] = 1;
//	B_S[4] -= 1;
//	B_S[3] -= 1;
//	B_S[2] -= 1;
//	B_S[5] -= 1;
//	B_S[6] -= 1;
//	A_E1[4][69999] = 1;
//	A_E1[3][69999] = 1;
//	A_E1[2][69999] = 1;
//	A_E1[5][69999] = 1;
//	A_E1[6][69999] = 1;
//	B_E1[4][69999] = 1;
//	B_E1[3][69999] = 1;
//	B_E1[2][69999] = 1;
//	B_E1[5][69999] = 1;
//	B_E1[6][69999] = 1;
//	while (day <= 365)
//	{
//		cout << epoch << "  day:" << day << endl;
//		newcase_A = 0;
//		newcase_B = 0;
//		air_move();//����Ǩ��
//		transition_A();
//		transition_B();
//		for (int i = 0; i < 18; i++)
//		{
//			A_sum_S[epoch][day - 1] += A_S[i];
//			A_sum_E1[epoch][day - 1] += A_E1[i][69999];
//			A_sum_E2[epoch][day - 1] += A_E2[i][69999];
//			A_sum_I[epoch][day - 1] += A_I[i][69999];
//			A_sum_Ia[epoch][day - 1] += A_Ia[i][69999];
//			A_sum_R[epoch][day - 1] += A_R[i];
//			B_sum_S[epoch][day - 1] += B_S[i];
//			B_sum_E1[epoch][day - 1] += B_E1[i][69999];
//			B_sum_E2[epoch][day - 1] += B_E2[i][69999];
//			B_sum_I[epoch][day - 1] += B_I[i][69999];
//			B_sum_Ia[epoch][day - 1] += B_Ia[i][69999];
//			B_sum_R[epoch][day - 1] += B_R[i];
//		}
//		new_A[epoch][day - 1] = newcase_A;
//		new_B[epoch][day - 1] = newcase_B;
//		sum_A[epoch][day - 1] = sum_I_A;
//		sum_B[epoch][day - 1] = sum_I_B;
//		sum_all[epoch][day - 1] = sum_I_A + sum_I_B;
//		day++;
//	}
//	epoch++;
//}
////���ļ�
//void read_file(string path, double m[18][18])
//{
//	//�Զ��뷽ʽ���ļ�
//	ifstream csv_data(path, ios::in);
//
//	if (!csv_data.is_open())
//	{
//		cout << "Error: opening file fail" << endl;
//		exit(1);
//	}
//	else {
//		string line;
//
//		vector<string> words; //����һ���ַ�������
//		string word;
//		// ------------��ȡ����-----------------
//
//		istringstream sin;
//		// ���ж�ȡ����
//		int i = 0, j = 0;//i��ʾ�У�j��ʾ��
//		while (getline(csv_data, line))
//		{
//			// ���vector���ַ�����,ֻ�浱ǰ�е�����
//			words.clear();
//			sin.clear();
//
//			sin.str(line);
//			//���ַ�����sin�е��ַ������ַ�������words�У��Զ���Ϊ�ָ���
//			while (getline(sin, word, ','))
//			{
//				m[i][j] = stod(word);
//				words.push_back(word); //��ÿһ���е��������push
//				j++;
//			}
//			i++;
//			j = 0;
//		}
//		csv_data.close();
//	}
//}
////��ʼ��������Ӵ�������˿�
//void init_matrix_population()
//{
//	//���Ӵ�����
//	read_file("data/Sichuan_npi0.csv", A_matrix);
//	read_file("data/Hubei_npi0.csv", B_matrix);
//	//�����������Ҹ��������˿�
//	age_distribution_A[0] = 5078;
//	age_distribution_A[1] = 4845;
//	age_distribution_A[2] = 5825;
//	age_distribution_A[3] = 7419;
//	age_distribution_A[4] = 7828;
//	age_distribution_A[5] = 5867;
//	age_distribution_A[6] = 6279;
//	age_distribution_A[7] = 10068;
//	age_distribution_A[8] = 10079;
//	age_distribution_A[9] = 7662;
//	age_distribution_A[10] = 5406;
//	age_distribution_A[11] = 7067;
//	age_distribution_A[12] = 5490;
//	age_distribution_A[13] = 4080;
//	age_distribution_A[14] = 2967;
//	age_distribution_A[15] = 1985;
//	age_distribution_A[16] = 1051;
//	age_distribution_A[17] = 1004;
//	age_distribution_B[0] = 5191;
//	age_distribution_B[1] = 4215;
//	age_distribution_B[2] = 4413;
//	age_distribution_B[3] =7982;
//	age_distribution_B[4] = 9531;
//	age_distribution_B[5] = 7234;
//	age_distribution_B[6] = 6885;
//	age_distribution_B[7] = 8552;
//	age_distribution_B[8] = 9975;
//	age_distribution_B[9] = 9011;
//	age_distribution_B[10] = 6621;
//	age_distribution_B[11] = 6396;
//	age_distribution_B[12] = 4866;
//	age_distribution_B[13] = 3323;
//	age_distribution_B[14] = 2455;
//	age_distribution_B[15] = 1804;
//	age_distribution_B[16] = 830;
//	age_distribution_B[17] = 715;
//}
////����Ǩ��
//void air_move()
//{
//	for (int i = 0; i < 18; i++)
//	{
//		//S̬Ǩ��
//		double A_can_go = A_S[i] * TS;//�������в��ɹ��뾳����
//		double B_can_go = B_S[i] * TS;//�������в��ɹ��뾳����
//		A_S[i] = A_S[i]-A_can_go+B_can_go;
//		B_S[i] = B_S[i]-B_can_go+A_can_go;
//		//E1̬Ǩ��(��ѡ)
//		double can_tr_A = A_E1[i][69999] * TS, can_tr_B = B_E1[i][69999] * TS;//�ܹ����е���
//		select_E1_A(0, i, int(can_tr_A));//A��E1̬���ߵ���Ⱥ
//		select_E1_B(0, i, int(can_tr_B));//B��E1̬���ߵ���Ⱥ
//		select_E1_B(1, i, int(can_tr_A));//��A��B��E1̬��Ⱥ
//		select_E1_A(1, i, int(can_tr_B));//��B��A��E1̬��Ⱥ
//		A_out_id.clear();
//		A_out_day.clear();
//		B_out_id.clear();
//		B_out_day.clear();//����vector
//		//E2̬Ǩ��(��ѡ)
//		can_tr_A = A_E2[i][69999] * TS, can_tr_B = B_E2[i][69999] *TS;//�ܹ����е���
//		select_E2_A(0, i, int(can_tr_A));//A��E2̬���ߵ���Ⱥ
//		select_E2_B(0, i, int(can_tr_B));//B��E2̬���ߵ���Ⱥ
//		select_E2_B(1, i, int(can_tr_A));//��A����B����E2̬��Ⱥ
//		select_E2_A(1, i, int(can_tr_B));//��B����A����E2̬��Ⱥ
//		A_out_id.clear();
//		A_out_day.clear();
//		B_out_id.clear();
//		B_out_day.clear();//����vector
//		//Ia̬Ǩ��
//		can_tr_A = A_Ia[i][69999] *TS, can_tr_B = B_Ia[i][69999]* TS;//�ܹ����е���
//		select_Ia_A(0, i, int(can_tr_A));//A��Ia̬���ߵ���Ⱥ
//		select_Ia_B(0, i, int(can_tr_B));//B��Ia̬���ߵ���Ⱥ
//		select_Ia_B(1, i, int(can_tr_A));//��A����B����Ia̬��Ⱥ
//		select_Ia_A(1, i, int(can_tr_B));//��B����A����Ia̬��Ⱥ
//		A_out_id.clear();
//		A_out_day.clear();
//		B_out_id.clear();
//		B_out_day.clear();//����vector
//		//R̬Ǩ��
//		A_can_go = A_R[i] * TS;//�������в��ɹ��뾳����
//		B_can_go = B_R[i] * TS;//�������в��ɹ��뾳����
//		A_R[i] = A_R[i] - A_can_go + B_can_go;
//		B_R[i] = B_R[i] - B_can_go + A_can_go;
//	}
//}
////��ѡA��E1̬,flag:0��ʾ����,1��ʾ����
//void select_E1_A(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	if (num > A_E1[age_group][69999]) {
//		std::cout << "Error: num exceeds available travelers in A_E1[" << age_group << "]" << std::endl;
//		return;
//	}
//	//��ѡ��ȥ���ÿ�
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E1[age_group][temp] != 0)
//			{
//				//��¼������flag
//				A_out_id.push_back(A_flag[age_group][temp]);
//				A_out_day.push_back(A_E1[age_group][temp]);
//				A_E1[age_group][temp] = 0;
//				A_E1[age_group][69999]--;
//				A_flag[age_group][temp] = -1;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	//��ѡ�������ÿ�
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E1[age_group][temp] == 0)
//			{
//				//��B����E1̬�οͼӽ���
//				int id = B_out_id.back(), last_day = B_out_day.back();
//				A_E1[age_group][temp] = last_day;
//				A_flag[age_group][temp] = id;
//				if (B_out_id.empty() || B_out_day.empty()) {
//					std::cout << "Error: B_out_id or B_out_day is empty before popping. num=" << num << std::endl;
//					break;
//				}
//				B_out_id.pop_back();
//				B_out_day.pop_back();
//				A_E1[age_group][69999]++;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//}
////��ѡB��E1̬,flag:0��ʾ����,1��ʾ����
//void select_E1_B(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//��ѡ��ȥ���ÿ�
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E1[age_group][temp] != 0)
//			{
//				//��¼��ź�flag
//				B_out_id.push_back(B_flag[age_group][temp]);
//				B_out_day.push_back(B_E1[age_group][temp]);
//				B_E1[age_group][temp] = 0;
//				B_E1[age_group][69999]--;
//				B_flag[age_group][temp] = -1;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	//��ѡ�������ÿ�
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E1[age_group][temp] == 0)
//			{
//				//��A����E1̬�οͼӽ���
//				int id = A_out_id.back(), last_day = A_out_day.back();
//				B_E1[age_group][temp] = last_day;
//				B_flag[age_group][temp] = id;
//				A_out_id.pop_back();
//				A_out_day.pop_back();
//				B_E1[age_group][69999]++;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//}
////��ѡA��E2̬,flag:0��ʾ����,1��ʾ����
//void select_E2_A(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//��ѡ��ȥ���ÿ�
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E2[age_group][temp] != 0)
//			{
//				//��¼��ź�����
//				A_out_id.push_back(temp);
//				A_out_day.push_back(A_E2[age_group][temp]);
//				A_E2[age_group][temp] = 0;
//				A_E2[age_group][69999]--;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	//��ѡ�������ÿ�
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E2[age_group][temp] == 0)
//			{
//				//��B����E2̬�οͼӽ���
//				int id = B_out_id.back(), last_day = B_out_day.back();
//				A_E2[age_group][temp] = last_day;
//				B_out_id.pop_back();
//				B_out_day.pop_back();
//				A_E2[age_group][69999]++;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//}
////��ѡB��E2̬,flag:0��ʾ����,1��ʾ����
//void select_E2_B(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//��ѡ��ȥ���ÿ�
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E2[age_group][temp] != 0)
//			{
//				//��¼��ź�����
//				B_out_id.push_back(temp);
//				B_out_day.push_back(B_E2[age_group][temp]);
//				B_E2[age_group][temp] = 0;
//				B_E2[age_group][69999]--;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	//��ѡ�������ÿ�
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E2[age_group][temp] == 0)
//			{
//				//��A����E2̬�οͼӽ���
//				int id = A_out_id.back(), last_day = A_out_day.back();
//				B_E2[age_group][temp] = last_day;
//				A_out_id.pop_back();
//				A_out_day.pop_back();
//				B_E2[age_group][69999]++;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//}
////��ѡA��Ia̬,flag:0��ʾ����,1��ʾ����
//void select_Ia_A(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//��ѡ��ȥ���ÿ�
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_Ia[age_group][temp] != 0)
//			{
//				//��¼����
//				A_out_day.push_back(A_Ia[age_group][temp]);
//				A_Ia[age_group][temp] = 0;
//				A_Ia[age_group][69999]--;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	//��ѡ�������ÿ�
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_Ia[age_group][temp] == 0)
//			{
//				//��B����Ia̬�οͼӽ���
//				int  last_day = B_out_day.back();
//				A_Ia[age_group][temp] = last_day;
//				if (B_out_id.empty() || B_out_day.empty()) {
//					//std::cout << "Error: B_out_id or B_out_day is empty before popping. num=" << num << std::endl;
//					break;
//				}
//				B_out_day.pop_back();
//				A_Ia[age_group][69999]++;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//}
////��ѡB��Ia̬,flag:0��ʾ����,1��ʾ����
//void select_Ia_B(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//��ѡ��ȥ���ÿ�
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_Ia[age_group][temp] != 0)
//			{
//				//��¼����
//				B_out_day.push_back(A_Ia[age_group][temp]);
//				B_Ia[age_group][temp] = 0;
//				B_Ia[age_group][69999]--;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	//��ѡ�������ÿ�
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_Ia[age_group][temp] == 0)
//			{
//				//��B����Ia̬�οͼӽ���
//				int last_day = A_out_day.back();
//				B_Ia[age_group][temp] = last_day;
//				A_out_day.pop_back();
//				B_Ia[age_group][69999]++;
//				num--;
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//}
////A���������в�����
//void transition_A()
//{
//	for (int i = 0; i < 18; i++)
//	{
//		if (i <= 3)Probability_asy = 1 - 0.181;
//		else if (i > 3 && i <= 7)Probability_asy = 1 - 0.224;
//		else if (i > 7 && i <= 11)Probability_asy = 1 - 0.305;
//		else Probability_asy = 1 - 0.355;
//		int temp = 0;
//		//S̬->E1̬
//		double t = 0;
//		for (int j = 0; j < 18; j++)
//		{
//			t += A_matrix[i][j] * (gamma_E2 * A_E2[j][69999] + gamma_Ia * A_Ia[j][69999] + A_I[j][69999]) / age_distribution_A[j];
//		}
//		double age_susceptibility = 0;
//		if (i <= 2)age_susceptibility = 0.58;
//		else if (i > 2 && i <= 12)age_susceptibility = 1;
//		else age_susceptibility = 1.65;
//
//		//����beta
//		/*double up = 2.5;
//		double left = 2 * (1 - 0.5 * Probability_asy);
//		double right = 5 * (1 - 0.5 * Probability_asy);
//		double down = 14.084118*(left+right);
//		beta_A = up / down;*/
//		if (i <= 3)beta_A = 0.042943;
//		else if (i <=7 && i>3)beta_A = 0.0414344;
//		else if (i <=11 && i >= 8)beta_A = 0.0388626;
//		else beta_A= 0.0374286;   
//		//cout << "age:" << i << " beta:" << beta_A<<endl;
//		temp = round(gsl_ran_binomial(R_GLOBAL, beta_A * t*age_susceptibility, A_S[i]));
//		//cout << temp<<endl;
//		A_S[i] -= temp;
//		while (temp > 0)
//		{
//			int tt = rand() % 69999;
//			if (A_E1[i][tt] != 0) continue;
//			double m = double(rand() % 10) / 10;
//			if (m <= Probability_asy)//��֢״
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period+ Psy_period));
//				if (tday == 0) continue;
//				A_flag[i][tt] = 0;
//				temp--;
//				A_E1[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//				A_E1[i][69999]++;
//			}		
//			else //��֢״
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period));
//				if (tday == 0) continue;
//				A_flag[i][tt] = 1;
//				temp--;
//				A_E1[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//				A_E1[i][69999]++;
//			}
//		}
//		//E1->Ia̬,E1->E2̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (A_E1[i][j] != 0)
//			{
//				A_E1[i][j]--;
//				if (A_E1[i][j] == 0)
//				{
//					if (A_flag[i][j] == 0) //��֢״
//					{
//						A_flag[i][j] = -1;//��ʼ��
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, 5));
//							if (A_Ia[i][tt] == 0 && tday != 0)
//							{
//								A_Ia[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//								A_Ia[i][69999]++;
//								break;
//							}
//							else
//							{
//								continue;
//							}
//						}
//					}
//					else //��֢״
//					{
//						//��ΪE2̬
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, Psy_period));
//							if (A_E2[i][tt] == 0 && tday != 0)
//							{
//								A_E2[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//								A_E2[i][69999]++;
//								newcase_A++;
//								A_flag[i][j] = -1;//��ʼ��
//								break;
//							}
//							else
//							{
//								continue;
//							}
//						}
//					}
//					A_E1[i][69999]--;
//				}
//			}
//		}
//		//E2->I̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (A_E2[i][j] != 0)
//			{
//				A_E2[i][j]--;
//				if (A_E2[i][j] == 0)
//				{
//					while (1)
//					{
//						int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, 5));
//						if (A_I[i][tt] == 0 && tday != 0)
//						{
//							A_I[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//							A_I[i][69999]++;
//							sum_I_A++;
//							A_flag[i][j] = -1;//��ʼ��
//							break;
//						}
//						else
//						{
//							continue;
//						}
//					}
//					A_E2[i][69999]--;
//				}
//			}
//		}
//		//Ia̬->R̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (A_Ia[i][j] != 0)
//			{
//				A_Ia[i][j]--;
//				if (A_Ia[i][j] == 0)
//				{
//					A_R[i]++;
//					A_Ia[i][69999]--;
//				}
//			}
//		}
//		//I̬->R̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (A_I[i][j] != 0)
//			{
//				A_I[i][j]--;
//				if (A_I[i][j] == 0)
//				{
//					A_R[i]++;
//					A_I[i][69999]--;
//				}
//			}
//		}
//	}
//}
////B���������в�����
//void transition_B()
//{
//	for (int i = 0; i < 18; i++)
//	{
//		if (i <= 3)Probability_asy = 1 - 0.181;
//		else if (i > 3 && i <= 7)Probability_asy = 1 - 0.224;
//		else if (i > 7 && i <= 11)Probability_asy = 1 - 0.305;
//		else Probability_asy = 1 - 0.355;
//		int temp = 0;
//		//S̬->E1̬
//		double t = 0;
//		for (int j = 0; j < 18; j++)
//		{
//			t += B_matrix[i][j] * (gamma_E2 * B_E2[j][69999] + gamma_Ia * B_Ia[j][69999] + B_I[j][69999]) / age_distribution_B[j];
//		}
//		double age_susceptibility = 0;
//		if (i <= 2)age_susceptibility = 0.58;
//		else if (i > 2 && i <= 12)age_susceptibility = 1;
//		else age_susceptibility = 1.65;
//
//		//����beta
//		/*double up = 2.5;
//		double left = 2 * (1 - 0.5 * Probability_asy);
//		double right = 5 * (1 - 0.5 * Probability_asy);
//		double down = 14.47788 * (left + right);
//		beta_B = up / down;*/
//		if (i <= 3)beta_B = 0.0417751;
//		else if (i <= 7 && i > 3)beta_B = 0.0403075;
//		else if (i <= 11 && i >= 8)beta_B = 0.0378056;
//		else beta_B = 0.0364106;
//		//cout << "B��������" << i << "betaΪ��" << beta_B << endl;
//		temp = round(gsl_ran_binomial(R_GLOBAL, beta_B * t * age_susceptibility, B_S[i]));
//		//cout << temp<<endl;
//		B_S[i] -= temp;
//		while (temp > 0)
//		{
//			int tt = rand() % 69999;
//			if (B_E1[i][tt] != 0) continue;
//			double m = double(rand() % 10) / 10;
//			if (m <= Probability_asy)//��֢״
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period + Psy_period));
//				if (tday == 0) continue;
//				B_flag[i][tt] = 0;
//				temp--;
//				B_E1[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//				B_E1[i][69999]++;
//			}
//			else //��֢״
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period));
//				if (tday == 0) continue;
//				B_flag[i][tt] = 1;
//				temp--;
//				B_E1[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//				B_E1[i][69999]++;
//			}
//		}
//		//E1->Ia̬,E1->E2̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (B_E1[i][j] != 0)
//			{
//				B_E1[i][j]--;
//				if (B_E1[i][j] == 0)
//				{
//					if (B_flag[i][j] == 0) //��֢״
//					{
//						B_flag[i][j] = -1;//��ʼ��
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, 5));
//							if (B_Ia[i][tt] == 0 && tday != 0)
//							{
//								B_Ia[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//								B_Ia[i][69999]++;
//								break;
//							}
//							else
//							{
//								continue;
//							}
//						}
//					}
//					else //��֢״
//					{
//						//��ΪE2̬
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, Psy_period));
//							if (B_E2[i][tt] == 0 && tday != 0)
//							{
//								B_E2[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//								B_E2[i][69999]++;
//								B_flag[i][j] = -1;//��ʼ��
//								break;
//							}
//							else
//							{
//								continue;
//							}
//						}
//					}
//					B_E1[i][69999]--;
//				}
//			}
//		}
//		//E2->I̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (B_E2[i][j] != 0)
//			{
//				B_E2[i][j]--;
//				if (B_E2[i][j] == 0)
//				{
//					while (1)
//					{
//						int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, 5));
//						if (B_I[i][tt] == 0 && tday != 0)
//						{
//							B_I[i][tt] = tday + 1;//+1����Ϊ������ȥһ��Ǳ��ʱ��
//							B_I[i][69999]++;
//							sum_I_B++;
//							newcase_B++;
//							B_flag[i][j] = -1;//��ʼ��
//							break;
//						}
//						else
//						{
//							continue;
//						}
//					}
//					B_E2[i][69999]--;
//				}
//			}
//		}
//		//Ia̬->R̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (B_Ia[i][j] != 0)
//			{
//				B_Ia[i][j]--;
//				if (B_Ia[i][j] == 0)
//				{
//					B_R[i]++;
//					B_Ia[i][69999]--;
//				}
//			}
//		}
//		//I̬->R̬
//		for (int j = 0; j < 69999; j++)
//		{
//			if (B_I[i][j] != 0)
//			{
//				B_I[i][j]--;
//				if (B_I[i][j] == 0)
//				{
//					B_R[i]++;
//					B_I[i][69999]--;
//				}
//			}
//		}
//	}
//}