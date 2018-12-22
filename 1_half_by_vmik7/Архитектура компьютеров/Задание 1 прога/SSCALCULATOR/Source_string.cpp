#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

const int S_len = 41;
// 0  ... 9    A  ...  Z	a  ...  z
// 48 ... 57   65 ...  90	97      122
const int Add_to_num = 48;
const int Add_to_Alpha = 55;
const int Add_to_alpha = 87;


char num_to_char(int num);
string char_from_dem_int(unsigned long long val, int final_ss);
unsigned long long char_to_dem_int(string str, int initial_ss);

struct div_item
{
	string div = "";
	string minus = "";
	string mod = "";
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	while (1)
	{

		//����
		string number_int = "";
		string number_real = "";
		int ss_first = 0, ss_second = 0;
		bool is_real = false;
		int int_len = 0, real_len = 0;
		bool is_error = false;
		do
		{
			char number[S_len];
			cout << "����� ��������CC ��������CC:\n";
			do
			{
				is_error = false;
				while (!(cin >> number >> ss_first >> ss_second))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "������������ ����! ������� �����:\n\n";
					cout << "����� ��������CC ��������CC:\n";
				}
				if (ss_first < 2 || ss_first > 36 || ss_second < 2 || ss_second > 36)
				{
					is_error = true;
					cout << "������� ��������� ����� ������ � ��������� �� 2 �� 36! ������� �����:\n\n";
					cout << "����� ��������CC ��������CC:\n";
				}

			} while (is_error);
			is_error = false;

			int_len = 0;
			real_len = 0;
			is_real = false;
			int temp_len = 0;
			int point_count = 0;
			for (int i = 0; i < S_len; i++)
			{
				if (number[i] == '\0')
				{
					if (is_real) real_len = temp_len;
					else int_len = temp_len;
					break;
				}
				else if (number[i] == '.' || number[i] == ',')
				{
					if (point_count == 0)
					{
						point_count++;
						is_real = true;
						int_len = temp_len;
						temp_len = 0;
					}
					else
					{
						is_error = true;
						break;
					}
				}
				else
				{
					temp_len++;
					if (number[i] < '0' || (number[i] > '9' && number[i] < 'A') || (number[i] > 'Z' && number[i] < 'a') || number[i] > 'z')
					{
						is_error = true;
						break;
					}
					if ((ss_first <= 10 && number[i] >= ss_first + Add_to_num) || (ss_first <= 36 && ((number[i] >= ss_first + Add_to_Alpha && number[i] < 'a') || (number[i] >= ss_first + Add_to_alpha))))
					{
						is_error = true;
						break;
					}
				}
			}

			//���� ��� ������ ������������ ���� ����� number_int � number_real
			if (!is_error)
			{
				for (int i = 0; i < int_len; i++)
					number_int.push_back(number[i]);
				if (is_real)
				{
					is_real = false;
					for (int i = int_len + 1; i < int_len + 1 + real_len; i++)
					{
						if (number[i] != '0')
						{
							is_real = true;
							break;
						}
					}
				}
				if (is_real)
				{
					for (int i = int_len + 1; i < int_len + 1 + real_len; i++)
						number_real.push_back(number[i]);
				}
			}
			else
			{
				cout << "������� ������� �����! ������� �����:\n\n";
			}
		} while (is_error);


		


		//��������� ����� ����� ������� �������
		//����� ����� ���������
		string final_int = "";

		//������ � ������ �������
		vector< vector<div_item> > divisions(0);

		//������ ��� ����������� �������
		vector<string> nums(0);

		//���������� ���� �������
		vector<string> mods(0);

		//������ current_num ��� ����� number_int. ����� ����� ��������� ������� �������
		string current_num = number_int;

		//������� ������� � ��������� �������
		unsigned long long current_num_int = char_to_dem_int(current_num, ss_first);

		//������� ������� � ���������� �������
		unsigned long long answer = current_num_int / ss_second;

