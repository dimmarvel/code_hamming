#include<iostream>
#include<cstring>
#include<map>
enum PLUS_SIZE;
PLUS_SIZE get_next_ps(PLUS_SIZE p_s);
void cout_arr(int *bit_array, int size) {
	for (int i = 1; i < size + 1; i++)
	{
		std::cout << " " << bit_array[i];
	}
	std::cout << std::endl;
}
void init_arr(int *bit_array, int size) {
	for (int i = 1; i < size + 1; i++) {
		bit_array[i] = i;
	}
}
enum PLUS_SIZE
{
	ONE = 1, TWO = 2, THREE = 4,
	FOUR = 8, FIVE = 16, SIX = 32,
	SEVEN = 64, EIGHT = 128, NINE = 256,
};
int* create_bit_array(int **arr_bit, int size_h, int size_a, int size_numbers, int *arr_numbers, PLUS_SIZE p_s) {
	PLUS_SIZE fnc_p_c = { ONE };
	int size_char_bit_arr = size_h + size_a;
	int *char_bit_arr = new int[size_char_bit_arr];
	int *bit_and_contrbit_arr = new int[size_char_bit_arr];
	std::cout << "ha:\n" << "h - ";
	for (int i = 0; i < size_h; i++)
	{
		char_bit_arr[i] = arr_bit[0][i];
		std::cout << char_bit_arr[i];
	}
	std::cout << std::endl;
	std::cout << "a - ";
	for (int i = 0; i < size_a; i++)
	{
		char_bit_arr[size_h + i] = arr_bit[1][i];
		std::cout << char_bit_arr[size_h + i];
	}
	std::cout << std::endl;
	std::cout << "ha - ";
	for (int i = 0; i < size_char_bit_arr; i++)
	{
		std::cout << char_bit_arr[i];
	}
	int j = 0;
	std::cout << std::endl;
	for (int i = 1; i <= size_numbers; i++)
	{
		if (i == fnc_p_c) {
			bit_and_contrbit_arr[i] = 0;
			fnc_p_c = get_next_ps(fnc_p_c);
		}
		else {
			bit_and_contrbit_arr[i] = char_bit_arr[j++];
			if(i >= fnc_p_c)
				fnc_p_c = get_next_ps(fnc_p_c);
		}
	}
	std::cout << "\nbit_and_contrbit_arr - ";
	for (int i = 1; i <= size_numbers; i++)
	{
		std::cout << bit_and_contrbit_arr[i];
	}
	return bit_and_contrbit_arr;
}
PLUS_SIZE get_next_ps(PLUS_SIZE p_s) {
	return static_cast<PLUS_SIZE>(static_cast<int>(p_s) * 2);
}
PLUS_SIZE calc_size(PLUS_SIZE p_s, int index, int i = 0) {
	if (p_s < index) {
		p_s = get_next_ps(p_s);
		p_s = calc_size(p_s, index);
	}
	return p_s;
}
bool X_counter(int* arr_bit,PLUS_SIZE p_s,int size_bit_arr) {
	//true - ���
	//false - �� ���

}
int main() {
	setlocale(LC_ALL, "rus");
	int h[8] = { 0,1,0,0,0,1,0,0 };
	int a[8] = { 0,0,1,1,1,1,0,1 };
	int size_bit_sum = (sizeof(h) / sizeof(int)) + (sizeof(a) / sizeof(int));
	int size_bit_h = sizeof(h) / sizeof(int);
	int size_bit_a = sizeof(a) / sizeof(int);
	int *word[2];
	word[0] = new int[size_bit_h];
	word[1] = new int[size_bit_a];
	word[0] = h;
	word[1] = a;

	int two_pow_bit_array[9] =
	{
		1, 2, 4,
		8, 16, 32,
		64, 128, 256
	};
	PLUS_SIZE plus_size = { ONE };

	std::cout << "����� ���: " << size_bit_sum << std::endl;
	int index = size_bit_sum;
	int *bit_arr = new int[index];
	init_arr(bit_arr, index);
	cout_arr(bit_arr, index);

	plus_size = calc_size(plus_size, index);
	switch (plus_size) {
	case ONE:
		std::cout << "����� �����: " << index << " + 1 �����. ��� = ";
		index++;
		std::cout << index << std::endl;
		break;
	case TWO:
		std::cout << "����� �����: " << index << " + 2 �����. ��� = ";
		index += 2;
		std::cout << index << std::endl;
		break;
	case THREE:
		std::cout << "����� �����: " << index << " + 3 �����. ��� = ";
		index += 3;
		std::cout << index << std::endl;
		break;
	case FOUR:
		std::cout << "����� �����: " << index << " + 4 �����. ��� = ";
		index += 4;
		std::cout << index << std::endl;
		break;
	case FIVE:
		std::cout << "����� �����: " << index << " + 5 �����. ��� = ";
		index += 5;
		std::cout << index << std::endl;
		break;
	case SIX:
		std::cout << "����� �����: " << index << " + 6 �����. ��� = ";
		index += 6;
		std::cout << index << std::endl;
		break;
	case SEVEN:
		std::cout << "����� �����: " << index << " + 7 �����. ��� = ";
		index += 7;
		std::cout << index << std::endl;
		break;
	case EIGHT:
		std::cout << "����� �����: " << index << " + 8 �����. ��� = ";
		index += 8;
		std::cout << index << std::endl;
		break;
	case NINE:
		std::cout << "����� �����: " << index << " + 9 �����. ��� = ";
		index += 9;
		std::cout << index << std::endl;
		break;
	}

	int *BitContr_arr = new int[index];
	init_arr(BitContr_arr, index);
	cout_arr(BitContr_arr, index);

	int *bit_and_contr_bit = new int[index];
	bit_and_contr_bit = create_bit_array(word, size_bit_h, size_bit_a, index, BitContr_arr, plus_size);

	bool chetnost = X_counter(bit_and_contr_bit, plus_size,index);




	system("pause");
	return 0;
}
