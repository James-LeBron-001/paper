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
////函数
//void read_file(string path, double m[18][18]);//读文件
//void init_matrix_population();//初始化人口和接触矩阵
//void air_move();//航空迁移
//void select_E1_A(int flag, int age_group, int num);//挑选A国E1态,flag:0表示出走,1表示进来
//void select_E1_B(int flag, int age_group, int num);//挑选B国E1态,flag:0表示出走,1表示进来
//void select_E2_A(int flag, int age_group, int num);//挑选A国E2态,flag:0表示出走,1表示进来
//void select_E2_B(int flag, int age_group, int num);//挑选B国E2态,flag:0表示出走,1表示进来
//void select_Ia_A(int flag, int age_group, int num);//挑选A国Ia态,flag:0表示出走,1表示进来
//void select_Ia_B(int flag, int age_group, int num);//挑选B国Ia态,flag:0表示出走,1表示进来
//void transition_A();//塞浦路斯国家内流行病传播
//void transition_B();//卢森堡国家内流行病传播
//void getnum();//获得感染人数
//
////变量
//double A_matrix[18][18];//接触矩阵
//double B_matrix[18][18];//
//double A_S[18] = { 0 };//两个国家各状态人群
//double A_E1[18][70000] = { 0 };//序号69999记录总人数，其余为患者
//double A_E2[18][70000] = { 0 };//序号69999记录总人数，其余为患者
//double A_flag[18][70000] = { 0 };//为1表示会进入E2态，为0表示不会进入,-1表示没有这个编号
//double A_Ia[18][70000] = { 0 };
//double A_I[18][70000] = { 0 };
//double A_R[18] = { 0 };
//double B_S[18] = { 0 };
//double B_E1[18][70000] = { 0 };//序号69999记录总人数，其余为患者编号和潜伏天数
//double B_E2[18][70000] = { 0 };//序号69999记录总人数，其余为患者编号和潜伏天数
//double B_flag[18][70000] = { 0 };//为1表示会进入E2态，为0表示不会进入,-1表示没有这个编号
//double B_Ia[18][70000] = { 0 };
//double B_I[18][70000] = { 0 };
//double B_R[18] = { 0 };
//int age_distribution_B[18] = { 0 };//各年龄组人口
//int age_distribution_A[18] = { 0 }; 
//int day = 1;//时间步------每一天
//vector<int> A_out_id;//A国出去的人编号
//vector<int> A_out_day;//A国出去的人潜伏剩余天数
//vector<int> B_out_id;//B国出去的人编号
//vector<int> B_out_day;//B国出去的人潜伏剩余天数
////参数
//double TS = 0;//两国交互程度（旅行限制）
//double beta_B = 0;//传播率
//double beta_A = 0;//传播率
//double gammaa = 0.2;//恢复率
//double Probability_asy = 0;//无症状率(随年龄发生变化) 
//double gamma_Ia = 0.5;//无症状态相对易感性
//double gamma_E2 = 1;//症前传播相对易感性
//double Exposed_period = 3;//平均潜伏时间
//double Psy_period = 2;//平均潜伏时间
//
//double sum_I_A = 0;
//double sum_I_B = 0;
//double newcase_A = 0;
//double newcase_B = 0;
//double sum_A[30][365] = {0};//A国总感染人数
//double sum_B[30][365] = {0};//B国总感染人数
//double sum_all[30][365] = { 0 };//总感染人数
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
//double new_A[30][365] = { 0 };//A每日新增人数
//double new_B[30][365] = { 0 };//B每日新 增人数
//int epoch = 0;//轮次
//
//int main()
//{
//	init_matrix_population();//初始化 
//	R_GLOBAL = gsl_rng_alloc(gsl_rng_taus);
//	for (int i = 1; i <=30; i++)
//	{
//		gsl_rng_set(R_GLOBAL, time(NULL)+i);
//		getnum();
//		cout << "step:" << i << endl;
//		cout << sum_I_A << "   " << sum_I_B << endl;
//	}
//	gsl_rng_free(R_GLOBAL);
//	ofstream outFile0, outFile1, outFile2, outFile3, outFile4, outFile5, outFile6, outFile7, outFile8,outFile9, outFile10, outFile11, outFile12, outFile13, outFile14, outFile15, outFile16; // 创建流对象
//	outFile0.open("res/sum_A.csv", ios::app); // 打开文件
//	outFile1.open("res/sum_B.csv", ios::app); // 打开文件
//	outFile2.open("res/sum_all.csv", ios::app); // 打开文件
//	outFile3.open("res/A_S.csv", ios::app); // 打开文件
//	outFile4.open("res/A_E1.csv", ios::app); // 打开文件
//	outFile5.open("res/A_E2.csv", ios::app); // 打开文件
//	outFile6.open("res/A_I.csv", ios::app); // 打开文件
//	outFile7.open("res/A_Ia.csv", ios::app); // 打开文件
//	outFile8.open("res/A_R.csv", ios::app); // 打开文件
//	outFile9.open("res/B_S.csv", ios::app); // 打开文件
//	outFile10.open("res/B_E1.csv", ios::app); // 打开文件
//	outFile11.open("res/B_E2.csv", ios::app); // 打开文件
//	outFile12.open("res/B_I.csv", ios::app); // 打开文件
//	outFile13.open("res/B_Ia.csv", ios::app); // 打开文件
//	outFile14.open("res/B_R.csv", ios::app); // 打开文件
//	outFile15.open("res/new_A.csv", ios::app); // 打开文件
//	outFile16.open("res/new_B.csv", ios::app); // 打开文件
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
//	outFile0.close(); // 关闭文件
//	outFile1.close(); // 关闭文件
//	outFile2.close(); // 关闭文件
//	outFile3.close(); // 关闭文件
//	outFile4.close(); // 关闭文件
//	outFile5.close(); // 关闭文件
//	outFile6.close(); // 关闭文件
//	outFile7.close(); // 关闭文件
//	outFile8.close(); // 关闭文件
//	outFile9.close(); // 关闭文件
//	outFile10.close(); // 关闭文件
//	outFile11.close(); // 关闭文件
//	outFile12.close(); // 关闭文件
//	outFile13.close(); // 关闭文件
//	outFile14.close(); // 关闭文件
//
//	return 0;
//}
//void getnum()
//{
//	day = 1;
//	sum_I_A = 0;
//	sum_I_B = 0;
//	//全为S态
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
//	//传播开始时每个国家有5个E1态节点
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
//		air_move();//航空迁移
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
////读文件
//void read_file(string path, double m[18][18])
//{
//	//以读入方式打开文件
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
//		vector<string> words; //声明一个字符串向量
//		string word;
//		// ------------读取数据-----------------
//
//		istringstream sin;
//		// 按行读取数据
//		int i = 0, j = 0;//i表示行，j表示列
//		while (getline(csv_data, line))
//		{
//			// 清空vector及字符串流,只存当前行的数据
//			words.clear();
//			sin.clear();
//
//			sin.str(line);
//			//将字符串流sin中的字符读到字符串数组words中，以逗号为分隔符
//			while (getline(sin, word, ','))
//			{
//				m[i][j] = stod(word);
//				words.push_back(word); //将每一格中的数据逐个push
//				j++;
//			}
//			i++;
//			j = 0;
//		}
//		csv_data.close();
//	}
//}
////初始化，读入接触矩阵和人口
//void init_matrix_population()
//{
//	//读接触矩阵
//	read_file("data/Sichuan_npi0.csv", A_matrix);
//	read_file("data/Hubei_npi0.csv", B_matrix);
//	//读入两个国家各年龄组人口
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
////航空迁移
//void air_move()
//{
//	for (int i = 0; i < 18; i++)
//	{
//		//S态迁移
//		double A_can_go = A_S[i] * TS;//可以旅行并成功入境的人
//		double B_can_go = B_S[i] * TS;//可以旅行并成功入境的人
//		A_S[i] = A_S[i]-A_can_go+B_can_go;
//		B_S[i] = B_S[i]-B_can_go+A_can_go;
//		//E1态迁移(挑选)
//		double can_tr_A = A_E1[i][69999] * TS, can_tr_B = B_E1[i][69999] * TS;//能够旅行的人
//		select_E1_A(0, i, int(can_tr_A));//A国E1态出走的人群
//		select_E1_B(0, i, int(can_tr_B));//B国E1态出走的人群
//		select_E1_B(1, i, int(can_tr_A));//从A来B的E1态人群
//		select_E1_A(1, i, int(can_tr_B));//从B来A的E1态人群
//		A_out_id.clear();
//		A_out_day.clear();
//		B_out_id.clear();
//		B_out_day.clear();//清理vector
//		//E2态迁移(挑选)
//		can_tr_A = A_E2[i][69999] * TS, can_tr_B = B_E2[i][69999] *TS;//能够旅行的人
//		select_E2_A(0, i, int(can_tr_A));//A国E2态出走的人群
//		select_E2_B(0, i, int(can_tr_B));//B国E2态出走的人群
//		select_E2_B(1, i, int(can_tr_A));//从A国来B国的E2态人群
//		select_E2_A(1, i, int(can_tr_B));//从B国来A国的E2态人群
//		A_out_id.clear();
//		A_out_day.clear();
//		B_out_id.clear();
//		B_out_day.clear();//清理vector
//		//Ia态迁移
//		can_tr_A = A_Ia[i][69999] *TS, can_tr_B = B_Ia[i][69999]* TS;//能够旅行的人
//		select_Ia_A(0, i, int(can_tr_A));//A国Ia态出走的人群
//		select_Ia_B(0, i, int(can_tr_B));//B国Ia态出走的人群
//		select_Ia_B(1, i, int(can_tr_A));//从A国来B国的Ia态人群
//		select_Ia_A(1, i, int(can_tr_B));//从B国来A国的Ia态人群
//		A_out_id.clear();
//		A_out_day.clear();
//		B_out_id.clear();
//		B_out_day.clear();//清理vector
//		//R态迁移
//		A_can_go = A_R[i] * TS;//可以旅行并成功入境的人
//		B_can_go = B_R[i] * TS;//可以旅行并成功入境的人
//		A_R[i] = A_R[i] - A_can_go + B_can_go;
//		B_R[i] = B_R[i] - B_can_go + A_can_go;
//	}
//}
////挑选A国E1态,flag:0表示出走,1表示进来
//void select_E1_A(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	if (num > A_E1[age_group][69999]) {
//		std::cout << "Error: num exceeds available travelers in A_E1[" << age_group << "]" << std::endl;
//		return;
//	}
//	//挑选出去的旅客
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E1[age_group][temp] != 0)
//			{
//				//记录天数和flag
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
//	//挑选进来的旅客
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E1[age_group][temp] == 0)
//			{
//				//将B国的E1态游客加进来
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
////挑选B国E1态,flag:0表示出走,1表示进来
//void select_E1_B(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//挑选出去的旅客
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E1[age_group][temp] != 0)
//			{
//				//记录编号和flag
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
//	//挑选进来的旅客
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E1[age_group][temp] == 0)
//			{
//				//将A国的E1态游客加进来
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
////挑选A国E2态,flag:0表示出走,1表示进来
//void select_E2_A(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//挑选出去的旅客
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E2[age_group][temp] != 0)
//			{
//				//记录编号和天数
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
//	//挑选进来的旅客
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_E2[age_group][temp] == 0)
//			{
//				//将B国的E2态游客加进来
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
////挑选B国E2态,flag:0表示出走,1表示进来
//void select_E2_B(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//挑选出去的旅客
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E2[age_group][temp] != 0)
//			{
//				//记录编号和天数
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
//	//挑选进来的旅客
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_E2[age_group][temp] == 0)
//			{
//				//将A国的E2态游客加进来
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
////挑选A国Ia态,flag:0表示出走,1表示进来
//void select_Ia_A(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//挑选出去的旅客
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_Ia[age_group][temp] != 0)
//			{
//				//记录天数
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
//	//挑选进来的旅客
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (A_Ia[age_group][temp] == 0)
//			{
//				//将B国的Ia态游客加进来
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
////挑选B国Ia态,flag:0表示出走,1表示进来
//void select_Ia_B(int flag, int age_group, int num)
//{
//	if (num <= 0) return;
//	//挑选出去的旅客
//	if (flag == 0)
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_Ia[age_group][temp] != 0)
//			{
//				//记录天数
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
//	//挑选进来的旅客
//	else
//	{
//		while (num > 0)
//		{
//			int temp = rand() % 69999;
//			if (B_Ia[age_group][temp] == 0)
//			{
//				//将B国的Ia态游客加进来
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
////A国家内流行病传播
//void transition_A()
//{
//	for (int i = 0; i < 18; i++)
//	{
//		if (i <= 3)Probability_asy = 1 - 0.181;
//		else if (i > 3 && i <= 7)Probability_asy = 1 - 0.224;
//		else if (i > 7 && i <= 11)Probability_asy = 1 - 0.305;
//		else Probability_asy = 1 - 0.355;
//		int temp = 0;
//		//S态->E1态
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
//		//估计beta
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
//			if (m <= Probability_asy)//无症状
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period+ Psy_period));
//				if (tday == 0) continue;
//				A_flag[i][tt] = 0;
//				temp--;
//				A_E1[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//				A_E1[i][69999]++;
//			}		
//			else //有症状
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period));
//				if (tday == 0) continue;
//				A_flag[i][tt] = 1;
//				temp--;
//				A_E1[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//				A_E1[i][69999]++;
//			}
//		}
//		//E1->Ia态,E1->E2态
//		for (int j = 0; j < 69999; j++)
//		{
//			if (A_E1[i][j] != 0)
//			{
//				A_E1[i][j]--;
//				if (A_E1[i][j] == 0)
//				{
//					if (A_flag[i][j] == 0) //无症状
//					{
//						A_flag[i][j] = -1;//初始化
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, 5));
//							if (A_Ia[i][tt] == 0 && tday != 0)
//							{
//								A_Ia[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//								A_Ia[i][69999]++;
//								break;
//							}
//							else
//							{
//								continue;
//							}
//						}
//					}
//					else //有症状
//					{
//						//变为E2态
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, Psy_period));
//							if (A_E2[i][tt] == 0 && tday != 0)
//							{
//								A_E2[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//								A_E2[i][69999]++;
//								newcase_A++;
//								A_flag[i][j] = -1;//初始化
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
//		//E2->I态
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
//							A_I[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//							A_I[i][69999]++;
//							sum_I_A++;
//							A_flag[i][j] = -1;//初始化
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
//		//Ia态->R态
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
//		//I态->R态
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
////B国家内流行病传播
//void transition_B()
//{
//	for (int i = 0; i < 18; i++)
//	{
//		if (i <= 3)Probability_asy = 1 - 0.181;
//		else if (i > 3 && i <= 7)Probability_asy = 1 - 0.224;
//		else if (i > 7 && i <= 11)Probability_asy = 1 - 0.305;
//		else Probability_asy = 1 - 0.355;
//		int temp = 0;
//		//S态->E1态
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
//		//估计beta
//		/*double up = 2.5;
//		double left = 2 * (1 - 0.5 * Probability_asy);
//		double right = 5 * (1 - 0.5 * Probability_asy);
//		double down = 14.47788 * (left + right);
//		beta_B = up / down;*/
//		if (i <= 3)beta_B = 0.0417751;
//		else if (i <= 7 && i > 3)beta_B = 0.0403075;
//		else if (i <= 11 && i >= 8)beta_B = 0.0378056;
//		else beta_B = 0.0364106;
//		//cout << "B地年龄组" << i << "beta为：" << beta_B << endl;
//		temp = round(gsl_ran_binomial(R_GLOBAL, beta_B * t * age_susceptibility, B_S[i]));
//		//cout << temp<<endl;
//		B_S[i] -= temp;
//		while (temp > 0)
//		{
//			int tt = rand() % 69999;
//			if (B_E1[i][tt] != 0) continue;
//			double m = double(rand() % 10) / 10;
//			if (m <= Probability_asy)//无症状
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period + Psy_period));
//				if (tday == 0) continue;
//				B_flag[i][tt] = 0;
//				temp--;
//				B_E1[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//				B_E1[i][69999]++;
//			}
//			else //有症状
//			{
//				int  tday = round(gsl_ran_exponential(R_GLOBAL, Exposed_period));
//				if (tday == 0) continue;
//				B_flag[i][tt] = 1;
//				temp--;
//				B_E1[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//				B_E1[i][69999]++;
//			}
//		}
//		//E1->Ia态,E1->E2态
//		for (int j = 0; j < 69999; j++)
//		{
//			if (B_E1[i][j] != 0)
//			{
//				B_E1[i][j]--;
//				if (B_E1[i][j] == 0)
//				{
//					if (B_flag[i][j] == 0) //无症状
//					{
//						B_flag[i][j] = -1;//初始化
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, 5));
//							if (B_Ia[i][tt] == 0 && tday != 0)
//							{
//								B_Ia[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//								B_Ia[i][69999]++;
//								break;
//							}
//							else
//							{
//								continue;
//							}
//						}
//					}
//					else //有症状
//					{
//						//变为E2态
//						while (1)
//						{
//							int tt = rand() % 69999, tday = round(gsl_ran_exponential(R_GLOBAL, Psy_period));
//							if (B_E2[i][tt] == 0 && tday != 0)
//							{
//								B_E2[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//								B_E2[i][69999]++;
//								B_flag[i][j] = -1;//初始化
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
//		//E2->I态
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
//							B_I[i][tt] = tday + 1;//+1是因为下面会减去一天潜伏时间
//							B_I[i][69999]++;
//							sum_I_B++;
//							newcase_B++;
//							B_flag[i][j] = -1;//初始化
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
//		//Ia态->R态
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
//		//I态->R态
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