		//��������� ����, ���� ������� ������� �� ����� ����
		while (answer)
		{
			//�������� ������� �������
			nums.push_back(current_num);

			//������ ������ ������� ����� ��������� ����� � divisions
			vector<div_item> temp_division(0);

			//�������� ������� �������
			int dig_count = current_num.size();		//����� �������� � �������
			int current_dig = 0;					//������� �������������� ������		 
			string cur_div = "0";					//������� �������
			string new_div = "";					//����� �������� �������� ��� ��� �������

			while (current_dig < dig_count)
			{
				if (cur_div[0] == '0')
				{
					//���� ��������� ������� �������, ������ ������ �����
					new_div = "";
					new_div += current_num[current_dig];
				}
				else
				{
					//������ �����
					new_div = cur_div;
					new_div += current_num[current_dig];
				}

				//��������� new_div � ���������� � ������� ������� ����� ������
				unsigned long long new_div_int = char_to_dem_int(new_div, ss_first);
				unsigned long long new_answer = new_div_int / ss_second;

				//���� ����� �� �������
				if (new_answer)
				{
					//���� :)
					div_item temp;
					temp.div = new_div;
					temp.minus = char_from_dem_int(ss_second * new_answer, ss_first);
					temp.mod = char_from_dem_int(new_div_int % ss_second, ss_first);
					temp_division.push_back(temp);

					//�������������� ������� � cur_div
					cur_div = temp.mod;

				}
				else
				{
					//��������� cur_div
					cur_div = new_div;
				}

				current_dig++;
			}

			divisions.push_back(temp_division);

			//����� �������
			unsigned long long mod = current_num_int - (answer * ss_second);	//��������� �������
			string mod_char = char_from_dem_int(mod, ss_first);					//��������� � ��������� ��
			mods.push_back(mod_char);											//��������� � �������
			divisions.back().back().mod = mod_char;

			//��������� current_num, current_num_int, answer, answer_char
			string answer_char = char_from_dem_int(answer, ss_first);
			current_num = answer_char;
			current_num_int = char_to_dem_int(current_num, ss_first);
			answer = current_num_int / ss_second;
		}

		//��������� ��������� ���������� ������� ��� �������
		mods.push_back(current_num);

		//�������� ��������� (������) �������
		nums.push_back(current_num);

		//��������� final_int ��������� ����� ������
		for (int i = mods.size() - 1; i >= 0; i--)
		{
			string mod_final = char_from_dem_int(char_to_dem_int(mods[i], ss_first), ss_second);
			final_int += mod_final[0];
		}



		//��������� ������� ����� ������� ���������
		//��������� ��������� � ��������� ��
		string calc_base = char_from_dem_int(ss_second, ss_first);

		//����� ����� �����
		string final_real = "";

		//����� ����� ������������ ����� ���������
		vector<string> factor_real(1);
		factor_real[0] = number_real;

		//����� ����� ����� �����, ������� ����������� � �������
		vector<string> factor_whole(1);
		factor_whole[0] = "0";

		vector<string> whole_final(1);
		whole_final[0] = "0";

		//����� ����� ���������� ��� �����
		vector< vector<string> > pluses(0);

		//���������� ���������
		int pluses_count = calc_base.size();

		//���������� ������ ���������
		int blocks_count = 0;

		//����� �������������
		bool is_repeat = false;

		//����� ����� ������, �� ������� ���������� ������
		int repeat_index = 0;

		//��������
		int prec = 9;

		//����� ������������ ��������
		bool is_overflow = false;

