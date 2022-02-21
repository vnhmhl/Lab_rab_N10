

#include <iostream>
using namespace std;

int n; //размер массива
int* make_mas()
{
	int* mas = new int[n];
	for (int i = 0;i < n;i++)
		mas[i] = rand() % 100;
	return mas;
}

int* delete_mas(int* arr, int k, int ind)
{
	//Удаление k элементов с индекса ind
	bool flag = true;
	if ((k + ind) > n) flag = false;

	int* mas_return = new int[n - k];  //новый массив
	int i = 0; //счетчик для итогового массива
	int ii;//счетчик для начального массива
	int count = 0;

	for (ii = 0; ii < n; ii++)
	{
		if (ii == ind)
		{
			while (k > 1)
			{
				ii++;
				k--;
				count++;
			};
		}
		else
		{
			mas_return[i] = arr[ii];
			i++;
		}
	}
	if (flag) n = n - (count + 1);
	else n = n - count;		
	return mas_return;
}

int* insert_mas(int* arr, int el, int key)
{
	//Добваление элемента по ключу
	int* mas_return = new int[n + 1];
	for (int i = 0; i < n+1; i++)
	{
		if (i == key)
		{
			mas_return[i] = el;
		}
		else
		{
			if (i > key) mas_return[i] = arr[i - 1];
			else mas_return[i] = arr[i];
		}
	}
	n = n + 1;
	return mas_return;
}

void print_mas(int* mas)
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "");

	//Введём кол-во элементов в массиве
	cout << "Введите кол-во элементов в массиве: n = ";
	cin >> n;
	int* arr = make_mas(); //создание массива
	print_mas(arr);

	//---------------------------------------------------------УДАЛЕНИЕ
	//Введём кол-во элементов для удаления
	int k;
	cout << "Введите кол-во элементов для удаления (сколько элементов удалить?) k = ";
	cin >> k;

	//Введём индекс, с которого хотим удалить элементы
	int index_del;
	cout << "Введите индекс, с которого хотите удалить " << k << " элементов. index = ";
	cin >> index_del;

	arr = delete_mas(arr, k, index_del);	//удаление элементов
	print_mas(arr);

	//--------------------------------------------------------ВСТАВКА
	//Введём значение элемента для вставки
	int a;
	cout << "Введите значение элемента, которое хотите вставить. а = ";
	cin >> a;

	//Введём индекс места, на которое хотим поставить элемент
	int index_insert;
	cout << "Введите индекс места, на которое хотите поставить новый элемент. index = ";
	cin >> index_insert;

	arr = insert_mas(arr, a, index_insert);	//вставка элемента
	print_mas(arr);

	//Вызов спец оператора delete (удаление массива)
	delete[] arr;

}
