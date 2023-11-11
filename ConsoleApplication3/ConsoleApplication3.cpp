#include <iostream>
#include "DList.h"
#include "Trolleybus.h"

using namespace std;

void TestDList();
void Test();

int main()
{
    setlocale(LC_ALL, "Russian");
    // Тестирование работы двусвязного списка
    //TestDList();
    // Тестирование функций парка троллейбусов
    Test();

}

void TestDList()
{
    cout << "Тестирование конструктора без параметров и добавления элементов различными способами, а также вывода с хвоста и головы" << endl;
    ListNode <int>l;
    l.AddHead(1);
    l.AddHead(2);
    l.AddHead(3);
    l.AddHead(4);
    l.AddHead(5);
    l.AddTail(6);
    l.AddTail(7);
    l.AddTail(8);
    l.AddTail(9);
    l.AddTail(10);
    l.AddNode(100, 5);
    l.ListHead();
    l.ListTail();

    cout << "\nТестирование работы с указателем, обращения по индексу и присваивания" << endl;
    cout << l++ << endl;
    cout << l.CurrentNode() << endl;
    l--;
    cout << l.CurrentNode() << endl;
    cout << l[4] << endl;
    l[3] = 213;
    l.ListHead();

    cout << "\nТестирование работы конструктора копирования" << endl;
    ListNode <int>l2(l);
    l2.ListHead();

    cout << "\nТестирование работы конструктора с параметрами" << endl;
    int arr[5] = { 1, 2, 3, 4, 5 };
    ListNode<int> l3(arr, 5);
    l3.ListHead();

    cout << "\nТестирование удаления и очистки списка" << endl;
    l3.DeleteHead();
    l3.DeleteTail();
    l3.DeleteNodePos(2);
    l3.ListHead();
    l3.Clear();
    cout << "Кол-во элементов в списке l3: " << l3.GetCount() << endl;
}


void Test()
{
    Park park;
    while (1)
    {
        char ch = input<char>(
            "Что вы хотите сделать?\n"
            "\t1 Добавить троллейбус в парк\n"
            "\t2 Добавить троллейбус на маршрут\n"
            "\t3 Снять троллейбус с маршрута в парк\n"
            "\t4 Отправить троллейбус из парка на маршрут\n"
            "\t5 Информация о троллейбусах в парке\n"
            "\t6 Информация о троллейбусах на маршруте\n"
            "\tE Выход\n"
        );
        Trolleybus t;
        int pos;
        switch (ch)
        {
        case '1':
            cout << "Укажите номер троллейбуса, фамилию водителя и номер маршрута:" << endl;
            cin >> t;
            park.AddToPark(t);
            break;
        case '2':
            cout << "Укажите номер троллейбуса, фамилию водителя и номер маршрута:" << endl;
            cin >> t;
            park.AddToTrack(t);
            break;
        case '3':
            pos = input<int>("Укажите позицию автобуса, который хотите снять с маршрута: ");
            park.GoToPark(pos);
            break;
        case '4':
            pos = input<int>("Укажите позицию автобуса, который хотите отправить на маршрут: ");
            park.GoToTrack(pos);
            break;
        case '5':
            cout << "Информация о троллейбусах в парке:" << endl;
            park.ParkInfo();
            break;
        case '6':
            cout << "Информация о троллейбусах на маршруте:" << endl;
            park.TrackInfo();
            break;
        case 'E':
            return;
            break;
        default:
            cout << "Команда не распознана" << endl;
        }
    }
}