		if (is_real)
		{
			unsigned long long current_factor_dem = char_to_dem_int(factor_real[0], ss_first);

			//���� ��������� �� ����� ���� ��� �� ������ ������ ��� �� ����������� �������� ���������� ���������
			while (current_factor_dem && !is_overflow)
			{
				//����� ���������
				vector<string> pluses_temp(0);
				pluses.push_back(pluses_temp);
				for (int i = 0; i < pluses_count; i++)
				{
					//��������� � ���������� ������� ��������� ����� ���������
					string cur_num = "";
					cur_num += calc_base[pluses_count - 1 - i];
					unsigned long long cur_num_dem = char_to_dem_int(cur_num, ss_first);

					//�������� ��������� ���������
					unsigned long long answer_dem = current_factor_dem * cur_num_dem;
					string answer_char = "";
					if (answer_dem == 0)
					{
						for (int z = 0; z < real_len; z++)
							answer_char += '0';
					}
					else
					{
						answer_char = char_from_dem_int(answer_dem, ss_first);
						for (int z = 0; z < i; z++)	//����������� ������
							answer_char += '0';
					}

					//������ � ���������
					pluses[blocks_count].push_back(answer_char);
				}

				//��������� ��������� ���������� ����� � ��������� factor
				unsigned long long cur_result_dem = current_factor_dem * ss_second;
				string cur_result = char_from_dem_int(cur_result_dem, ss_first);

				//����� ����� ����������
				int res_whole_len = cur_result.size() - real_len;
				if (res_whole_len == 0)
				{
					string res_whole = "0";
					factor_whole.push_back(res_whole);
				}
				else
				{
					string res_whole = "";
					for (int i = 0; i < res_whole_len; i++)
					{
						res_whole += cur_result[i];
					}
					factor_whole.push_back(res_whole);
				}


				//������������ ����� ����������
				string res_real = "";
				for (int i = res_whole_len; i < cur_result.size(); i++)
				{
					res_real += cur_result[i];
				}
				factor_real.push_back(res_real);

				blocks_count++;

				//��������� �������������
				for (int i = 0; i < blocks_count; i++)
				{
					bool is_equal = true;
					if (factor_real.back() != factor_real[i])
						is_equal = false;
					if (is_equal)
					{
						is_repeat = true;
						repeat_index = i;
						break;
					}
				}

				//����� �� ����� ��� �������������
				if (is_repeat)
					break;

				//����� �� ����� �� ��������� �������� ��� ������������ ��������
				else if (blocks_count >= prec)
					is_overflow = true;

				current_factor_dem = char_to_dem_int(factor_real[blocks_count], ss_first);
			}

			//������� �����, ����������� �����
			final_real += '.';
			for (int i = 1; i < factor_whole.size(); i++)
			{
				string final_answer_num = char_from_dem_int(char_to_dem_int(factor_whole[i], ss_first), ss_second);
				final_real += final_answer_num[0];
				whole_final.push_back(final_answer_num);
			}

			//���������� ��������� ��� ������������
			if (is_overflow)
				final_real += "...";

			//���������� �������� � ������ �������
			if (is_repeat)
			{
				string c = "(";
				final_real.insert(repeat_index + 1, c);
				final_real += ')';
			}
		}



		//����������	
		//������, ������� ����� �������� cout
		vector<string> out_strs(0);

		//������������ �������
		//������� ������������ �������
		int divs = 0;

