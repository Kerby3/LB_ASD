#include <iostream>
using namespace std;

void Merge(int *arr, int first, int last) {
	int *tmpArr = new int[10]; //временный массив
	int middle = (first + last) / 2; //находим середину массива
	int start = first; //начало левой части подмассива
	int end = middle + 1; //начало правой части подмассива
	int i; //итератор
	for (i = first; i <= last; i++) { 
		if ((start <= middle) && (end > last) || (arr[start] < arr[end])) { //если левая часть меньше равна правой и индекс последнего элемента больше начала правой части или значение левой части меньше, чем правой
			tmpArr[i] = arr[start]; //то записать в левую часть
			start++; // итерируем левую часть
		} else {
			tmpArr[i] = arr[end]; //иначе записываем в правую часть
			end++; //итерируем правую часть
		}
	}
	for (i = first; i <= last; i++) {
		arr[i] = tmpArr[i]; //добавляем в выходной массив значение
	}
	delete[]tmpArr; //очищаем временный массив
}

void MergeSort(int arr[], int first, int last) { //функция деления на подмассивы
	if (first < last) {
		MergeSort(arr, first, (first + last) / 2); // сортировка левой части
		MergeSort(arr, (first + last) / 2 + 1, last); // сортировка правой части
		Merge(arr, first, last); //склейка подмассивов
	}
}

void main() {
	setlocale(LC_ALL, "Russian"); //устанавливаем русский язык
	int arr[10] = {4, 12, 578, -34, 54, -20, 41, -22, 41, 5}; //массив на вход
	cout << "Массив до сортировки" << endl; // сообщение
	for (int i = 0; i < size(arr); i++) { // вывод массива до сортировки
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Массив после сортировки" << endl; //сообщение
	MergeSort(arr, 0, size(arr) - 1); //вызов функции сортировки
	for (int i = 0; i < size(arr); i++) { //вывод массива после сортировки
		cout << arr[i] << " ";
	}
}