		//����, ������� ������������ ��� ������� divisions
		while (divs < divisions.size())
		{
			//������ �������� �������
			vector<string> cur_strs(0);

			//������ �������� �������
			int cur_num_width = nums[divs].size() + 1;	//+ 1 ����� ����������� �������� �������
			int cur_div_width = (cur_num_width > 6 ? cur_num_width : 6);

			//������� div_item
			int cur_div = 0;

			//������������ ������� div_item
			while (cur_div < divisions[divs].size())
			{
				//3 ������ �������
				string temp_div(cur_div_width + 1, ' ');	// + 1 ��� ����������� ������� �������
				string temp_minus(cur_div_width + 1, ' ');
				string temp_mod(cur_div_width + 1, ' ');

				int temp_div_index = 0;

				//��������� temp_div
				if (cur_div == 0)
				{
					//���� ��� ������ div_item, �� temp_div ����� �������� ��������
					temp_div = nums[divs];
					while (temp_div.size() < cur_div_width + 1) //��������� ��������� �� ������ ������������ ����� ������
						temp_div += ' ';
				}
				else
				{
					//����� ������������ temp_div c ���������� ��������
					temp_div = cur_strs[cur_div * 2];

					//������ temp_div
					temp_div_index = temp_div.size() - 1;
					while (temp_div[temp_div_index - 1] == ' ')
						temp_div_index--;

					//������ �������� div_item.div
					int div_item_div_index = 0;

					//���� ������� �������, ������� ����
					if (divisions[divs][cur_div - 1].mod[0] == '0')
						temp_div[temp_div_index - 1] = ' ';
					else
						while (temp_div_index && temp_div[temp_div_index - 1] != ' ')
							temp_div_index--;

					//���������� ������� div_item.div � temp_div
					for (int i = 0; i < divisions[divs][cur_div].div.size(); i++)
					{
						temp_div[temp_div_index] = divisions[divs][cur_div].div[i];
						temp_div_index++;
					}
				}

				//��������� temp_minus � temp_mod
				int minus_index;
				if (cur_div == 0)
					minus_index = divisions[divs][cur_div].div.size() - 1;
				else
					minus_index = --temp_div_index;

				int mod_index;
				if (cur_div == divisions[divs].size() - 1)
					mod_index = cur_num_width - 2;
				else
					mod_index = minus_index;

				for (int i = divisions[divs][cur_div].minus.size() - 1; i >= 0; i--)
				{
					temp_minus[minus_index] = divisions[divs][cur_div].minus[i];
					minus_index--;
				}

				for (int i = divisions[divs][cur_div].mod.size() - 1; i >= 0; i--)
				{
					temp_mod[mod_index] = divisions[divs][cur_div].mod[i];
					mod_index--;
				}

				//������ ������� � cur_strs
				if (cur_div != 0)
					cur_strs.pop_back();

				cur_strs.push_back(temp_div);
				cur_strs.push_back(temp_minus);
				cur_strs.push_back(temp_mod);

				//���� ������� � ��������
				if (cur_div == divisions[divs].size() - 1)
				{
					string mod_final = char_from_dem_int(char_to_dem_int(mods[divs], ss_first), ss_second);
					string temp_mod_dem = "";
					int temp_mod_dem_len = cur_num_width - 2 - int(mod_final.size());
					while (int(temp_mod_dem.size()) < temp_mod_dem_len)
						temp_mod_dem += ' ';
					temp_mod_dem += '[';
					for (int i = 0; i < mod_final.size(); i++)
						temp_mod_dem += mod_final[i];
					temp_mod_dem += ']';
					cur_strs.push_back(temp_mod_dem);
				}

				cur_div++;
			}

			//������ �������
			cur_strs[0][cur_div_width] = '|';
			cur_strs[1][cur_div_width] = '|';
			cur_strs[2][cur_div_width] = '|';

			//����� ���������
			cur_strs[0] += calc_base;

			//������ �����
			//������ ���������� �������
			int next_num_width = nums[divs + 1].size() + 1;	//+ 1 ����� ����������� �������� �������
			int next_div_width = (next_num_width > 6 ? next_num_width : 6);

			for (int i = 0; i < next_div_width; i++)
				cur_strs[1] += '-';

			//����� ���������
			cur_strs[2] += nums[divs + 1];

			//���� ��������� ������� � ��������
			if (divs == divisions.size() - 1)
			{
				string last_answer_final = char_from_dem_int(char_to_dem_int(nums.back(), ss_first), ss_second);

				while (cur_strs[3].size() < cur_div_width + 1)
					cur_strs[3] += ' ';
				cur_strs[3].pop_back();
				while (cur_strs[3].size() < cur_strs[2].size() + 1 - last_answer_final.size() - 2)
					cur_strs[3] += ' ';
				cur_strs[3] += '[';
				for (int i = 0; i < last_answer_final.size(); i++)
					cur_strs[3] += last_answer_final[i];
				cur_strs[3] += ']';
			}

			//������ cur_strs � out_strs;
			if (divs == 0)
			{
				for (int i = 0; i < cur_strs.size(); i++)
					out_strs.push_back(cur_strs[i]);
			}
			else
			{
				int out_str_number = divs * 2;
				int out_str_index = out_strs[out_str_number].size() - nums[divs].size();
				//int first_str_index = out_str_index;

				for (int i = 0; i < nums[divs].size(); i++)
					out_strs[out_str_number].pop_back();

				for (int i = 0; i < cur_strs.size(); i++)
				{
					if (out_str_number < out_strs.size())
					{
						while (out_strs[out_str_number].size() < out_str_index)
							out_strs[out_str_number] += ' ';
						out_strs[out_str_number] += cur_strs[i];
					}
					else
					{
						string temp_str(out_str_index, ' ');
						temp_str += cur_strs[i];
						out_strs.push_back(temp_str);
					}
					out_str_number++;
				}
			}

			divs++;
		}


		//������������ ���������
		if (is_real)
		{
			vector<string> real_out(0);

			int max_whole_size = 1;
			for (int i = 1; i < factor_whole.size(); i++)
			{
				if (factor_whole[i].size() > max_whole_size)
					max_whole_size = factor_whole[i].size();
			}

			//����� ���������
			int calc_base_len = calc_base.size();

			//����� ����� ������
			int real_out_len = 4 + max_whole_size + 1 + (real_len > calc_base_len + 1 ? real_len : calc_base_len + 1);

			for (int fact = 0; fact < blocks_count; fact++)
			{
				//������ � real_out ���������
				string factor_str = "";

				//��������� ������� �� ������� ����� ������������ ������� ������ � ������� ������ ������
				for (int p = 0; p < max_whole_size - factor_whole[fact].size(); p++)
					factor_str += ' ';

				//��������� ������� ����� ����� � ��������
				if (fact == 0)
				{
					for (int i = 0; i < 4; i++)
						factor_str += ' ';
				}
				else
				{
					factor_str += '[';
					factor_str += whole_final[fact];
					factor_str += ']';
					factor_str += '=';
				}

				//��������� ����� ����� ���������
				for (int i = 0; i < factor_whole[fact].size(); i++)
					factor_str += factor_whole[fact][i];

				//��������� �������
				factor_str += '|';

				//��������� ������� ���� ����� ��������� ������
				for (int p = 0; p < calc_base_len + 1 - real_len; p++)
					factor_str += ' ';

				//��������� ������������ ����� ���������
				for (int i = 0; i < real_len; i++)
					factor_str += factor_real[fact][i];

				real_out.push_back(factor_str);


				//������ � real_out ���������
				string calc_base_str = "";

				//��������� �������
				for (int p = 0; p < max_whole_size + 4; p++)
					calc_base_str += ' ';

				//��������� �������
				calc_base_str += '|';

				//��������� ������� ���� ����� ����� ����� ������
				for (int p = 0; p < real_len - calc_base_len - 1; p++)
					calc_base_str += ' ';

				//��������� ���� ���������
				calc_base_str += '*';

				//��������� ���������
				for (int i = 0; i < calc_base_len; i++)
					calc_base_str += calc_base[i];

				real_out.push_back(calc_base_str);


				//������ � real_out ���������
				for (int pl = 0; pl < pluses_count; pl++)
				{
					bool is_zero = true;
					for (int i = 0; i < pluses[fact][pl].size(); i++)
					{
						if (pluses[fact][pl][i] != '0')
						{
							is_zero = false;
							break;
						}
					}
					if (is_zero)
						continue;

					string temp_plus_str = "";

					//��������� ������� �� �������� ����� ������ ������ ����� �������� � ������ ����� ����� ����������
					for (int p = 0; p < 4 + max_whole_size - pluses[fact][pl].size() + real_len; p++)
						temp_plus_str += ' ';

					//��������� ����� ����� ����������
					for (int i = 0; i < pluses[fact][pl].size() - real_len; i++)
						temp_plus_str += pluses[fact][pl][i];

					//��������� �������
					temp_plus_str += '|';

					//��������� ������� ���� ����� ��������� ������
					for (int p = 0; p < calc_base_len + 1 - real_len; p++)
						temp_plus_str += ' ';

					//��������� ������������ ����� ����������
					for (int i = pluses[fact][pl].size() - real_len; i < pluses[fact][pl].size() - pl; i++)
						temp_plus_str += pluses[fact][pl][i];

					//�������� ��������� ������ ���������
					for (int i = 0; i < pl; i++)
						temp_plus_str += ' ';

					real_out.push_back(temp_plus_str);
				}


				//������ � real_out �����
				string line_str = "";
				for (int l = 0; l < real_out_len; l++)
					line_str += '-';
				real_out.push_back(line_str);
			}

			//������ � real_out ����� ��������� ���������
			string factor_str = "";

			//��������� ������� �� ������� ����� ������������ ������� ������ � ������� ������ ������
			for (int p = 0; p < max_whole_size - factor_whole[blocks_count].size(); p++)
				factor_str += ' ';

			//��������� ������� ����� ����� � ��������

			factor_str += '[';
			factor_str += whole_final[blocks_count];
			factor_str += ']';
			factor_str += '=';

			//��������� ����� ����� ���������
			for (int i = 0; i < factor_whole[blocks_count].size(); i++)
				factor_str += factor_whole[blocks_count][i];

			//��������� �������
			factor_str += '|';

			//��������� ������� ���� ����� ��������� ������
			for (int p = 0; p < calc_base_len + 1 - real_len; p++)
				factor_str += ' ';

			//��������� ������������ ����� ���������
			for (int i = 0; i < real_len; i++)
				factor_str += factor_real[blocks_count][i];

			real_out.push_back(factor_str);


			//��������� real_out � out_strs
			int max_out_str_len = 0;
			for (int i = 0; i < out_strs.size(); i++)
			{
				if (out_strs[i].size() > max_out_str_len)
					max_out_str_len = out_strs[i].size();
			}

			int real_out_space = 6;

			for (int i = 0; i < real_out.size(); i++)
			{
				if (i < out_strs.size())
				{
					while (out_strs[i].size() < max_out_str_len + real_out_space)
						out_strs[i] += ' ';
					out_strs[i] += real_out[i];
				}
				else
				{
					string temp_str = "";
					while (temp_str.size() < max_out_str_len + real_out_space)
						temp_str += ' ';
					temp_str += real_out[i];
					out_strs.push_back(temp_str);
				}
			}
		}


		//�����
		cout << endl;
		for (int i = 0; i < out_strs.size(); i++)
			cout << out_strs[i] << endl;
		cout << "\n�����: " << final_int << final_real << endl << endl << endl;
	}

	cout << "��� ������ ������� ����� ������� ..." << endl;
	_getch();
	return 0;
}



string char_from_dem_int(unsigned long long val, int final_ss)
{
	vector<char> new_str(0);
	while (val >= final_ss)
	{
		int digit = val % final_ss;
		if (digit < 10) digit += Add_to_num;
		else digit += Add_to_Alpha;
		new_str.push_back(char(digit));
		val /= final_ss;
	}
	int digit = val % final_ss;
	if (digit < 10) digit += Add_to_num;
	else digit += Add_to_Alpha;
	new_str.push_back(char(digit));

	string result = "";
	for (int i = new_str.size() - 1; i >= 0; i--)
		result += new_str[i];

	return result;
}



unsigned long long char_to_dem_int(string str, int initial_ss)
{
	unsigned long long result = 0;
	unsigned long long power = 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		int digit = str[i];
		if (digit <= 57) digit -= Add_to_num;
		else if (digit <= 90) digit -= Add_to_Alpha;
		else digit -= Add_to_alpha;
		result += digit * power;
		power *= initial_ss;
	}

	return result;
}



char num_to_char(int num)
{
	if (num < 10) num += Add_to_num;
	else num += Add_to_Alpha;
	return char(num);
}